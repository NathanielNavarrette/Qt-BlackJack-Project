#include "player.h"

Player::Player()
{
    //debug_deck();
    m_name = "Player1";

}

void Player::debug_deck()
{
    for(int i=0;i<m_deck->get_size();i++)
        qDebug() << "Card Value: " << (m_deck->get_value_at(i)) << "|| Card Name: " << (m_deck->get_name_at(i));
}

bool Player::check_if_empty()
{
    return m_deck->my_empty();
}

void Player::hit_card()
{
    pull_card();
}

QPixmap* Player::get_card_img()
{
    return m_tmp_card.get_image();
}

Card Player::get_card()
{
    return m_tmp_card;
}

void Player::pull_card()
{
    m_tmp_card = m_deck->getCard();
    m_hand_total += m_tmp_card.get_value();
    check_total();
}

bool Player::check_total()
{
    //if hand is under 21, return true, ELSE return false
    if(m_hand_total < 21)
        return true;
    else
        return false;
}

void Player::end_turn()
{
    m_hand_total = 0;
}
