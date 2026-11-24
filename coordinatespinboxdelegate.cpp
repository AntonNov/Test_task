#include "coordinatespinboxdelegate.h"

#include <QModelIndex>
#include <QSpinBox>
#include <QStyleOptionViewItem>

#include "iconcoordinatesmodel.h"


CoordinateSpinBoxDelegate::CoordinateSpinBoxDelegate(int maximumX, int maximumY, QObject *parent)
    : QStyledItemDelegate(parent)
    , m_maximumX(qMax(0, maximumX))
    , m_maximumY(qMax(0, maximumY))
{
}

QWidget *CoordinateSpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &,
                                                 const QModelIndex &index) const
{
    QSpinBox *spinBox = new QSpinBox(parent);
    spinBox->setFrame(false);
    spinBox->setKeyboardTracking(false);
    spinBox->setRange(0, index.row() == IconCoordinatesModel::XRow ? m_maximumX : m_maximumY);

    return spinBox;
}

void CoordinateSpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);
    if (spinBox == nullptr)
        return;

    spinBox->setValue(index.data(Qt::EditRole).toInt());
    spinBox->selectAll();
}

void CoordinateSpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                             const QModelIndex &index) const
{
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(editor);
    if (spinBox == nullptr || model == nullptr)
        return;

    spinBox->interpretText();
    model->setData(index, spinBox->value(), Qt::EditRole);
}

void CoordinateSpinBoxDelegate::updateEditorGeometry(QWidget *editor,
                                                     const QStyleOptionViewItem &option,
                                                     const QModelIndex &) const
{
    editor->setGeometry(option.rect);
}
