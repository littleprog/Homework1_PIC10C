//
//  cards.h
//  Homework1_PIC10C
//
//  Created by Seng chow Choy on 4/12/20.
//  Copyright © 2020 Seng chow Choy. All rights reserved.


#include <string>
#include <vector>
#include <fstream>


#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};

/*
 The values for this type start at 0 and increase by one
 afterwards until they get to SIETE.
 The rank reported by the function Card::get_rank() below is
 the value listed here plus one.
 E.g:
 The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
 The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
 */
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA=9, CABALLO=10, REY=11};

class Hand;

class Card {
public:
    /**
     Class constructor: a spanish card that has a suit and rank
     */
    Card();
    
    /**
     Gives the suit of the spanish card
     
     @return suit of spanish card as string
     */
    string get_spanish_suit() const;
    
    /**
     Gives the rank of the spanish card
     
    @return rank of spanish card as string
     */
    string get_spanish_rank() const;
    
    /**
     Gives the suit of the spanish card translated to the english card version
     
     @return the suit of the spanish card translated to the english card version as string
     */
    string get_english_suit() const;
    
    /**
     Gives the rank of the spanish card translated to the english card version
     
     @return the rank of the spanish card translated to the english card version as string
     */
    string get_english_rank() const;
    
    // Converts card rank to number.
    // The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
    int get_rank() const;
    
    // Compare rank of two cards. E.g: Eight<Jack is true.
    // Assume Ace is always 1.
    // Useful if you want to sort the cards.
    bool operator < (Card card2) const;
    
    
private:
    suit_t suit;
    rank_t rank;
};


class Hand {
public:
    /**
     Class constructor: an object that stores all the cards in the player or dealer's hand
     */
    Hand();
    
    /**
     Add a card to the player or dealer's hand
     
     @param current_card the card to be added to hand
     */
    void add_card( Card& current_card );
    
    
    /**
     Prints cards in player or dealer's hand on the console
     */
    void print_card();
    
    /**
     Prints cards in player or dealer's hand in file
     
     @param fout the stream that is used to print cards to file
     */
    void fprint_card(ofstream& fout);
    
    /**
     
     */
    int rankname_to_rankvalue(Card& current) const;
    
    /**
    Gives the total value of cards on the player or dealer's hand
     */
    double total_value() const;
    
    
private:
    vector<Card> hand_cards;
};


class Player {
public:
    /**
    Class constructor: creates a player of the game
    @param m the money that the player will start the game with
     */
    Player(int m);
    
    /**
     Gives the money that the player or dealer has at the moment
     
     @return the money that the player or dealer has at the moment
     */
    int get_money() const; 
    
    /**
     Increases or decreases the money the player has depending on the amount he/she has bet and whether he/she has won
     
     @param bet the amount of money player wants to bet
     @param won true if player has won, false if player lost
     */
    void update_money(int bet, bool won);
    
private:
    int money;
};



#endif /* cards_h */
