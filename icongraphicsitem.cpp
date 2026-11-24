#include "icongraphicsitem.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QPen>
#include <QStyleOptionGraphicsItem>
#include <QVariant>

namespace
{
/// Цвет рамки выделения объекта.
const QColor kSelectionColor(0x3D, 0x7E, 0xC4);
} // namespace

IconGraphicsItem::IconGraphicsItem(const QPixmap &iconPixmap, int iconId, QGraphicsItem *parent)
    : QGraphicsObject(parent)
    , m_iconPixmap(iconPixmap.scaled(IconSize, IconSize, Qt::KeepAspectRatio, Qt::SmoothTransformation))
    , m_iconId(iconId)
{
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
    setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton);
    setCursor(Qt::SizeAllCursor);
    setToolTip(tr("Перетащите объект мышью или задайте его координаты в таблице"));
}

QRectF IconGraphicsItem::boundingRect() const
{
    return QRectF(0.0, 0.0, IconSize, IconSize);
}

void IconGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter->drawPixmap(boundingRect().toRect(), m_iconPixmap);

    if (option->state & QStyle::State_Selected)
    {
        // Пунктирная рамка внутри объекта повторяет оформление выделения на рисунке задания.
        QPen pen(kSelectionColor, 1.0, Qt::DashLine);
        pen.setCosmetic(true);
        painter->setPen(pen);
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(QRectF(0.5, 0.5, IconSize - 1.0, IconSize - 1.0));
    }
}

void IconGraphicsItem::setTopLeft(const QPoint &topLeft)
{
    setPos(topLeft);
}

QVariant IconGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemPositionChange && scene() != nullptr)
    {
        // Объект не должен выходить за границы сцены, а его координаты —
        // всегда целые, чтобы совпадать со значениями таблицы поля (4).
        const QRectF canvas = scene()->sceneRect();
        const qreal maximumX = qMax<qreal>(0.0, canvas.width() - IconSize);
        const qreal maximumY = qMax<qreal>(0.0, canvas.height() - IconSize);

        QPointF position = value.toPointF();
        position.setX(qBound<qreal>(0.0, position.x(), maximumX));
        position.setY(qBound<qreal>(0.0, position.y(), maximumY));

        return QPointF(qRound(position.x()), qRound(position.y()));
    }

    if (change == QGraphicsItem::ItemPositionHasChanged)
        emit positionChanged(pos().toPoint());

    return QGraphicsObject::itemChange(change, value);
}
