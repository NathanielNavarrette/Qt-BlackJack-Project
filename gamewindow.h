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

#include "player.h"
#include "cardview.h"
#include "computerai.h"
#include "gameoptions.h"
#include "moneydisplay.h"
#include "optionswindow.h"

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

    OptionsWindow* m_options_window = new OptionsWindow(this);
    GameOptions* m_options = new GameOptions;

    QSize m_prev_size;
    Player player1;

    QPixmap m_background_img;
    QPalette m_palette;

    std::vector<QWidget*> outputtedCards;

    QVBoxLayout *m_layout = new QVBoxLayout(this);

    QWidget *topButtons = new QWidget(this);
    QWidget *moneyDisplayArea = new MoneyDisplay(this);
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

    void display_all_cards();

public slots:
    void close_game();
    void recieved_options(GameOptions *send_options);

private slots:
    //slot to check if window size change to rescale background picture
    void check_size_change();

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
