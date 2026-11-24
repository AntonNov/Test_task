#ifndef ICONGRAPHICSITEM_H
#define ICONGRAPHICSITEM_H

#include <QGraphicsObject>
#include <QPoint>
#include <QRectF>

/**
 * \file icongraphicsitem.h
 * \brief Графический объект: пиктограмма 64x64 пикселя с координатами.
 */

/**
 * \brief Графический объект на сцене — пиктограмма 64x64 пикселя.
 *
 * Положение pos() считается координатами верхнего левого угла, поэтому
 * boundingRect() начинается в локальной точке (0, 0). Объект можно
 * перетаскивать мышью и выделять; выход за границы сцены и целые координаты
 * исключает itemChange().
 */
class IconGraphicsItem : public QGraphicsObject
{
    Q_OBJECT

public:
    /**
     * \brief Служебные константы класса.
     */
    enum
    {
        Type = UserType + 1,  //!< Идентификатор типа для qgraphicsitem_cast().
        IconSize = 64         //!< Сторона объекта в пикселях.
    };

    /**
     * \brief Создаёт объект с заданным растром.
     * \param iconPixmap Растр пиктограммы; приводится к размеру IconSize.
     * \param iconId Идентификатор пиктограммы каталога.
     * \param parent Родительский графический элемент.
     */
    explicit IconGraphicsItem(const QPixmap &iconPixmap, int iconId, QGraphicsItem *parent = nullptr);


    /// \brief Возвращает идентификатор типа объекта.
    int type() const override { return Type; }

    /// \brief Возвращает прямоугольник объекта в локальных координатах.
    QRectF boundingRect() const override;

    /**
     * \brief Рисует растр пиктограммы и рамку выделения.
     * \param painter Художник, предоставленный сценой.
     * \param option Параметры отрисовки, включая состояние выделения.
     * \param widget Виджет отрисовки; не используется.
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    /// \brief Возвращает идентификатор пиктограммы, из которой создан объект.
    int iconId() const { return m_iconId; }


    /// \brief Возвращает координаты верхнего левого угла объекта.
    QPoint topLeft() const { return pos().toPoint(); }


    /**
     * \brief Перемещает объект в точку topLeft.
     * \param topLeft Новые координаты верхнего левого угла.
     */
    void setTopLeft(const QPoint &topLeft);

signals:

    /**
     * \brief Сигнал об изменении положения объекта.
     * \param topLeft Действительные координаты верхнего левого угла.
     */
    void positionChanged(const QPoint &topLeft);

protected:

    /**
     * \brief Ограничивает положение границами сцены и выравнивает по пикселям.
     * \param change Вид изменения состояния элемента.
     * \param value Новое значение изменения.
     * \return Скорректированное значение изменения.
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
    QPixmap m_iconPixmap;  //!< Растр пиктограммы объекта.
    int m_iconId;          //!< Идентификатор пиктограммы каталога.
};

#endif // ICONGRAPHICSITEM_H
