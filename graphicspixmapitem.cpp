#include "graphicspixmapitem.h"
#include "city.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

GraphicsPixmapItem::GraphicsPixmapItem(QPixmap pixmap): QGraphicsPixmapItem(pixmap)
{
}


void GraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    int x = event->lastPos().x();
    int y = event->lastPos().y();
    qDebug() << x;
    qDebug() << y;
    emit pointClicked(event->lastPos().toPoint());
}
