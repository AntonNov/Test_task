#ifndef GRAPHICSCANVASVIEW_H
#define GRAPHICSCANVASVIEW_H

#include <QGraphicsView>

/**
 * \file graphicscanvasview.h
 * \brief Графическая область, принимающая перетаскивание.
 */

class QDragEnterEvent;
class QDragMoveEvent;
class QDropEvent;
class QResizeEvent;


/**
 * \brief Рабочая область фиксированного размера 1024x512.
 *
 * Принимает перенос только с прикладным MIME-типом из icontransfer.h и
 * сообщает об успешном переносе сигналом iconDropped(). Сцена всегда равна
 * вьюпорту, поэтому координаты объектов совпадают с пикселями области.
 */
class GraphicsCanvasView : public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * \brief Создаёт область с пустой белой сценой.
     * \param parent Родительский виджет.
     */
    GraphicsCanvasView(QWidget *parent = nullptr);

signals:

    /**
     * \brief Сигнал об успешном завершении перетаскивания.
     * \param iconId Идентификатор перенесённой пиктограммы.
     */
    void iconDropped(int iconId);

protected:
    /**
     * \brief Принимает перенос, если данные созданы каталогом пиктограмм.
     * \param event Событие входа курсора с перетаскиваемыми данными.
     */
    void dragEnterEvent(QDragEnterEvent *event) override;

    /**
     * \brief Подтверждает перенос при движении курсора над областью.
     * \param event Событие движения с перетаскиваемыми данными.
     */
    void dragMoveEvent(QDragMoveEvent *event) override;

    /**
     * \brief Завершает перенос и испускает сигнал iconDropped().
     * \param event Событие отпускания кнопки мыши.
     */
    void dropEvent(QDropEvent *event) override;

    /**
     * \brief Подгоняет прямоугольник сцены под размер вьюпорта.
     * \param event Событие изменения размера области.
     */
    void resizeEvent(QResizeEvent *event) override;

};

#endif // GRAPHICSCANVASVIEW_H
