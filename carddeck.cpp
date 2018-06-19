#include "carddeck.h"

CardDeck::CardDeck()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<13;j++)
            m_deck.push_back(Card(cardNames[j], suitNames[i]));

    shuffleDeck();
}

int CardDeck::get_size()
{
    return m_deck.size();
}

int CardDeck::get_value_at(int pos)
{
    return m_deck.at(pos).get_value();
}

void CardDeck::shuffleDeck()
{
    std::srand (unsigned (std::time(0))); //seed rand from current time(ms)
    std::random_shuffle ( m_deck.begin(), m_deck.end() ); //random shuffle, starting from begging to end of vector
}
