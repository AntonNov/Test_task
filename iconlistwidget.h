#ifndef ICONLISTWIDGET_H
#define ICONLISTWIDGET_H

#include <QListWidget>
#include <QDrag>
#include <QListWidgetItem>
#include <QPixmap>
#include <QSize>

/**
 * \file iconlistwidget.h
 * \brief Каталог пиктограмм, которые перетаскивают в графическую область.
 */

/**
 * \brief Перегруженный QListWidget — источник перетаскивания.
 *
 * Вместо стандартных данных item-view формирует собственные MIME-данные
 * (см. icontransfer.h), понятные графической сцене.
 */
class IconListWidget : public QListWidget
{
    Q_OBJECT
public:
    /**
     * \brief Создаёт каталог, который умеет только перетаскивать элементы.
     * \param parent Родительский виджет.
     */
    IconListWidget(QWidget *parent = nullptr);

    /**
     * \brief Добавляет пиктограмму в каталог.
     * \param icon Изображение элемента списка.
     * \param text Подпись элемента.
     * \param iconId Идентификатор пиктограммы для протокола переноса.
     */
    void addIcon(const QIcon &icon, const QString &text, int iconId);

    /**
     * \brief Роли элемента списка.
     */
    enum ItemRole
    {
        IconIdRole = Qt::UserRole + 1  //!< Идентификатор пиктограммы в каталоге.
    };

    /**
     * \brief Формирует MIME-данные и запускает цикл перетаскивания.
     * \param supportedActions Действия, разрешённые представлением.
     */
    void startDrag(Qt::DropActions supportedActions) override;

signals:
    /**
     * \brief Сигнал об обращении к пиктограмме: щелчок или начало переноса.
     */
    void iconActivated();
};

#endif // ICONLISTWIDGET_H
