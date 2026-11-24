#ifndef ICONCOORDINATESMODEL_H
#define ICONCOORDINATESMODEL_H

#include <QAbstractTableModel>
#include <QPoint>

class IconGraphicsItem;


class IconCoordinatesModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Column
    {
        NameColumn = 0,
        ValueColumn = 1,
        ColumnCount = 2
    };

    enum Row
    {
        XRow = 0,
        YRow = 1,
        RowCount = 2
    };

    explicit IconCoordinatesModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    void setIcon(IconGraphicsItem *icon);
    IconGraphicsItem *icon() const;

private slots:
    void updatePosition(const QPoint &topLeft);

private:
    IconGraphicsItem *m_icon;
};

#endif // ICONCOORDINATESMODEL_H
