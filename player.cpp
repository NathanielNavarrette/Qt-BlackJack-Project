#include "player.h"

Player::Player()
{
    //debug_deck();
    m_name = "Player1";

}

Player::Player(int money_start)
{
    m_name = "Player1";
    m_money = money_start;
}

void Player::debug_deck()
{
    for(int i=0;i<m_deck.get_size();i++)
        qDebug() << "Card Value: "
                 << (m_deck.get_value_at(i))
                 << "|| Card Name: "
                 << (m_deck.get_name_at(i));
}

bool Player::check_if_empty()
{
    return m_deck.my_empty();
}

void Player::hit_card()
{
    pull_card();
}

std::vector<Card> Player::get_hand()
{
    return m_hand;
}

QPixmap* Player::get_card_img()
{
    return m_tmp_card->get_image();
}

Card* Player::get_card()
{
    return m_tmp_card;
}

void Player::pull_card()
{
    m_tmp_card = m_deck.getCard();
    m_hand.push_back(*m_tmp_card);
    m_hand_total += m_tmp_card->get_value();
    //if check_total returns false automatically end the turn
    //if it returns true, continue
    //check_total();
}

bool Player::check_total()
{
    //if hand is under 21, return true, ELSE return false
    if(m_hand_total < 21)
        return true;
    else
        return false;
}

int Player::get_hand_total()
{
    return m_hand_total;
}

void Player::end_turn()
{
    m_hand_total = 0;
}
