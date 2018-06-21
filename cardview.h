#ifndef CARDVIEW_H
#define CARDVIEW_H

#include <QMouseEvent>
#include <QWidget>
#include <QPixmap>
#include <QLayout>
#include <QLabel>
#include <QDebug>

#include "carddeck.h"
#include "card.h"


class CardView : public QWidget
{
    Q_OBJECT
public:
    explicit CardView(QWidget *parent = nullptr);
    CardView(QPixmap &img, QWidget *parent = nullptr);

private:
    void debug_card(QMouseEvent * e);
    QWidget* displayWindow = new QWidget(this);
    QHBoxLayout* m_layout = new QHBoxLayout(displayWindow);


signals:

public slots:
};

#endif // CARDVIEW_H
