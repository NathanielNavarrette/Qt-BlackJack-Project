#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QDialogButtonBox>
#include <QRadioButton>
#include <QMessageBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QWidget>
#include <QLayout>
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <vector>
#include <QTime>


class GameOptions
{
public:
    GameOptions();

    //game options getters:
    int get_difficulty_int();
    int get_num_players();
    int get_start_money();
    int get_min_bet();
    QString get_string(int pos);
    QList<QString> get_difficulty_string();

    //game option mutators:
    void set_difficulty(int diff_num);
    void set_num_players(int player_num);
    void set_start_money(int money_start);
    void set_min_bet(int bet_min);

private:
    void options_dialog();

    int m_difficulty_value = 1;
    int m_num_of_players = 3;
    int m_starting_money = 500;
    int m_min_bet = 20;
    QString m_default_string = QString::fromStdString(dif_string[m_difficulty_value]);
    std::string dif_string[5]{"Novice", "Casual", "Hit Me", "Professional", "Cheaters"};
};

#endif // GAMEOPTIONS_H
