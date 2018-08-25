#include "carddeck.h"

CardDeck::CardDeck()
{
    qDebug() << "CardDeck Constructed";
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            m_deck.push_back(new Card(cardNames[j], suitNames[i]));

    //shuffleDeck();
}

Card* CardDeck::getCard()
{
    if(!my_empty())
    {
        Card* tmp_card = m_deck.at(0);
        m_deck.erase(m_deck.begin());
        return tmp_card;
    }else{
        for(int i=0;i<4;i++)
            for(int j=0;j<13;j++)
                m_deck.push_back(new Card(cardNames[j], suitNames[i]));
        shuffleDeck();

        Card* tmp_card = m_deck.at(0);
        m_deck.erase(m_deck.begin());
        return tmp_card;
    }
}

Card CardDeck::getBlank()
{
    //return
}

int CardDeck::get_size()
{
    return m_deck.size();
}

int CardDeck::get_value_at(int pos)
{
    return m_deck.at(pos)->get_value();
}

QString CardDeck::get_name_at(int pos)
{
    return m_deck.at(pos)->get_card_name();
}

void CardDeck::shuffleDeck()
{
    std::srand (unsigned (std::time(0))); //seed rand from current time(ms)
    std::random_shuffle ( m_deck.begin(), m_deck.end() ); //random shuffle, starting from begging to end of vector
}

bool CardDeck::my_empty()
{
    return m_deck.empty();
}
