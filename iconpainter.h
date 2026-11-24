#ifndef ICONPAINTER_H
#define ICONPAINTER_H

/**
 * \file iconpainter.h
 * \brief Программная отрисовка пиктограмм приложения.
 */

#include <QIcon>
#include <QPixmap>
#include <QApplication>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QPen>
#include <QRectF>
#include <QString>

/**
 * \brief Идентификаторы пиктограмм каталога.
 */
enum IconId
{
    InfoIcon = 1  //!< Пиктограмма «информация» — единственный элемент каталога.
};


/**
 * \brief Рисует пиктограмму «информация» заданного размера.
 * \param side Сторона квадрата в пикселях.
 * \return Растр с прозрачным фоном.
 */
QPixmap drawInfoIcon(int);

/**
 * \brief Возвращает растр пиктограммы нужного размера.
 * \param iconId Идентификатор пиктограммы (см. IconId).
 * \param size Сторона квадрата в пикселях (по умолчанию 64).
 * \return Готовый растр или пустой растр, если идентификатор неизвестен.
 */
QPixmap pixmap(int iconId, int size);

/**
 * \brief Возвращает QIcon для элемента списка каталога.
 * \param iconId Идентификатор пиктограммы (см. IconId).
 * \return Готовый QIcon или пустой QIcon, если идентификатор неизвестен.
 */
QIcon icon(int iconId);

#endif // ICONPAINTER_H
