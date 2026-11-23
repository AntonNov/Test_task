#ifndef ICONPAINTER_H
#define ICONPAINTER_H

#include <QIcon>
#include <QPixmap>
#include <QApplication>
#include <QColor>
#include <QFont>
#include <QPainter>
#include <QPen>
#include <QRectF>
#include <QString>

enum IconId
{
    InfoIcon = 1
};


QPixmap drawInfoIcon(int);

QPixmap pixmap(int iconId, int size);

QIcon icon(int iconId);

#endif // ICONPAINTER_H
