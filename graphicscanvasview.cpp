#include "graphicscanvasview.h"

#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsScene>
#include <QPointF>
#include <QRectF>
#include <QResizeEvent>
#include <QSizeF>

#include "icontransfer.h"


GraphicsCanvasView::GraphicsCanvasView(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::white);
    setScene(scene);

    setAlignment(Qt::AlignLeft | Qt::AlignTop);
    setFrameShape(QFrame::StyledPanel);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setAcceptDrops(true);
    viewport()->setAcceptDrops(true);
}


void GraphicsCanvasView::dragEnterEvent(QDragEnterEvent *event)
{
    if (!IconTransfer::canDecode(event->mimeData()))
    {
        event->ignore();
        return;
    }

    event->setDropAction(Qt::CopyAction);
    event->accept();
}


void GraphicsCanvasView::dragMoveEvent(QDragMoveEvent *event)
{
    if (!IconTransfer::canDecode(event->mimeData()))
    {
        event->ignore();
        return;
    }

    event->setDropAction(Qt::CopyAction);
    event->accept();
}


void GraphicsCanvasView::dropEvent(QDropEvent *event)
{
    const int iconId = IconTransfer::decodeIconId(event->mimeData());
    if (iconId < 0)
    {
        event->ignore();
        return;
    }

    event->setDropAction(Qt::CopyAction);
    event->accept();

    emit iconDropped(iconId);
}


void GraphicsCanvasView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);

    scene()->setSceneRect(QRectF(QPointF(0, 0), QSizeF(viewport()->size())));
}
