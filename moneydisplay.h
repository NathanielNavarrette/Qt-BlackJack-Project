#ifndef MONEYDISPLAY_H
#define MONEYDISPLAY_H

#include <QLCDNumber>
#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QTime>

class MoneyDisplay : public QWidget
{
public:
    explicit MoneyDisplay(QWidget *parent);
    MoneyDisplay(int display_money, QString owner, QWidget *parent);

private:
    int m_current_money;
    QString m_owner;
    QWidget* displayWindow = new QWidget(this);
    QHBoxLayout* m_layout = new QHBoxLayout(displayWindow);

signals:

private slots:
    void showMoney();

public slots:
    void display_money();
    void changeMoney(int money_changed);
    void resetMoney(bool check);
};

#endif // MONEYDISPLAY_H
