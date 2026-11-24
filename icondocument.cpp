#include "IconDocument.h"

#include <QGraphicsScene>
#include <QPixmap>

#include "iconpainter.h"
#include "icongraphicsitem.h"
#include "iconrecordsmodel.h"
#include "iconcoordinatesmodel.h"

IconDocument::IconDocument(QGraphicsScene *scene, QObject *parent)
    : QObject(parent)
    , m_scene(scene)
    , m_records(new IconRecordsModel(this))
    , m_coordinates(new IconCoordinatesModel(this))
    , m_currentRow(-1)
    , m_topZValue(0.0)
{
    Q_ASSERT(m_scene != nullptr);
}

int IconDocument::createIcon(int iconId)
{
    const QPixmap iconPixmap = pixmap(iconId, IconGraphicsItem::IconSize);

    IconGraphicsItem *icon = new IconGraphicsItem(iconPixmap, iconId);
    m_scene->addItem(icon);

    icon->setPos(0.0, 0.0);
    icon->setZValue(++m_topZValue);

    const int row = m_records->appendIcon(icon);

    connect(icon, &IconGraphicsItem::positionChanged, this, [this, row]() {
        m_records->notifyRowChanged(row);
    });

    emit iconCreated(row);
    setCurrentRow(row);

    return row;
}

void IconDocument::setCurrentRow(int row)
{
    if (row < 0 || row >= m_records->rowCount())
        row = -1;

    if (row == m_currentRow)
        return;

    m_currentRow = row;
    m_coordinates->setIcon(row >= 0 ? m_records->iconAt(row) : nullptr);
    emit currentRowChanged(row);
}
