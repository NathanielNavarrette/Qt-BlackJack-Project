#include "player.h"

Player::Player()
{
    debug_deck();
}

void Player::debug_deck()
{
    for(int i=0;i<m_deck.get_size();i++)
        qDebug() << (m_deck.get_value_at(i));
}
