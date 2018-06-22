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
    Player(int money_start);
    int get_current_money();
    QPixmap* get_card_img();
    std::vector<Card> get_hand();
    void hit_card();
    Card* get_card();
    bool check_if_empty();
    bool check_total();
    int get_hand_total();
    void end_turn();

private:
    CardDeck m_deck;// = new CardDeck;
    std::vector<Card> m_hand;
    Card* m_tmp_card;
    QString m_name;
    void pull_card();
    void debug_deck();
    int m_money = 500;
    int m_hand_total = 0;

};

#endif // PLAYER_H
