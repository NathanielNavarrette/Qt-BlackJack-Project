#include "optionswindow.h"

OptionsWindow::OptionsWindow(QWidget *parent) : QWidget(parent)
{

}

void OptionsWindow::addOptionsDialog()
{

}

void OptionsWindow::changingOptions(bool clicked)
{

}

void OptionsWindow::options_dialog()
{
    //might have to change this over to a qwizard class for some odd reason
    //that way i can just place the stuff inside the dialog box
    /*
    QLabel *classNameLabel;
    QLabel *baseClassLabel;
    QLineEdit *classNameLineEdit;
    QLineEdit *baseClassLineEdit;
    QCheckBox *qobjectMacroCheckBox;
    QGroupBox *groupBox;
    QRadioButton *qobjectCtorRadioButton;
    QRadioButton *qwidgetCtorRadioButton;
    QRadioButton *defaultCtorRadioButton;
    QCheckBox *copyCtorCheckBox;

    setTitle(tr("Class Information"));
    setSubTitle(tr("Specify basic information about the class for which you "
                   "want to generate skeleton source code files."));
    setPixmap(QWizard::LogoPixmap, QPixmap(":/images/logo1.png"));

    classNameLabel = new QLabel(tr("&Class name:"));
    classNameLineEdit = new QLineEdit;
    classNameLabel->setBuddy(classNameLineEdit);

    baseClassLabel = new QLabel(tr("B&ase class:"));
    baseClassLineEdit = new QLineEdit;
    baseClassLabel->setBuddy(baseClassLineEdit);

    qobjectMacroCheckBox = new QCheckBox(tr("Generate Q_OBJECT &macro"));

    groupBox = new QGroupBox(tr("C&onstructor"));

    qobjectCtorRadioButton = new QRadioButton(tr("&QObject-style constructor"));
    qwidgetCtorRadioButton = new QRadioButton(tr("Q&Widget-style constructor"));
    defaultCtorRadioButton = new QRadioButton(tr("&Default constructor"));
    copyCtorCheckBox = new QCheckBox(tr("&Generate copy constructor and "
                                        "operator="));

    defaultCtorRadioButton->setChecked(true);

    connect(defaultCtorRadioButton, &QAbstractButton::toggled,
            copyCtorCheckBox, &QWidget::setEnabled);

    registerField("className*", classNameLineEdit);
    registerField("baseClass", baseClassLineEdit);
    registerField("qobjectMacro", qobjectMacroCheckBox);
    registerField("qobjectCtor", qobjectCtorRadioButton);
    registerField("qwidgetCtor", qwidgetCtorRadioButton);
    registerField("defaultCtor", defaultCtorRadioButton);
    registerField("copyCtor", copyCtorCheckBox);

    QVBoxLayout *groupBoxLayout = new QVBoxLayout;
    groupBoxLayout->addWidget(qobjectCtorRadioButton);
    groupBoxLayout->addWidget(qwidgetCtorRadioButton);
    groupBoxLayout->addWidget(defaultCtorRadioButton);
    groupBoxLayout->addWidget(copyCtorCheckBox);
    groupBox->setLayout(groupBoxLayout);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(classNameLabel, 0, 0);
    layout->addWidget(classNameLineEdit, 0, 1);
    layout->addWidget(baseClassLabel, 1, 0);
    layout->addWidget(baseClassLineEdit, 1, 1);
    layout->addWidget(qobjectMacroCheckBox, 2, 0, 1, 2);
    layout->addWidget(groupBox, 3, 0, 1, 2);
    setLayout(layout);
    */
}
