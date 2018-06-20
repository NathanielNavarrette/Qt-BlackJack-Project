#include "player.h"

Player::Player()
{
    debug_deck();

}

void Player::debug_deck()
{
    for(int i=0;i<m_deck.get_size();i++)
        qDebug() << "Card Value: " << (m_deck.get_value_at(i)) << "|| Card Name: " << (m_deck.get_name_at(i));

    /*
    int size_tmp = m_deck.get_size();
    for(int i=0;i<size_tmp;i++)
        qDebug() << i+1 << "Card: " << m_deck.getCard().get_card_name();
    */
}

