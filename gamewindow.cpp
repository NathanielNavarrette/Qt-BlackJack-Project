#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap test(QPixmap(":/images/images/bg.jpg"));
    test = test.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette tpalette;
    tpalette.setBrush(QPalette::Background, test);
    cardDisplays->setPalette(tpalette);

    QIcon qiimg(QPixmap(":/images/images/icon.png"));
    this->setWindowIcon(qiimg);

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

    m_layout->addWidget(moneyDisplayArea);

    m_layout->addWidget(cardDisplayArea);

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
    this->show();

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(check_active()));
    timer->start(50);

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
    //after clicking this, the options to play the game should show on the bottom
    gameOptions->show();

    //while(!(player1.check_if_empty()))
    //{
    QPixmap* displayImg = player1.get_card();
    QWidget* this_card = new QWidget(cardDisplays);
    this_card->setMaximumSize(100, 146);
    this_card->setMinimumSize(50, 73);

    QWidget *cardView = new CardView(cardDisplayArea);
    QHBoxLayout *matrixLayout = new QHBoxLayout(cardDisplayArea);
    QWidget *l1 = new QLabel(MatrixView(lhs, this).get_string());
    QWidget *l2 = new QLabel(operation);
    QWidget *l3 = new QLabel(MatrixView(rhs, this).get_string());
    QWidget *l4 = new QLabel(QString("="));
    QWidget *l5 = new QLabel(MatrixView(result, this).get_string());

    matrixLayout->addWidget(l1);
    matrixLayout->addWidget(l2);
    matrixLayout->addWidget(l3);
    matrixLayout->addWidget(l4);
    matrixLayout->addWidget(l5);

    QPixmap pic("/path/to/your/image");
   // ui->m_layout->setPixmap(displayImg);
    ui->

    /*
    *displayImg = displayImg->scaled(this_card->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, *displayImg);
    this_card->setPalette(palette);

    m_layout->addWidget(this_card);
    m_layout->stretch(1);
*/
    //cardDisplayLayout->addWidget(this_card);
    //}
}

void GameWindow::returnToMenu()
{
    emit menuReturn();
}

void GameWindow::check_active()
{
    if (!(this->isActiveWindow()))
        emit menuReturn();
}

void GameWindow::close_game()
{

}
