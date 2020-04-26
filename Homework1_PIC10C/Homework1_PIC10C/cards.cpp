//
//  cards.cpp
//  Homework1_PIC10C
//
//  Created by Seng chow Choy on 4/12/20.
//  Copyright © 2020 Seng chow Choy. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "cards.h"

/* *************************************************
 Card class
 ************************************************* */

/*
 Default constructor for the Card class.
 It could give repeated cards. This is OK.
 Most variations of Blackjack are played with
 several decks of cards at the same time.
 */
Card::Card(){
    int r = 1 + rand() % 4;
    switch (r) {
        case 1: suit = OROS; break;
        case 2: suit = COPAS; break;
        case 3: suit = ESPADAS; break;
        case 4: suit = BASTOS; break;
        default: break;
    }
    
    r = 1 + rand() % 10;
    switch (r) {
        case  1: rank = AS; break;
        case  2: rank = DOS; break;
        case  3: rank = TRES; break;
        case  4: rank = CUATRO; break;
        case  5: rank = CINCO; break;
        case  6: rank = SEIS; break;
        case  7: rank = SIETE; break;
        case  8: rank = SOTA; break;
        case  9: rank = CABALLO; break;
        case 10: rank = REY; break;
        default: break;
    }
}

// Accessor: returns a string with the suit of the card in Spanish
string Card::get_spanish_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "oros";
            break;
        case COPAS:
            suitName = "copas";
            break;
        case ESPADAS:
            suitName = "espadas";
            break;
        case BASTOS:
            suitName = "bastos";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish
string Card::get_spanish_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "As";
            break;
        case DOS:
            rankName = "Dos";
            break;
        case TRES:
            rankName = "Tres";
            break;
        case CUATRO:
            rankName = "Cuatro";
            break;
        case CINCO:
            rankName = "Cinco";
            break;
        case SEIS:
            rankName = "Seis";
            break;
        case SIETE:
            rankName = "Siete";
            break;
        case SOTA:
            rankName = "Sota";
            break;
        case CABALLO:
            rankName = "Caballo";
            break;
        case REY:
            rankName = "Rey";
            break;
        default: break;
    }
    return rankName;
}



// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
    string suitName;
    switch (suit) {
        case OROS:
            suitName = "coins";
            break;
        case COPAS:
            suitName = "cups";
            break;
        case ESPADAS:
            suitName = "spades";
            break;
        case BASTOS:
            suitName = "clubs";
            break;
        default: break;
    }
    return suitName;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
    string rankName;
    switch (rank) {
        case AS:
            rankName = "Ace";
            break;
        case DOS:
            rankName = "Two";
            break;
        case TRES:
            rankName = "Three";
            break;
        case CUATRO:
            rankName = "Four";
            break;
        case CINCO:
            rankName = "Five";
            break;
        case SEIS:
            rankName = "Six";
            break;
        case SIETE:
            rankName = "Seven";
            break;
        case SOTA:
            rankName = "Jack";
            break;
        case CABALLO:
            rankName = "Knight";
            break;
        case REY:
            rankName = "King";
            break;
        default: break;
    }
    return rankName;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
    return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
    return rank < card2.rank;
}



/* *************************************************
 Hand class
 ************************************************* */

Hand::Hand() {};

void Hand::add_card( Card& current) {
    //Adds card to the data member hand_cards
    hand_cards.push_back(current);
}

void Hand::print_card() {
    //for each cards in hand
    for (int i = 0; i < hand_cards.size(); ++i) {
        //Create a string that is the name of the card based on its suit and rank
        string spanish_card_name = hand_cards[i].get_spanish_rank() + " de " + hand_cards[i].get_spanish_suit();
        //Prints the name of the card to the console
        cout << setw(17) << spanish_card_name;
        //Create a string that is the name of the card based on its suit and rank translated to english
        string english_card_name = "(" + hand_cards[i].get_english_rank() + " of " + hand_cards[i].get_english_suit() + ")";
        //Prints the english name of the card to the console
        cout << setw(20) <<  english_card_name <<'\n';
    }
}

void Hand::fprint_card(ofstream& fout) {
    //for each cards in hand
    for (int i = 0; i < hand_cards.size(); ++i) {
        //Create a string that is the name of the card based on its suit and rank
        string spanish_card_name = hand_cards[i].get_spanish_rank() + " de " + hand_cards[i].get_spanish_suit();
        //Prints the name of the card to the file
        fout << string(8, ' ') << left << setw(22) << spanish_card_name;
        //Create a string that is the name of the card based on its suit and rank translated to english
        string english_card_name = "(" + hand_cards[i].get_english_rank() + " of " + hand_cards[i].get_english_suit() + ")";
        //Prints the english name of the card to the file
        fout << setw(20) <<  english_card_name <<'\n';
    }
}

double Hand::total_value() const{
    //Declare and initialize total value of cards in hand
    double total = 0;
    //for each card in hand
    for (int i = 0; i < hand_cards.size(); ++i) {
        //if the card has a rank greater than 10
        if (hand_cards[i].get_rank() >= 10) {
            //Its value is 0.5 so we add 0.5
            total += 0.5;
        }
        //otherwise
        else {
            //the rank will be equal to value of card so we add the value of the rank
            total += hand_cards[i].get_rank();
        }
    }
    //return sum of all values of cards in hand
    return total;
}

/* *************************************************
 Player class
 ************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m): money(m) {}

int Player::get_money() const {
    //returns the money the player has at the moment
    return money;
}

void Player::update_money(int bet, bool won) {
    //if the dealer/player has won
    if (won) {
        //increase the dealer/player's money by the amount the player bet
        money += bet;
    }
    //otherwise
    else {
        //decrease the dealer/plauer's money by the amount the player bet
       money -= bet;
    }
    
    return;
}
    

