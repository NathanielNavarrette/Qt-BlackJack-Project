#include "optionswindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) : QWidget(parent)
{
    this->setMaximumWidth(150);
}

void OptionsWindow::changingOptions()
{
    qDebug() << "options slot recieed";
    options_dialog();
}

void OptionsWindow::options_dialog()
{
    qDebug() << "Attempting to create options dialog";
    QDialog dialog(this);
    dialog.setMinimumHeight(225);
    dialog.setMinimumWidth(150);
    dialog.setMaximumHeight(350);
    dialog.setMaximumWidth(200);

    // QForum as a layout for the dialog window
    QFormLayout form(&dialog);

    // Dialog Window Title thing
    form.addRow(new QLabel("Game Options:"));

    QLabel* num_of_players_label = new QLabel("Number of Players:");
    QSpinBox* edit_players = new QSpinBox(&dialog);

    edit_players->setValue(m_options->get_num_players());
    edit_players->setMinimum(1);
    edit_players->setMaximum(4);

    QLabel* money_label = new QLabel("Starting Money:");
    QLineEdit* edit_money = new QLineEdit(QString::number(m_options->get_start_money()), &dialog);

    QLabel* bet_label = new QLabel("Minumum Bet:");
    QLineEdit* edit_bet = new QLineEdit(QString::number(m_options->get_min_bet()), &dialog);

    QLabel* diffcult_label = new QLabel("Difficulty:");
    QRadioButton* difficulty_list[5];

    form.addRow(num_of_players_label, edit_players);
    form.addRow(money_label, edit_money);
    form.addRow(bet_label, edit_bet);
    form.addRow(diffcult_label);

    for(int i=0; i<5; i++)
    {
        difficulty_list[i] = new QRadioButton(QString(m_options->get_string(i)), this);
        if(i == m_options->get_difficulty_int())
            difficulty_list[i]->setChecked(true);
        form.addRow(difficulty_list[i]);
    }

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Check what user does with dialog
    if (dialog.exec() == QDialog::Accepted){
        qDebug() << "Options Window Accepted";
        qDebug() << "Number of players inputted: " << edit_players->text().toInt();
        m_options->set_num_players(edit_players->text().toInt());
        qDebug() << "Starting Money Inputted: " << edit_money->text().toInt();
        m_options->set_start_money(edit_money->text().toInt());
        qDebug() << "Minimum Bet inputted: " << edit_bet->text().toInt();
        m_options->set_min_bet(edit_bet->text().toInt());

        for(int i=0;i<5;i++)
        {
            if(difficulty_list[i]->isChecked())
            {
                qDebug() << "Difficulty Checked: " << m_options->get_string(i);
                m_options->set_difficulty(i);
            }
        }
        emit finished(m_options);
        // If the user didn't dismiss the dialog, do something with the fields
    }else{
        qDebug() << "Options Window Rejected";
        //just close and do nothing
    }
}
void OptionsWindow::displayRules()
{
    rulesDialog();
}

void OptionsWindow::rulesDialog()
{
    qDebug() << "Attempting to display Rules";
    QDialog dialog(this);
    dialog.setMinimumHeight(225);
    dialog.setMinimumWidth(150);
    //dialog.setMaximumHeight(350);
    //dialog.setMaximumWidth(200);

    // QForum as a layout for the dialog window
    QFormLayout form(&dialog);

    // Dialog Window Title thing
    form.addRow(new QLabel("Black Jack Rules:\n"));
    form.addRow(new QLabel("How it's played:"));
    form.addRow(new QLabel(
                    "Each player will start out with two cards.\n"
                    "The card totals have to get as close as they can \n"
                    "to the number 21 without going over. Face cards \n"
                    "have a value of 10, except for ace which can count \n"
                    "as 1 or 11.  Each player will make a bet, then get \n"
                    "their hand and either fold, stay or 'hit' where the \n"
                    "dealer or 'house' gives an other card to the player. \n"
                    ));
    form.addRow(new QLabel("Objectives:"));
    form.addRow(new QLabel("•Get highest number without going over 21.\n"
                           "•Get as much money as you can!\n"
                           "•That's pretty much it."));


    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));

    // Check what user does with dialog
    if (dialog.exec() == QDialog::Accepted){
        qDebug() << "Options Window Accepted";
        // If the user didn't dismiss the dialog, do something with the fields
    }else{
        qDebug() << "Options Window Rejected";
        //just close and do nothing
    }
}

void OptionsWindow::displayAbout()
{
    qDebug() << "Attempting to display About";
    about_dialog();
}

void OptionsWindow::about_dialog()
{
    qDebug() << "Attempting to display Rules";
    QDialog dialog(this);
    dialog.setMinimumHeight(225);
    dialog.setMinimumWidth(150);
    //dialog.setMaximumHeight(350);
    //dialog.setMaximumWidth(200);

    // QForum as a layout for the dialog window
    QFormLayout form(&dialog);

    // Dialog Window Title thing
    form.addRow(new QLabel("About:\n"));
    form.addRow(new QLabel("Author: Nathaniel Navarrette"));
    form.addRow(new QLabel("Author Email: nathaniel.navarrette96@gmail.com"));
    form.addRow(new QLabel("Version: 0.0.0.1"));

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));

    // Check what user does with dialog
    if (dialog.exec() == QDialog::Accepted){
        qDebug() << "Options Window Accepted";
        // If the user didn't dismiss the dialog, do something with the fields
    }else{
        qDebug() << "Options Window Rejected";
        //just close and do nothing
    }
}

void OptionsWindow::openBetting()
{
    qDebug() << "Attempting to crete betting diaog";
    bet_dialog();
}

void OptionsWindow::bet_dialog()
{
    qDebug() << "Attempting to display Rules";
    QDialog dialog(this);
    dialog.setMinimumHeight(225);
    dialog.setMinimumWidth(150);
    //dialog.setMaximumHeight(350);
    //dialog.setMaximumWidth(200);

    // QForum as a layout for the dialog window
    QFormLayout form(&dialog);

    // Dialog Window Title thing
    form.addRow(new QLabel("How Much Do You Want To Bet?:\n"));
    QLabel* amount_label = new QLabel("Amount: ");
    QSpinBox* bet_amount = new QSpinBox(&dialog);

    bet_amount->setValue(m_options->get_num_players());
    bet_amount->setMinimum(1);
    bet_amount->setMaximum(4);

    form.addRow(amount_label, bet_amount);

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));

    // Check what user does with dialog
    if (dialog.exec() == QDialog::Accepted){
        qDebug() << "Options Window Accepted";
        // If the user didn't dismiss the dialog, do something with the fields
    }else{
        qDebug() << "Options Window Rejected";
        //just close and do nothing
    }
}
