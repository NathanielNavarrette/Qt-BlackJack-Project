#ifndef CARD_H
#define CARD_H
#include<iostream>
#include<string>
#include<QString>

class Card
{
public:
    Card();
    Card(std::string cardName, std::string cardFamily);
    int get_value();
    QString get_card_name();

private:
    int create_values(std::string &cardName);
    std::string cardNames[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int m_value;
    QString m_card_name;

};

#endif // CARD_H
