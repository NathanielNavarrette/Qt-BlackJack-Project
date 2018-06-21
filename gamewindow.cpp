#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

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

    //top menu button connections
    connect(startButton, SIGNAL(clicked()), this, SLOT(game_start()));
    connect(menuButton, SIGNAL(clicked()), this, SLOT(returnToMenu()));
    connect(resetButton, SIGNAL(clicked()), this, SLOT(reset_pressed()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(save_pressed()));

    //game play options/control connections
    connect(hitButton, SIGNAL(clicked()), this, SLOT(hit_pressed()));
    connect(stayButton, SIGNAL(clicked()), this, SLOT(stay_pressed()));
    connect(splitButton, SIGNAL(clicked()), this, SLOT(split_pressed()));
    connect(betButton, SIGNAL(clicked()), this, SLOT(bet_pressed()));
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::game_start()
{
    //after clicking this, the options to play the game should show on the bottom
    gameOptions->show();
    startButton->hide();


    int added_count = 0;
    std::vector<QWidget*> card_buffer;
    std::vector<QWidget*> empty_buffer;
    player1.hit_card();
    Card my_blank = player1.get_card();
    my_blank.set_blank();

    while(!(player1.check_if_empty()))
    {
        if(added_count != 13)
        {
            qDebug() << "Going into the True for displaying cards";

            QPixmap* displayImg = player1.get_card_img();
            QWidget *card = new CardView(*displayImg, cardDisplayArea);
            card->setWhatsThis(player1.get_card().get_card_name());
            card_buffer.push_back(card);
            added_count++;
            player1.hit_card();
        }else{
            qDebug() << "Going into the False/else for displaying cards";
            QWidget* card_row = new CardView(cardDisplayArea);
            QHBoxLayout* row_layout = new QHBoxLayout(card_row);
            for(int i=0;i<card_buffer.size();i++)
                row_layout->addWidget(card_buffer.at(i));
            cardDisplayLayout->addWidget(card_row);
            card_buffer=empty_buffer;
            added_count=0;
        }
    }

    //add the last row to the display
    if(added_count == 13)
    {
        QWidget* card_row = new CardView(cardDisplayArea);
        QHBoxLayout* row_layout = new QHBoxLayout(card_row);
        for(int i=0;i<card_buffer.size();i++)
            row_layout->addWidget(card_buffer.at(i));
        cardDisplayLayout->addWidget(card_row);
        card_buffer=empty_buffer;
        added_count=0;
    }

    //add the blank card
    if(true)
    {
        QWidget* card_row = new CardView(cardDisplayArea);
        QHBoxLayout* row_layout = new QHBoxLayout(card_row);
        QPixmap* displayImg = my_blank.get_image();
        QWidget *card = new CardView(*displayImg, cardDisplayArea);
        row_layout->addWidget(card);

        cardDisplayLayout->addWidget(card_row, Qt::AlignCenter);
    }
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
    qDebug() << "Close game";
}

void GameWindow::reset_pressed()
{
    qDebug() << "reset button pressed";
}

void GameWindow::save_pressed()
{
    qDebug() << "save button pressed";
}

void GameWindow::hit_pressed()
{
    qDebug() << "hit button pressed";
}

void GameWindow::stay_pressed()
{
    qDebug() << "stay button pressed";
}

void GameWindow::split_pressed()
{
    qDebug() << "split button pressed";
}

void GameWindow::bet_pressed()
{
    qDebug() << "bet button pressed";
}
