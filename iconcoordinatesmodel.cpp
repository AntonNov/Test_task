#include "iconcoordinatesmodel.h"

#include <QPoint>
#include <QString>

#include "icongraphicsitem.h"


const char COLUMN_X[] = "x";
const char COLUMN_Y[] = "y";

IconCoordinatesModel::IconCoordinatesModel(QObject *parent)
    : QAbstractTableModel(parent)
    , m_icon(nullptr)
{
}

int IconCoordinatesModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || m_icon == nullptr)
        return 0;

    return RowCount;
}

int IconCoordinatesModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return ColumnCount;
}

QVariant IconCoordinatesModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || m_icon == nullptr)
        return QVariant();

    if (index.column() == NameColumn)
    {
        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return QString::fromLatin1(index.row() == XRow ? COLUMN_X : COLUMN_Y);
        default:
            return QVariant();
        }
    }

    if (index.column() == ValueColumn)
    {
        const QPoint topLeft = m_icon->topLeft();

        switch (role)
        {
        case Qt::DisplayRole:
        case Qt::EditRole:
            return index.row() == XRow ? topLeft.x() : topLeft.y();
        default:
            return QVariant();
        }
    }

    return QVariant();
}

Qt::ItemFlags IconCoordinatesModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags itemFlags = QAbstractTableModel::flags(index);

    if (m_icon != nullptr && index.isValid() && index.column() == ValueColumn)
        itemFlags |= Qt::ItemIsEditable;

    return itemFlags;
}

bool IconCoordinatesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (m_icon == nullptr || role != Qt::EditRole || !index.isValid() || index.column() != ValueColumn)
        return false;

    bool ok = false;
    const int newValue = value.toInt(&ok);
    if (!ok)
        return false;

    QPoint topLeft = m_icon->topLeft();
    if (index.row() == XRow)
        topLeft.setX(newValue);
    else
        topLeft.setY(newValue);

    m_icon->setTopLeft(topLeft);

    return true;
}

void IconCoordinatesModel::setIcon(IconGraphicsItem *icon)
{
    if (m_icon == icon)
        return;

    if (m_icon != nullptr)
        disconnect(m_icon, nullptr, this, nullptr);

    const bool wasEmpty = (m_icon == nullptr);
    const bool willBeEmpty = (icon == nullptr);

    if (wasEmpty != willBeEmpty)
        beginResetModel();

    m_icon = icon;

    if (m_icon != nullptr)
        connect(m_icon, &IconGraphicsItem::positionChanged,
                this, &IconCoordinatesModel::updatePosition);

    if (wasEmpty != willBeEmpty)
        endResetModel();
    else
        emit dataChanged(index(XRow, ValueColumn), index(YRow, ValueColumn));
}

IconGraphicsItem *IconCoordinatesModel::icon() const
{
    return m_icon;
}

void IconCoordinatesModel::updatePosition(const QPoint &)
{
    if (m_icon == nullptr)
        return;

    emit dataChanged(index(XRow, ValueColumn), index(YRow, ValueColumn));
}
