#include "iconpainter.h"

QPixmap drawInfoIcon(int side){
    QPixmap canvas(side, side);
    canvas.fill(Qt::transparent);

    QPainter painter(&canvas);
    const qreal stroke = qMax<qreal>(1.2, side * 0.05);

    QPen pen(Qt::black, stroke, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);


    const qreal inset = side * 0.05;
    const QRectF frame(inset, inset, side - 2.0 * inset, side - 2.0 * inset);
    painter.drawRoundedRect(frame, side * 0.2, side * 0.2);

    const qreal diameter = side * 0.6;
    const QRectF circle(frame.center().x() - diameter / 2.,
                        frame.center().y() - diameter / 2.,
                        diameter,
                        diameter);
    painter.drawEllipse(circle);

    QFont font = QApplication::font();
    font.setFamily("Times New Roman");
    font.setPixelSize(qMax(6, qRound(side * 0.4)));
    font.setBold(true);

    painter.setFont(font);
    painter.setPen(Qt::black);
    painter.drawText(circle, Qt::AlignCenter, "i");
    painter.end();
    return canvas;
}

QPixmap pixmap(int iconId, int size  = 64)
{
    if (iconId != InfoIcon)
        return QPixmap();

    const int side = qMax(8, size);
    return drawInfoIcon(side);
}

QIcon icon(int iconId)
{
    return pixmap(iconId);
}
