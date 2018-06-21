#include "player.h"

Player::Player()
{
    debug_deck();

}

void Player::debug_deck()
{
    for(int i=0;i<m_deck->get_size();i++)
        qDebug() << "Card Value: " << (m_deck->get_value_at(i)) << "|| Card Name: " << (m_deck->get_name_at(i));

    /*
    int size_tmp = m_deck.get_size();
    for(int i=0;i<size_tmp;i++)
        qDebug() << i+1 << "Card: " << m_deck.getCard().get_card_name();
    */

    /*
    qDebug() << "Checking if image is success: ";
    int size_tmp = m_deck.get_size();
    for(int i=0;i<size_tmp;i++)
    {
        Card tmp_card = m_deck.getCard();
        if(tmp_card.get_image() == NULL)
            qDebug() << tmp_card.get_card_name() << " Failed";
        else
            qDebug() << tmp_card.get_card_name() << " Success";
    }
    */
}

bool Player::check_if_empty()
{
    return m_deck->my_empty();
}

QPixmap* Player::get_card_img()
{

    return tmp_card.get_image();
}

Card Player::get_card()
{

}

void Player::pull_card()
{
    m_tmp_card = m_deck->getCard();
}
