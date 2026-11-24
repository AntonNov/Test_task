#ifndef ICONRECORDSMODEL_H
#define ICONRECORDSMODEL_H

#include <QAbstractListModel>
#include <QVector>

class IconGraphicsItem;

/**
 * \file IconRecordsModel.h
 * \brief Модель данных для поля (3) — списка созданных объектов.
 */

/**
 * \class IconRecordsModel
 * \brief Список созданных объектов: одна строка списка — один объект поля (2).
 *
 * Модель хранит указатели на графические объекты и служит связующим звеном
 * между строкой списка и объектом на сцене. Строки только добавляются
 * (удаление в задании не предусмотрено), поэтому индексы строк остаются
 * стабильными на всё время работы приложения.
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

    /// \note Переопределяет \c QAbstractListModel::rowCount().
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /// \brief Возвращает подпись «[icon]» и подсказку с текущими координатами.
    /// \note Переопределяет \c QAbstractListModel::data().
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * \brief Добавляет строку для нового графического объекта.
     * \param icon Объект, созданный в поле (2). Модель не владеет им.
     * \return Индекс добавленной строки.
     */
    int appendIcon(IconGraphicsItem *icon);

    /**
     * \brief Возвращает объект, связанный со строкой.
     * \param row Номер строки.
     * \return Указатель на объект или nullptr, если строка не существует.
     */
    IconGraphicsItem *iconAt(int row) const;

    /**
     * \brief Ищет строку, связанную с объектом.
     * \param icon Объект поля (2).
     * \return Номер строки или -1, если объект в модели отсутствует.
     */
    int rowOf(const IconGraphicsItem *icon) const;

    /**
     * \brief Уведомляет представления об изменении данных строки.
     * \param row Номер строки.
     */
    void notifyRowChanged(int row);

private:
    QVector<IconGraphicsItem *> m_icons; //!< Объекты поля (2) в порядке создания.
    };

#endif // ICONRECORDSMODEL_H
