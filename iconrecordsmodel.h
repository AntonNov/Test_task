#ifndef ICONRECORDSMODEL_H
#define ICONRECORDSMODEL_H

#include <QAbstractListModel>
#include <QVector>

class IconGraphicsItem;


class IconRecordsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit IconRecordsModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int appendIcon(IconGraphicsItem *icon);
    IconGraphicsItem *iconAt(int row) const;
    int rowOf(const IconGraphicsItem *icon) const;
    void notifyRowChanged(int row);

private:
    QVector<IconGraphicsItem *> m_icons;
};

#endif // ICONRECORDSMODEL_H
