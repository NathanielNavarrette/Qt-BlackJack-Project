#ifndef MONEYDISPLAY_H
#define MONEYDISPLAY_H

#include <QLCDNumber>
#include <QWidget>
#include <QTimer>
#include <QDebug>
#include <QTime>

class MoneyDisplay : public QLCDNumber
{
public:
    MoneyDisplay();


private:
    int m_current_money = 500;

signals:

private slots:
    void showMoney();

public slots:
    void changeMoney(int money_changed);
    void resetMoney(bool check);
};

#endif // MONEYDISPLAY_H
