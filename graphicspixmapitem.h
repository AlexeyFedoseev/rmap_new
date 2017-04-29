#ifndef GRAPHICSPIXMAPITEM_H
#define GRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QPoint>

class GraphicsPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    GraphicsPixmapItem(QPixmap pixmap);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
signals:
    void pointClicked(QPoint);
};

#endif // GRAPHICSPIXMAPITEM_H
