#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumHeight(300);
    this->setMinimumWidth(300);

    /*
    QPixmap bkgnd(":/images/bg.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
*/
    displayAreaLayout->addWidget(playButton);
    displayAreaLayout->addWidget(closeButton);


    //displayAreaLayout


    /*
    topButtonLayout->addWidget(startButton);
    topButtonLayout->addWidget(optionsButton);
    topButtonLayout->addWidget(saveButton);
    topButtonLayout->addWidget(loadButton);
    m_layout->addWidget(topButtons);

    m_layout->addWidget(moneyDisplays);

    m_layout->addWidget(cardDisplays);

    gameOptionsLayout->addWidget(hitButton);
    gameOptionsLayout->addWidget(stayButton);
    gameOptionsLayout->addWidget(splitButton);
    gameOptionsLayout->addWidget(betButton);
    m_layout->addWidget(gameOptions);

    this->setMinimumHeight(600);
    this->setMinimumWidth(800);

    ui->centralWidget->setLayout(m_layout);
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::play_clicked()
{

}

void MainWindow::close_clicked()
{

}
