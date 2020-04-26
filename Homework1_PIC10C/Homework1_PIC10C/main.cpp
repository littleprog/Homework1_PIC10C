//
//  main.cpp
//  Homework1_PIC10C
//
//  Created by Seng chow Choy on 4/12/20.
//  Copyright © 2020 Seng chow Choy. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"

using namespace std;

int main(){
    //Starting with game number 1
    int game_number = 1;
    //Create player with $100 to bet initially
    Player me(100);
    //Create dealer with $0 to bet
    Player dealer(0);
    //Declare and initialize the amount player wants to bet to be zero
    int bet = 0;
    
    //while player has amount greater than $0 and the dealer has not lost $900
    while (me.get_money() > 0 && dealer.get_money() > -900) {
        //Create hand object that stores all cards in player's hand
        Hand myHand;
        //Create hand object that stores all cards in dealer's hand
        Hand dealerHand;
        
        cout << string(50, '-') << "\n\n";
        //Declare the the game number and Asks the player to input an amount he/she wants to bet
        cout << "Game " << game_number << " How much do you want to bet?\n";
        //Reads the amount the player wants to bet
        cin >> bet;
        //while the player bet an amount greater than what he currently has
        while (bet > me.get_money() ) {
            //Tells player to bet amount equal to or less than what he has
            cout << "Please enter appropriate amount of bet.\n";
            //Reads the bet player inputs again
            cin >> bet;
        }
        
        //Creates a card object which will be the player's first card
        Card myCard;
        //Add the card to the player's hand
        myHand.add_card(myCard);
        
        //Tells the player on the console what he has drawn for his first card
        cout << "Your hand cards: \n";
        myHand.print_card();
        
        //Tells the player on the console the total value of his first card
        cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
        
        //As long as player has cards whose sum add up to less than 7.5
        while (myHand.total_value() < 7.5) {
            //Asks the player if he wants to draw more cards
            cout << "Do you want more cards? (y/n) ";
            char more_card;
            //Reads y or n from user
            cin >> more_card;
            //if player wants more cards
            if (more_card == 'y') {
                //Create another card object and add it to his hand
                Card newCard;
                myHand.add_card(newCard);
                
                //Tells the player all the cards he has in his hand
                cout << "Your hand cards: \n";
                myHand.print_card();
                
                //Tells the player the total value of all cards in his hand
                cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
            }
            //if players do not want anymore cards
            else if (more_card == 'n' ) {
                break;
                
            }
            //or if player inputs char other than y or n when asked for more cards
            else {
                //Reminds player he can only enter y or n and the cards in his/her hand and their total value
                cout << "Note: Please enter only y or n\n\n";
                cout << "Your hand cards are: \n";
                myHand.print_card();
                cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
            }
        }
        
        //Create a card object which will be the dealer's first card
        Card dealerCard;
        //Add the card to the dealer's hand
        dealerHand.add_card(dealerCard);
        
        //open a file game_log
        ofstream fout("game_log",  std::ios_base::app);
        
        //if total value of cards in dealer's hand is less than 5.5
        while (dealerHand.total_value() < 5.5) {
            //Create and add another card to his hand
            Card nextDealerCard;
            dealerHand.add_card(nextDealerCard);
        }
        
        //Tells player the cards in the dealer's hand
        cout << "Dealer Hand cards: \n";
        dealerHand.print_card();
        
        //Tells player the total value of the cards in the dealer's hand
        cout << "Total value of the dealer's cards is: " << dealerHand.total_value() << "\n\n";
        
        //Get the money that the player has before he has placed the bet
        int my_initial_money = me.get_money();
        
        //if player busts, he will always lose
        if ( myHand.total_value() > 7.5) {
            //updates the amount of money in the dealer and player has
            dealer.update_money(bet, true);
            me.update_money(bet, false);
        }
        
        // if player has total card value less than or equal to 7.5 there are three possible outcomes
        else if (myHand.total_value() <= 7.5) {
            //if dealer busts, player wins
            if (dealerHand.total_value() > 7.5) {
                //updates the amount of money in the dealer and player has
                dealer.update_money(bet, false);
                me.update_money(bet, true);
            }
            //if dealer has total value of cards less than the player's total value of cards, player wins
            else if (dealerHand.total_value() < myHand.total_value()) {
                //updates the amount of money in the dealer and player has
                dealer.update_money(bet, false);
                me.update_money(bet, true);
            }
            //if both tie for total value of cards
            else if (dealerHand.total_value() == myHand.total_value()) {
               // do nothing
            }
            //if dealer has total value of cards greater than the player's total value of cards, dealer wins
            else if (dealerHand.total_value() > myHand.total_value()) {
                //updates the amount of money in the dealer and player has
                dealer.update_money(bet, true);
                me.update_money(bet, false);
            }
            
        }
        
        //Tells the player the amount he has left
        cout << "Your remaining amount is " << me.get_money() << "\n\n";
        
        //Write a log of the game in the game_log file
        fout << string(50, '-') << "\n\n";
       
        fout << "Game number: " << game_number;
        fout << setw(20) << " Money left: " << my_initial_money << '\n';
        fout << "Bet: " << bet << "\n\n";
        
        fout << "Your cards: \n";
        myHand.fprint_card(fout);
        fout << "Your total: " << myHand.total_value() << "\n\n";
        
        fout << "Dealer Hand cards: \n";
        dealerHand.fprint_card(fout);
        fout << "Dealer's total is " << dealerHand.total_value() << "\n\n";
        
        if (me.get_money() == 0) {
            fout << string(50, '-');
        }
        //close the file
        fout.close();
        //Increment the game number for the next game
        ++game_number;
    }
    
    
    return 0;
}
