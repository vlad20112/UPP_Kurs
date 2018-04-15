#ifndef CARD_H
#define CARD_H
#include <QString>
#include <QGraphicsItem>
#include <QColor>

class Card : public QGraphicsItem
{
private:
    QString text;
    QColor col;
public:
    Card();
    Card(QString,QColor);
    QRectF rectCard() const;
    void DrawCard(QGraphicsScene *Scene);
};

#endif // CARD_H
