#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QSettings>
#include <QObject>
#include <QLayout>
#include <QEvent>
#include <QLabel>
#include <QTimer>
#include <vector>
#include <QIcon>
#include <map>

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
    QWidget *moneyDisplayArea = new QWidget(this);
    QWidget *cardDisplayArea = new CardView(this);
    QWidget *gameOptions = new QWidget(this);

    QHBoxLayout *topButtonLayout = new QHBoxLayout(topButtons);
    QWidget *startButton = new QPushButton("Start Game", topButtons);
    QWidget *resetButton = new QPushButton("Reset Game", topButtons);
    QWidget *saveButton = new QPushButton("Save Game", topButtons);
    QWidget *menuButton = new QPushButton("Go To Menu", topButtons);

    QHBoxLayout *moneyDisplayLayout = new QHBoxLayout(moneyDisplayArea);
    std::vector<QWidget*> playerMonies; //will get created in the cpp file

    QVBoxLayout *cardDisplayLayout = new QVBoxLayout(cardDisplayArea);

    QHBoxLayout *gameOptionsLayout = new QHBoxLayout(gameOptions);
    QWidget *hitButton = new QPushButton("Hit", gameOptions);
    QWidget *stayButton = new QPushButton("Stay", gameOptions);
    QWidget *splitButton = new QPushButton("Split", gameOptions);
    QWidget *betButton = new QPushButton("Bet", gameOptions);

public slots:
    void close_game();

private slots:
    //slot to act as a timmer
     void check_active();

    //slots for menu buttons
    void reset_pressed();
    void save_pressed();
    void game_start();
    void returnToMenu();

    //slots for game buttons
    void hit_pressed();
    void stay_pressed();
    void split_pressed();
    void bet_pressed();


signals:
    void menuReturn();

};

#endif // GAMEWINDOW_H
