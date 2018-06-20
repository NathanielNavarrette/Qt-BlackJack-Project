#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    this->setMinimumHeight(450);
    this->setMinimumWidth(450);

    QPixmap bkgnd(":/images/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    topButtonLayout->addWidget(startButton);
    topButtonLayout->addWidget(resetButton);
    topButtonLayout->addWidget(saveButton);
    topButtonLayout->addWidget(menuButton);
    m_layout->addWidget(topButtons);

    m_layout->addWidget(moneyDisplays);

    m_layout->addWidget(cardDisplays);

    gameOptionsLayout->addWidget(hitButton);
    gameOptionsLayout->addWidget(stayButton);
    gameOptionsLayout->addWidget(splitButton);
    gameOptionsLayout->addWidget(betButton);
    m_layout->addWidget(gameOptions);
    gameOptions->hide();

    this->setMinimumHeight(600);
    this->setMinimumWidth(800);

    ui->centralwidget->setLayout(m_layout);

    m_icon->show();

    connect(this, SIGNAL(menuReturn()), parent, SLOT(menu_pressed()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(game_start()));
    connect(menuButton, SIGNAL(clicked()), this, SLOT(returnToMenu()));

}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::game_start()
{
    //show other options
    //display a bet window
    //
    gameOptions->show();
}

void GameWindow::returnToMenu()
{
    emit menuReturn();
}
