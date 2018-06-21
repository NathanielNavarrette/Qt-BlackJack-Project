#include "cardview.h"

CardView::CardView(QWidget *parent) : QWidget(parent)
{
    //just set this a minimum area
    setMinimumHeight(500);
    setMinimumWidth(500);
}


CardView::CardView(QPixmap& img, QWidget *parent) : QWidget(parent)
{
    QLabel* tmp_label = new QLabel(this);
    tmp_label->setPixmap(img);
    QWidget* my_card = new QLabel(tmp_label);
    m_layout->addWidget(my_card);
}
