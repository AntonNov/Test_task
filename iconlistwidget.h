#ifndef ICONLISTWIDGET_H
#define ICONLISTWIDGET_H

#include <QListWidget>
#include <QDrag>
#include <QListWidgetItem>
#include <QPixmap>
#include <QSize>

class IconListWidget : public QListWidget
{
    Q_OBJECT
public:
    IconListWidget(QWidget *parent = nullptr);
    void addIcon(const QIcon &icon, const QString &text, int iconId);
    enum ItemRole
    {
        IconIdRole = Qt::UserRole + 1
    };
    void startDrag(Qt::DropActions supportedActions) override;
signals:
    void iconActivated();
};

#endif // ICONLISTWIDGET_H
