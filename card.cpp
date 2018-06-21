#include "card.h"
#include <QDebug>

Card::Card()
{
    //do nothing
}

Card::Card(std::string cardName, std::string cardFamily)
{
    QString* card_fam_tmp = new QString(QString::fromStdString(cardFamily));
    *card_fam_tmp = card_fam_tmp->toLower();
    QString* card_name_tmp = new QString(QString::fromStdString(cardName));
    *card_name_tmp = card_name_tmp->toLower();

    m_card_name = QString::fromStdString(cardName) + " of " + QString::fromStdString(cardFamily);
    m_img_loc = QString::fromStdString(":/images/images/cards/") + card_name_tmp + QString::fromStdString("_of_") + card_fam_tmp + QString::fromStdString(".png");
    m_value = create_values(cardName, cardFamily);
    m_card_img = new QPixmap(m_img_loc);
}

void Card::set_blank()
{
    m_prev_img = m_card_img;
    m_img_loc = QString::fromStdString(":/images/images/cards/blank_card.png");
    m_card_img = new QPixmap(m_img_loc);

}

void Card::flip_blank()
{
    m_card_img = m_prev_img;
}


int Card::create_values(std::string &cardName, std::string& cardFamily)
{
    if(cardName == cardNames[0])
    {
        return 0; //0 will be "wild", since aces can be either be 1 or 11
    }else if(cardName == cardNames[1]){
        return 2;
    }else if(cardName == cardNames[2]){
        return 3;
    }else if(cardName == cardNames[3]){
        return 4;
    }else if(cardName == cardNames[4]){
        return 5;
    }else if(cardName == cardNames[5]){
        return 6;
    }else if(cardName == cardNames[6]){
        return 7;
    }else if(cardName == cardNames[7]){
        return 8;
    }else if(cardName == cardNames[8]){
        return 9;
    }else if(cardName == cardNames[9]){
        return 10;
    }else if(cardName == cardNames[10]){
        return 10;
    }else if(cardName == cardNames[11]){
        return 10;
    }else if(cardName == cardNames[12]){
        return 10;
    }else{
        return -1; //if all else fails, return a -1 indicating something went wrong
    }
}

int Card::get_value()
{
    return m_value;
}

QString Card::get_card_name()
{
    return m_card_name;
}

QPixmap* Card::get_image()
{
    return m_card_img;
}
