#include "iconlistwidget.h"

IconListWidget::IconListWidget(QWidget *parent)
    : QListWidget(parent)
{}

void IconListWidget::addIcon(const QIcon &icon, const QString &text, int iconId)
{
    QListWidgetItem *item = new QListWidgetItem(icon, text, this);
    item->setData(IconIdRole, iconId);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
}