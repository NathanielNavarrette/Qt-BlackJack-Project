#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    nothing->setMinimumWidth(100);
    get_locatons();

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

void GameWindow::get_locatons()
{
    std::vector<int> tmp1;
    std::vector<int> tmp2;
    std::vector<int> result;
    //subtract first two times by 0
    //subtract second two terms by 2
    //subtract final two terms by 4
    for(int i=0;i<6;i++)
        tmp1.push_back(i*3);

    for(int i=0;i<6;i+=2)
    {
        tmp2.push_back(i);
        tmp2.push_back(i);
    }

    for(int i=0;i<6;i++)
    {
        result.push_back(tmp1.at(i)-tmp2.at(i));
        qDebug() << tmp1.at(i)-tmp2.at(i);
    }

    m_cpu_locations = result;
}

void GameWindow::play_game()
{

    player_turn();
    draw_cards();

    hitButton->setEnabled(false);
    stayButton->setEnabled(false);
    splitButton->setEnabled(false);
    betButton->setEnabled(false);


    for(int i=0;i<2;i++)
        computer_turn(i);
}

void GameWindow::draw_cards()
{
    //player draws card
    for(int i=0;i<2;i++)
    {
        player1->hit_card();
        QPixmap* displayImg = player1->get_card_img();
        QWidget *card = new CardView(*displayImg, cardDisplayArea);
        card->setWhatsThis(player1->get_card()->get_card_name());
        m_cards_buffer.push_back(card);
        m_hand_displays_layout.at(0)->addWidget(m_cards_buffer.at(i));
    }
    //m_hand_displays_layout.at(0)->addWidget(m_hand_displays.at(0));
    m_hand_displays.at(0)->setStyleSheet("background-color: red");
    m_cards_buffer.clear();

    //Comptuers draw cards
    for(int j=1;j<m_cpu.size();j++)
    {
        for(int i=0;i<2;i++)
        {
            m_cpu.at(j)->hit_card();
            if(i==1)
                m_cpu.at(j)->
            QPixmap* displayImg = m_cpu.at(j)->get_card_img();
            QWidget *card = new CardView(*displayImg, cardDisplayArea);
            card->setWhatsThis(m_cpu.at(j)->get_card()->get_card_name());
            m_cards_buffer.push_back(card);
            m_hand_displays_layout.at
                    (m_cpu_locations.at(j))->addWidget
                    (m_cards_buffer.at(i));
        }
        //cardDisplayLayout->addWidget(m_hand_displays.at(m_cpu_locations.at(j)));
        m_cards_buffer.clear();
    }
}

void GameWindow::player_turn()
{
    //bool end_player_turn = false;

    hitButton->setEnabled(true);
    stayButton->setEnabled(true);
    splitButton->setEnabled(true);
    betButton->setEnabled(true);

    /*
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
    */
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
    //create a row that has 4 H layouts in them and add 3 of them to card displays

    QWidget* card_row = new CardView(cardDisplayArea);
    QHBoxLayout* row_layout = new QHBoxLayout(card_row);

    int count=0;
    int keeptrack=0;
    for(int i=0;i<3;i++)
    {
        QWidget* card_row = new CardView(cardDisplayArea);
        QHBoxLayout* row_layout = new QHBoxLayout(card_row);
        for(int j=0;j<4;j++)
        {

            m_hand_displays.push_back
                    (new CardView(cardDisplayArea));
            m_hand_displays_layout.push_back
                    (new QHBoxLayout(m_hand_displays.at(count)));

            if(j == 1 || 2)
                for(int k=0;k<5;k++)
                    m_hand_displays_layout.at(count)->addWidget(nothing);
            count++;

        }

        keeptrack=count-3;
        for(int j=keeptrack;j<count;j++)
        {
            row_layout->addWidget(m_hand_displays.at(keeptrack));
        }
        cardDisplayLayout->addWidget(card_row);
    }


    /*
    int count = 0;
    for(int i=0;i<m_options->get_num_players();i++)
    {
        QWidget* card_row = new CardView(cardDisplayArea);
        QHBoxLayout* row_layout = new QHBoxLayout(card_row);
        for(int j=0;j<3;j++)
        {


            //card row widget
            m_hand_displays.push_back(new CardView(cardDisplayArea));
            //card row layout
            m_hand_displays_layout.push_back
                    (new QHBoxLayout(m_hand_displays.at(count)));
            //m_hand_displays.at(count)->setStyleSheet("background-color: blue");
            if(j == 1 || 2)
                for(int k=0;k<5;k++)
                    m_hand_displays_layout.at(count)->addWidget(nothing);

            count++;
        }
        for(int j=0;j<m_hand_displays.size();j++)
        {
            cardDisplayLayout->addWidget(m_hand_displays.at(j));
        }
    }
    */

    m_hand_displays.at(1)->setStyleSheet("background-color: blue");

    for(int i=0;i<count;i++)
        cardDisplayLayout->addWidget(m_hand_displays.at(i));

    qDebug() << "Finsihed creating the layouts";

    //create the AI computers
    for(int i=0;i<m_options->get_num_players()+1;i++)
        m_cpu.push_back(new ComputerAi);

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




