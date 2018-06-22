#include "moneydisplay.h"

MoneyDisplay::MoneyDisplay(QWidget* parent) : QWidget(parent)
{
    setMinimumHeight(75);
}

MoneyDisplay::MoneyDisplay(int display_money, QString owner, QWidget *parent)
{
    setMinimumHeight(75);
    m_current_money = display_money;
    m_owner = owner;
}

void MoneyDisplay::display_money()
{
    QWidget* display_money = new QLabel(m_owner + " : " + QString::number(m_current_money));
    m_layout->addWidget(display_money);
}

void MoneyDisplay::changeMoney(int money_changed)
{

}


void MoneyDisplay::resetMoney(bool check)
{

}
