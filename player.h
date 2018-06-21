#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <QDebug>

//for debugging
#include <QDialog>
#include <QLayout>
#include <QDialogButtonBox>
#include <QWidget>
#include <QPixmap>

#include "card.h"
#include "carddeck.h"

class Player
{
public:
    Player();
    int get_current_money();
    QPixmap* get_card_img();
    Card get_card();
    bool check_if_empty();


private:
    CardDeck* m_deck = new CardDeck;
    std::vector<Card> m_hand;
    Card m_tmp_card;
    void pull_card();
    void debug_deck();
    int m_money = 500;


};

#endif // PLAYER_H
