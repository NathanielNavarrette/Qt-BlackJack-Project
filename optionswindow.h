#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialogButtonBox>
#include <QRadioButton>
#include <QWizardPage>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include <QLayout>
#include <QDialog>
#include <QWizard>
#include <QDebug>
#include <QLabel>
#include <vector>
#include <QTime>

#include"gameoptions.h"

class OptionsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit OptionsWindow(QWidget *parent = nullptr);

private:
    // Create dialogs for MainWindow
    void options_dialog();
    void rulesDialog();
    void about_dialog();

    // Create dialogs for GameWindow
    void bet_dialog();

    GameOptions* m_options = new GameOptions();

signals:
    void finished(GameOptions* changed_options);

public slots:
    // slots for MainWindow
    void changingOptions();
    void displayRules();
    void displayAbout();

    // slots for GameWindow
    void openBetting();

private slots:

};

#endif // OPTIONSWINDOW_H
