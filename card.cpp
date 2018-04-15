#include "card.h"
#include <QGraphicsScene>
#include <QPainter>

Card::Card()
{

}
Card::Card(QString a,QColor b)
{
    this->text = a;
    this->col = b;
}

QRectF Card::rectCard() const
{
    qreal width = 2;
    return QRectF(-10 - width / 2, -10 - width / 2,
                  20 + width, 20 + width);
}
void Card::DrawCard(QGraphicsScene *Scene)
{
   //Scene->addItem(card1);
   // Scene->addItem(card1);
    //Scene->addRect(rectCard());
    //Scene->addText("foma");
    //Scene->addItem(Card("ppggr",Qt::green));
}
