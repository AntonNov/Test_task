#ifndef ICONRECORDSMODEL_H
#define ICONRECORDSMODEL_H

#include <QAbstractListModel>
#include <QVector>

/**
 * \file iconrecordsmodel.h
 * \brief Модель списка созданных объектов.
 */

class IconGraphicsItem;


/**
 * \brief Список созданных объектов: одна строка — один графический объект.
 *
 * Модель хранит указатели на графические объекты и связывает строку списка с
 * объектом на сцене. Строки только добавляются, поэтому индексы строк
 * остаются стабильными на всё время работы приложения.
 */
class IconRecordsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    /**
     * \brief Создаёт пустую модель.
     * \param parent Родительский объект.
     */
    explicit IconRecordsModel(QObject *parent = nullptr);

    /**
     * \brief Возвращает количество созданных объектов.
     * \param parent Родительский индекс; для списка не используется.
     * \return Количество строк модели.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * \brief Возвращает подпись «[icon]» и подсказку с координатами.
     * \param index Индекс строки.
     * \param role Роль данных.
     * \return Значение для запрошенной роли.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * \brief Добавляет строку для нового графического объекта.
     * \param icon Графический объект; модель не владеет им.
     * \return Номер добавленной строки.
     */
    int appendIcon(IconGraphicsItem *icon);

    /**
     * \brief Возвращает объект, связанный со строкой.
     * \param row Номер строки.
     * \return Указатель на объект или nullptr, если строки нет.
     */
    IconGraphicsItem *iconAt(int row) const;

    /**
     * \brief Ищет строку, связанную с объектом.
     * \param icon Графический объект.
     * \return Номер строки или -1, если объекта в модели нет.
     */
    int rowOf(const IconGraphicsItem *icon) const;

    /**
     * \brief Уведомляет представления об изменении строки.
     * \param row Номер изменившейся строки.
     */
    void notifyRowChanged(int row);

private:
    QVector<IconGraphicsItem *> m_icons;  //!< Графические объекты в порядке создания.
};

#endif // ICONRECORDSMODEL_H
