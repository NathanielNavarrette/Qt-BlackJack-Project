#ifndef CARD_H
#define CARD_H

#include <algorithm>
#include <iostream>
#include <QPixmap>
#include <QString>
#include <string>



class Card
{
public:
    Card();
    Card(std::string cardName, std::string cardFamily);
    int get_value();
    QString get_card_name();
    QPixmap* get_image();
    void set_blank();
    void flip_blank();

private:
    int create_values(std::string &cardName, std::string &cardFamily);
    std::string cardNames[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int m_value;
    QString m_img_loc;
    QString m_card_name;
    QPixmap* m_card_img;
    QPixmap* m_prev_img;

};

#endif // CARD_H
