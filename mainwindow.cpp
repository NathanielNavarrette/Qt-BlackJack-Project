#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QCoreApplication::setApplicationName("BlackJack");

    QIcon qiimg(QPixmap(":/images/images/icon.png"));
    m_icon->setIcon(qiimg);
    this->setWindowIcon(qiimg);

    this->setMinimumHeight(500);
    this->setMinimumWidth(533);

    this->setMaximumHeight(500);
    this->setMaximumWidth(533);

    QPixmap bkgnd(":/images/images/bg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    displayAreaLayout->addWidget(returnButton);
    displayAreaLayout->stretch(1);
    displayAreaLayout->addWidget(playButton);
    displayAreaLayout->stretch(1);
    displayAreaLayout->addWidget(closeButton);
    displayAreaLayout->stretch(1);

    secondRowLayout->addWidget(optionsButton);
    secondRowLayout->stretch(1);
    secondRowLayout->addWidget(loadButton);
    secondRowLayout->stretch(1);

    thirdRowLayout->addWidget(ruleButton);
    thirdRowLayout->stretch(1);
    thirdRowLayout->addWidget(aboutButton);
    thirdRowLayout->stretch(1);

    nothing->setMinimumHeight(50);
    m_layout->addWidget(nothing);
    m_layout->addWidget(nothing);
    m_layout->addWidget(nothing);
    m_layout->addWidget(nothing);
    m_layout->addWidget(nothing);
    m_layout->addWidget(nothing);
    m_layout->addWidget(displayArea);
    m_layout->addWidget(secondRow);
    m_layout->addWidget(thirdRow);

    connect(playButton, SIGNAL(clicked()), this, SLOT(play_clicked()));
    connect(returnButton, SIGNAL(clicked()), this, SLOT(return_clicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close_clicked()));

    connect(optionsButton, SIGNAL(clicked()), this, SLOT(options_clicked()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(load_clicked()));

    connect(ruleButton, SIGNAL(clicked()), this, SLOT(rules_clicked()));
    connect(aboutButton, SIGNAL(clicked()), this, SLOT(about_clicked()));

    returnButton->hide();

    ui->centralWidget->setLayout(m_layout);
    m_icon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::menu_pressed()
{
    m_game->hide();
    this->show();
}

void MainWindow::play_clicked()
{
    qDebug() << "Play button clicked";
    m_game = new GameWindow(this);
    m_game->show();
    this->hide();
    m_icon->show();

    displayAreaLayout->removeWidget(playButton);
    delete playButton;
    returnButton->show();
}

void MainWindow::return_clicked()
{
    qDebug() << "Return button clicked";
    m_game->showNormal();
    m_game->show();
    this->hide();

}

void MainWindow::close_clicked()
{
    qDebug() << "Closed button clicked";
    //this->close();
    QApplication::quit();
}

void MainWindow::options_clicked()
{
    qDebug() << "options button clicked";
}

void MainWindow::load_clicked()
{
    qDebug() << "load button clicked";
}

void MainWindow::rules_clicked()
{
    qDebug() << "rules button clicked";
}

void MainWindow::about_clicked()
{
    qDebug() << "about button clicked";
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    event->accept();
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "BlackJack",
                                                                tr("Are you sure?\nDon't forget to save!"),
                                                                QMessageBox::Cancel | QMessageBox::Ok,
                                                                QMessageBox::Ok);

    if (resBtn != QMessageBox::Ok)
        event->ignore();
    else
        event->accept();
}
