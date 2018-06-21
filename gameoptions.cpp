#include "gameoptions.h"

GameOptions::GameOptions()
{
    //constructor for game options
}

int GameOptions::get_difficulty_int()
{
    return m_difficulty_value;
}

int GameOptions::get_num_players()
{
    return m_num_of_players;
}

int GameOptions::get_start_money()
{
    return m_starting_money;
}

int GameOptions::get_min_bet()
{
    return m_min_bet;
}

QString GameOptions::get_string(int pos)
{
    return QString::fromStdString(dif_string[pos]);
}

QList<QString> GameOptions::get_difficulty_string()
{
    QList<QString> difficulty_list;

    for(int i=0;i<5;i++)
        difficulty_list.push_back(QString::fromStdString(dif_string[i]));
    return difficulty_list;
}

void GameOptions::set_difficulty(int diff_num)
{
    m_difficulty_value = diff_num;
    m_default_string = QString::fromStdString(dif_string[diff_num]);
}

void GameOptions::set_num_players(int player_num)
{
    m_num_of_players = player_num;
}

void GameOptions::set_start_money(int money_start)
{
    m_starting_money = money_start;
}

void GameOptions::set_min_bet(int bet_min)
{
    m_min_bet = bet_min;
}
