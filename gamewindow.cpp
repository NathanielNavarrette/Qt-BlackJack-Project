#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    nothing->setMinimumWidth(100);

    this->setWindowTitle("Black Jack Game");

    QIcon qiimg(QPixmap(":/images/images/icon.png"));
    this->setWindowIcon(qiimg);

    this->setMinimumHeight(740);
    this->setMinimumWidth(800);

    m_background_img = QPixmap(":/images/images/background.png");
    m_background_img = m_background_img.scaled(this->size(), Qt::IgnoreAspectRatio);
    m_palette.setBrush(QPalette::Background, m_background_img);
    this->setPalette(m_palette);

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

    m_prev_size = this->size();

    //m_icon->show();
    this->show();

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(check_active()));
    connect(timer, SIGNAL(timeout()), this, SLOT(check_size_change()));
    timer->start(25);

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

    hitButton->setEnabled(false);
    stayButton->setEnabled(false);
    splitButton->setEnabled(false);
    betButton->setEnabled(false);
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::play_game()
{

    player_turn();

    hitButton->setEnabled(false);
    stayButton->setEnabled(false);
    splitButton->setEnabled(false);
    betButton->setEnabled(false);

    for(int i=0;i<2;i++)
        computer_turn(i);
}

void GameWindow::draw_cards()
{

}

void GameWindow::player_turn()
{
    //bool end_player_turn = false;

    hitButton->setEnabled(true);
    stayButton->setEnabled(true);
    splitButton->setEnabled(true);
    betButton->setEnabled(true);

    for(int i=0;i<2;i++)
    {
        player1->hit_card();
        QPixmap* displayImg = player1->get_card_img();
        QWidget *card = new CardView(*displayImg, cardDisplayArea);
        card->setWhatsThis(player1->get_card()->get_card_name());
        m_cards_buffer.push_back(card);
        m_hand_displays_layout.at(0)->addWidget(m_cards_buffer.at(i));
    }
    cardDisplayLayout->addWidget(m_hand_displays.at(0));

    /*
    while(end_player_turn == false)
    {

    }
    */

}

void GameWindow::computer_turn(int computer_pos)
{

}

void GameWindow::check_win()
{

}

void GameWindow::check_size_change()
{
    if(this->size() != m_prev_size)
    {
        QPixmap bkgnd(":/images/images/background.png");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);
    }
}

void GameWindow::recieved_options(GameOptions* send_options)
{
    qDebug() << "Recieved options caught";
    qDebug() << send_options->get_string(send_options->get_difficulty_int());
    m_options = send_options;
}

void GameWindow::game_start()
{
    //after clicking this, the options to play the game should show on the bottom
    gameOptions->show();
    startButton->hide();

    //display_all_cards();
    //create the layout on the board for the correct players
    //there will be 4 each row and only the first and last (4th) will contain stuff
    int count = 0;
    for(int i=0;i<m_options->get_num_players();i++)
    {
        for(int j=0;j<4;j++)
        {
            m_hand_displays.push_back(new QWidget(cardDisplayArea));
            m_hand_displays_layout.push_back(new QHBoxLayout(m_hand_displays.at(count)));
            if(j == 1 || 2)
                for(int k=0;k<5;k++)
                    m_hand_displays_layout.at(count)->addWidget(nothing);
            count++;
        }
    }

    qDebug() << "Finsihed creating the layouts";
    play_game();

    //m_options->debug_options("GameWindow");
    //display_all_cards();
}

void GameWindow::display_all_cards()
{
    int added_count = 0;
    std::vector<QWidget*> card_buffer;
    std::vector<QWidget*> empty_buffer;
    player1->hit_card();
    Card* my_blank = player1->get_card();
    my_blank->set_blank();

    while(!(player1->check_if_empty()))
    {
        if(added_count != 13)
        {
            //qDebug() << "Going into the True for displaying cards";

            QPixmap* displayImg = player1->get_card_img();
            QWidget *card = new CardView(*displayImg, cardDisplayArea);
            card->setWhatsThis(player1->get_card()->get_card_name());
            card_buffer.push_back(card);
            added_count++;
            player1->hit_card();
        }else{
            //qDebug() << "Going into the False/else for displaying cards";
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
    if(added_count == 12)
    {
        //player1->hit_card();
        QPixmap* displayImg = player1->get_card_img();
        QWidget *card = new CardView(*displayImg, cardDisplayArea);
        card->setWhatsThis(player1->get_card()->get_card_name());
        card_buffer.push_back(card);

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
        QPixmap* displayImg = my_blank->get_image();
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


