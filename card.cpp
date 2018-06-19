#include "card.h"
#include <QDebug>

Card::Card()
{
    //qDebug() << "Invalid creation of a card";
    //do nothing
}

Card::Card(std::string cardName, std::string cardFamily)
{
    //qDebug() << "Correct creation of card";
    m_card_name = QString::fromStdString(cardName) + " of " + QString::fromStdString(cardFamily);
    m_value = create_values(cardName);
}

int Card::create_values(std::string &cardName)
{
    if(cardName == cardNames[0])
        return 0; //0 will be "wild", since aces can be either be 1 or 11
    else if(cardName == cardNames[1])
        return 2;
    else if(cardName == cardNames[2])
        return 3;
    else if(cardName == cardNames[3])
        return 4;
    else if(cardName == cardNames[4])
        return 5;
    else if(cardName == cardNames[5])
        return 6;
    else if(cardName == cardNames[6])
        return 7;
    else if(cardName == cardNames[7])
        return 8;
    else if(cardName == cardNames[8])
        return 9;
    else if(cardName == cardNames[9])
        return 10;
    else if(cardName == cardNames[10])
        return 10;
    else if(cardName == cardNames[11])
        return 10;
    else if(cardName == cardNames[12])
        return 10;
    else
        return -1; //if all else fails, return a -1 indicating something went wrong
}

int Card::get_value()
{
    return m_value;
}

QString Card::get_card_name()
{
    return m_card_name;
}
