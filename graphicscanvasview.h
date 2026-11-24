#ifndef GRAPHICSCANVASVIEW_H
#define GRAPHICSCANVASVIEW_H

#include <QGraphicsView>

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
class QResizeEvent;


class GraphicsCanvasView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsCanvasView(QWidget *parent = nullptr);

signals:

    void iconDropped(int iconId);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

};

#endif // GRAPHICSCANVASVIEW_H
