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
    void addOptionsDialog();
    void options_dialog();

    GameOptions m_options;

signals:
    void finished(GameOptions changed_options);

public slots:
    void changingOptions();
    void displayRules();
    void displayAbout();

private slots:

};

#endif // OPTIONSWINDOW_H
