#include "iconlistwidget.h"
#include "icontransfer.h"

#include <QDrag>
#include <QListWidgetItem>
#include <QPixmap>
#include <QSize>


const int ICON_SIZE = 48;

IconListWidget::IconListWidget(QWidget *parent)
    : QListWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setDefaultDropAction(Qt::CopyAction);

    connect(this, &QListWidget::itemClicked, this, [this](QListWidgetItem *) {
        emit iconActivated();
    });
}

void IconListWidget::addIcon(const QIcon &icon, const QString &text, int iconId)
{
    QListWidgetItem *item = new QListWidgetItem(icon, text, this);
    item->setData(IconIdRole, iconId);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
}

void IconListWidget::startDrag(Qt::DropActions supportedActions)
{
    QListWidgetItem *draggedItem = currentItem();
    if (draggedItem == nullptr || !(supportedActions & Qt::CopyAction))
        return;

    const int iconId = draggedItem->data(IconIdRole).toInt();

    QDrag dragObject(this);
    dragObject.setMimeData(createMimeData(iconId));

    const QPixmap preview = draggedItem->icon().pixmap(ICON_SIZE, ICON_SIZE);
    if (!preview.isNull())
    {
        dragObject.setPixmap(preview);
        dragObject.setHotSpot(QPoint(preview.width() / 2, preview.height() / 2));
    }

    emit iconActivated();
    dragObject.exec(Qt::CopyAction);
}
