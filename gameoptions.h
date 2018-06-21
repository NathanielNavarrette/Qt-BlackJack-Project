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

private:
    void options_dialog();

    int m_difficulty_value = 1;
    int m_num_of_players = 3;
    int m_starting_money = 500;
    int m_min_bet = 20;
    std::string dif_string[5]{"Novice", "Casual", "Hit Me", "Professional", "Cheaters"};
};

#endif // GAMEOPTIONS_H
