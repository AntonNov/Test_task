#ifndef COORDINATESPINBOXDELEGATE_H
#define COORDINATESPINBOXDELEGATE_H

#include <QStyledItemDelegate>


class CoordinateSpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit CoordinateSpinBoxDelegate(int maximumX, int maximumY, QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

private:
    int m_maximumX;
    int m_maximumY;
};

#endif // COORDINATESPINBOXDELEGATE_H
