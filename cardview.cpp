#include "cardview.h"

CardView::CardView(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(500);
    setMinimumWidth(500);
}

CardView::CardView(QPixmap& img, QWidget *parent = nullptr)
{

}
