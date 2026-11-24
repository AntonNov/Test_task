#ifndef ICONGRAPHICSITEM_H
#define ICONGRAPHICSITEM_H

#include <QGraphicsObject>
#include <QPoint>
#include <QRectF>


class IconGraphicsItem : public QGraphicsObject
{
    Q_OBJECT

public:
    enum
    {
        Type = UserType + 1,
        IconSize = 64
    };

    explicit IconGraphicsItem(const QPixmap &iconPixmap, int iconId, QGraphicsItem *parent = nullptr);


    int type() const override { return Type; }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    int iconId() const { return m_iconId; }


    QPoint topLeft() const { return pos().toPoint(); }


    void setTopLeft(const QPoint &topLeft);

signals:

    void positionChanged(const QPoint &topLeft);

protected:

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QPixmap m_iconPixmap;
    int m_iconId;
};

#endif // ICONGRAPHICSITEM_H
