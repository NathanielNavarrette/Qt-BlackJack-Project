#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialogButtonBox>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QWidget>
#include <QLayout>
#include <QDialog>
#include <QDebug>
#include <QLabel>
#include <vector>
#include <QTime>

#include"gameoptions.h"

class OptionsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit OptionsWindow(QWidget *parent = nullptr);

private:
    void addOptionsDialog();

    int m_difficulty_value;
    int m_num_of_players = 3;
    int m_starting_money = 500;
    int m_min_bet = 20;
    std::string dif_string[5]{"Novice", "Casual", "Hit Me", "Professional", "Cheaters"};

signals:
    void finished(GameOptions changed_options);

public slots:
    void changingOptions(bool clicked);
};

#endif // OPTIONSWINDOW_H
