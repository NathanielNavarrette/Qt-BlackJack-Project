#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollArea>
#include <QSettings>
#include <QLayout>
#include <QObject>
#include <vector>
#include <QDebug>
#include <QIcon>

#include <QCloseEvent>

#include "player.h"
#include "cardview.h"
#include "gamewindow.h"
#include "gameoptions.h"
#include "optionswindow.h"

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

    void closeEvent(QCloseEvent *event);

    QSystemTrayIcon* m_icon = new QSystemTrayIcon(this);

    GameOptions* pass_options;
    bool m_options_changed = false;

    OptionsWindow* m_options_window = new OptionsWindow(this);

    QWidget* displayArea = new QWidget(this);
    QWidget* secondRow = new QWidget(this);
    QWidget* thirdRow = new QWidget(this);
    QWidget* nothing = new QWidget(this);

    QVBoxLayout* m_layout = new QVBoxLayout(this);
    QHBoxLayout* displayAreaLayout = new QHBoxLayout(displayArea);
    QHBoxLayout* secondRowLayout = new QHBoxLayout(secondRow);
    QHBoxLayout* thirdRowLayout = new QHBoxLayout(thirdRow);

    QWidget* buttonArea = new QWidget(displayArea);

    QWidget* returnButton = new QPushButton("Return to Game", buttonArea);
    QWidget* playButton = new QPushButton("Play Game", buttonArea);
    QWidget* closeButton = new QPushButton("Close", buttonArea);

    QWidget* optionsButton = new QPushButton("Options", buttonArea);
    QWidget* loadButton = new QPushButton("Load Previous Game", buttonArea);

    QWidget* ruleButton = new QPushButton("Rules", buttonArea);
    QWidget* aboutButton = new QPushButton("About", buttonArea);

public slots:
    void menu_pressed();
    void recieved_options(GameOptions* my_options);

private slots:
    void play_clicked();
    void return_clicked();
    void close_clicked();
    void options_clicked();
    void load_clicked();
    void rules_clicked();
    void about_clicked();

signals:
    void send_options(GameOptions* send_options);
    void changing_options();
    void displayingRules();
    void displayingAbout();

};

#endif // MAINWINDOW_H
