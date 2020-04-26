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

// Global constants (if any)


// Non member functions declarations (if any)

// Non member functions implementations (if any)


// Stub for main
int main(){
    
    int game_number = 1;
    Player me(100);
    Player dealer(0);
    int bet = 0;
    
    while (me.get_money() > 0 && dealer.get_money() > -900) {
        Hand myHand;
        Hand dealerHand;
        
        
        cout << string(50, '-') << "\n\n";
        cout << "Game " << game_number << " How much do you want to bet?\n";
        cin >> bet;
        while (bet > me.get_money() ) {
            cout << "Please enter appropriate amount of bet.\n";
            cin >> bet;
        }
        
        Card myCard;
        myHand.add_card(myCard);
        
        cout << "Your hand cards: \n";
        myHand.print_card();
        
        cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
        
        
        while (myHand.total_value() < 7.5) {
    
            cout << "Do you want more cards? (y/n) ";
            char more_card;
            cin >> more_card;
            if (more_card == 'y') {
                Card newCard;
                myHand.add_card(newCard);
                
                cout << "Your hand cards: \n";
                myHand.print_card();
                
                cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
            }
            else if (more_card == 'n' ) {
                break;
                
            }
            else {
                cout << "Note: Please enter only y or n\n\n";
                cout << "Your hand cards are: \n";
                myHand.print_card();
                cout << "Total value of your cards is: " << myHand.total_value() << "\n\n";
            }
        }
        
        
        Card dealerCard;
        dealerHand.add_card(dealerCard);
        ofstream fout("game_log",  std::ios_base::app);
        while (dealerHand.total_value() < 5.5) {
            Card nextDealerCard;
            dealerHand.add_card(nextDealerCard);
        }
        
        cout << "Dealer Hand cards: \n";
        dealerHand.print_card();
        
        cout << "Total value of the dealer's cards is: " << dealerHand.total_value() << "\n\n";
        
        int my_initial_money = me.get_money();
        if ( myHand.total_value() > 7.5) {
            dealer.update_money(bet, true);
            me.update_money(bet, false);
        }
        
        else if (myHand.total_value() <= 7.5) {
            if (dealerHand.total_value() > 7.5) {
                dealer.update_money(bet, false);
                me.update_money(bet, true);
            }
            else if (dealerHand.total_value() < myHand.total_value()) {
                dealer.update_money(bet, false);
                me.update_money(bet, true);
            }
            else if (dealerHand.total_value() == myHand.total_value()) {
               
            }
            else if (dealerHand.total_value() > myHand.total_value()) {
                dealer.update_money(bet, true);
                me.update_money(bet, false);
            }
            
        }
        
        
        cout << "Your remaining amount is " << me.get_money() << "\n\n";
        
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
        
        ++game_number;
    }
    
    
    return 0;
}
