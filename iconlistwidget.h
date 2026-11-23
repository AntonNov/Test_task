#ifndef ICONLISTWIDGET_H
#define ICONLISTWIDGET_H

#include <QListWidget>

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

};

#endif // ICONLISTWIDGET_H
