/*
 *
 * When called, should create a deck that is stored in itself.
 * Should pass random cards to the player to create their "hand".
 * Pass a "card" type back to the hand
 * Either shuffle after every turn or after the deck has been gone through.
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <QDebug>
#include <ctime>

#include "Card.h"

class CardDeck
{
public:
    CardDeck();
    Card* getCard();
    int get_size();
    int get_value_at(int pos);
    QString get_name_at(int pos);
    bool my_empty();
    Card getBlank();


private:
    void shuffleDeck();
    std::vector<Card*> m_deck;

    std::string cardNames[13]={"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    std::string suitNames[4]={"Spades", "Diamonds", "Clubs", "Hearts"};

};

#endif // CARDDECK_H
