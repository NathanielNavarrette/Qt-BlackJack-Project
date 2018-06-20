#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QSettings>
#include <QLayout>
#include <QObject>
#include <vector>
#include <QIcon>

#include"player.h"
#include"cardview.h"

namespace Ui {
    class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

    QSystemTrayIcon* m_icon = new QSystemTrayIcon(this);

    Player player1;

    std::vector<QWidget*> outputtedCards;

    QVBoxLayout *m_layout = new QVBoxLayout(this);

    QWidget *topButtons = new QWidget(this);
    QWidget *moneyDisplays = new QWidget(this);
    QWidget *cardDisplays = new CardView(this);
    QWidget *gameOptions = new QWidget(this);

    QHBoxLayout *topButtonLayout = new QHBoxLayout(topButtons);
    QWidget *startButton = new QPushButton("Start Game", topButtons);
    QWidget *resetButton = new QPushButton("Reset Game", topButtons);
    QWidget *saveButton = new QPushButton("Save Game", topButtons);
    QWidget *menuButton = new QPushButton("Go To Menu", topButtons);

    QHBoxLayout *moneyDisplayLayout = new QHBoxLayout(moneyDisplays);
    std::vector<QWidget*> playerMonies; //will get created in the cpp file

    QHBoxLayout *cardDisplayLayout = new QHBoxLayout(cardDisplays);

    QHBoxLayout *gameOptionsLayout = new QHBoxLayout(gameOptions);
    QWidget *hitButton = new QPushButton("Hit", gameOptions);
    QWidget *stayButton = new QPushButton("Stay", gameOptions);
    QWidget *splitButton = new QPushButton("Split", gameOptions);
    QWidget *betButton = new QPushButton("Bet", gameOptions);

public slots:

private slots:
    void game_start();
    void returnToMenu();

signals:
    void menuReturn();

};

#endif // GAMEWINDOW_H
