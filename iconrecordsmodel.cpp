#include "iconrecordsmodel.h"

#include <QString>

#include "icongraphicsitem.h"


const char RECORD_TITLE[] = "[icon]";

IconRecordsModel::IconRecordsModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int IconRecordsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_icons.size();
}

QVariant IconRecordsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_icons.size())
        return QVariant();

    const IconGraphicsItem *icon = m_icons.at(index.row());

    switch (role)
    {
    case Qt::DisplayRole:
        return QString::fromLatin1(RECORD_TITLE);

    case Qt::ToolTipRole:
        return QString("Координаты: x = %1, y = %2")
            .arg(icon->topLeft().x())
            .arg(icon->topLeft().y());

    case Qt::TextAlignmentRole:
        return static_cast<int>(Qt::AlignLeft | Qt::AlignVCenter);

    default:
        return QVariant();
    }
}

int IconRecordsModel::appendIcon(IconGraphicsItem *icon)
{
    const int row = m_icons.size();

    beginInsertRows(QModelIndex(), row, row);
    m_icons.append(icon);
    endInsertRows();

    return row;
}

IconGraphicsItem *IconRecordsModel::iconAt(int row) const
{
    if (row < 0 || row >= m_icons.size())
        return nullptr;

    return m_icons.at(row);
}

int IconRecordsModel::rowOf(const IconGraphicsItem *icon) const
{
    if (icon == nullptr)
        return -1;

    for (int row = 0; row < m_icons.size(); ++row)
    {
        if (m_icons.at(row) == icon)
            return row;
    }

    return -1;
}

void IconRecordsModel::notifyRowChanged(int row)
{
    if (row < 0 || row >= m_icons.size())
        return;

    const QModelIndex changedRow = index(row, 0);
    emit dataChanged(changedRow, changedRow, QVector<int>() << Qt::ToolTipRole);
}
