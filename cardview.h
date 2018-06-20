#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QWidget>
#include <QPixmap>
#include <QLayout>

#include "carddeck.h"
#include "card.h"


class CardView : public QWidget
{
    Q_OBJECT
public:
    explicit CardView(QWidget *parent = nullptr);
    explicit CardView(QPixmap& img, QWidget *parent = nullptr);

private:
    QWidget* displayWindow = new QWidget(this);
    QHBoxLayout* m_layout = new QHBoxLayout(displayWindow);


signals:

public slots:
};

#endif // CARDVIEW_H
