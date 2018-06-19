#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QSettings>
#include <QLayout>
#include <QObject>
#include <vector>

#include "player.h"
#include "cardview.h"
#include "gamewindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    GameWindow *m_game;


private:
    Ui::MainWindow *ui;
    QWidget* displayArea = new QWidget(this);
    QVBoxLayout* m_layout = new QVBoxLayout(this);
    QHBoxLayout* m_layout = new QHBoxLayout(this);
    QWidget* buttonArea = new QWidget(displayArea);

    QWidget* playButton = new QPushButton("Play Game", displayArea);
    QWidget* closeButton = new QPushButton("Close", displayArea);

    /*
    Player player1;

    std::vector<QWidget*> outputtedCards;

    QVBoxLayout *m_layout = new QVBoxLayout(this);

    QWidget *topButtons = new QWidget(this);
    QWidget *moneyDisplays = new QWidget(this);
    QWidget *cardDisplays = new CardView(this);
    QWidget *gameOptions = new QWidget(this);

    QHBoxLayout *topButtonLayout = new QHBoxLayout(topButtons);
    QWidget *startButton = new QPushButton("Start Game", topButtons);
    QWidget *optionsButton = new QPushButton("Game Options", topButtons);
    QWidget *saveButton = new QPushButton("Save Game", topButtons);
    QWidget *loadButton = new QPushButton("Load Game", topButtons);

    QHBoxLayout *moneyDisplayLayout = new QHBoxLayout(moneyDisplays);
    std::vector<QWidget*> playerMonies; //will get created in the cpp file

    QHBoxLayout *cardDisplayLayout = new QHBoxLayout(cardDisplays);

    QHBoxLayout *gameOptionsLayout = new QHBoxLayout(gameOptions);
    QWidget *hitButton = new QPushButton("Hit", gameOptions);
    QWidget *stayButton = new QPushButton("Stay", gameOptions);
    QWidget *splitButton = new QPushButton("Split", gameOptions);
    QWidget *betButton = new QPushButton("Bet", gameOptions);

    */
public slots:

private slots:
    void play_clicked();
    void close_clicked();


signals:

};

#endif // MAINWINDOW_H
