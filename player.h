#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <QDebug>

#include "card.h"
#include "carddeck.h"

class Player
{
public:
    Player();
    int get_current_money();

private:
    CardDeck m_deck;
    std::vector<Card> m_hand;
    void debug_deck();
    int m_money = 500;
};

#endif // PLAYER_H
