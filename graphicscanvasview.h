#ifndef GRAPHICSCANVASVIEW_H
#define GRAPHICSCANVASVIEW_H

#include <QGraphicsView>

class GraphicsCanvasView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsCanvasView(QWidget *parent = nullptr);
};

#endif // GRAPHICSCANVASVIEW_H
