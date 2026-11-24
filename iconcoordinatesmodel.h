#ifndef ICONCOORDINATESMODEL_H
#define ICONCOORDINATESMODEL_H

#include <QAbstractTableModel>
#include <QPoint>

/**
 * \file iconcoordinatesmodel.h
 * \brief Модель таблицы координат выбранного объекта.
 */

class IconGraphicsItem;


/**
 * \brief Таблица настроек «x» и «y» для одного графического объекта.
 *
 * Две строки (x и y) и два столбца: название настройки и её значение. Пока
 * объект не выбран, таблица пуста — так выполняется требование «по щелчку по
 * строке списка таблица появляется». Связь двусторонняя: правка ячейки
 * перемещает объект, а перемещение объекта мышью обновляет значения.
 */
class IconCoordinatesModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    /**
     * \brief Столбцы таблицы.
     */
    enum Column
    {
        NameColumn = 0,   //!< Название настройки («x» или «y»).
        ValueColumn = 1,  //!< Значение координаты.
        ColumnCount = 2
    };

    /**
     * \brief Строки таблицы.
     */
    enum Row
    {
        XRow = 0,  //!< Координата x.
        YRow = 1,  //!< Координата y.
        RowCount = 2
    };

    /**
     * \brief Создаёт пустую таблицу без выбранного объекта.
     * \param parent Родительский объект.
     */
    explicit IconCoordinatesModel(QObject *parent = nullptr);

    /**
     * \brief Возвращает количество строк таблицы.
     * \param parent Родительский индекс; для таблицы не используется.
     * \return RowCount, если объект выбран, иначе 0.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * \brief Возвращает количество столбцов таблицы.
     * \param parent Родительский индекс; для таблицы не используется.
     * \return ColumnCount.
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * \brief Возвращает название настройки или её значение.
     * \param index Индекс ячейки.
     * \param role Роль данных.
     * \return Значение для запрошенной роли.
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    /**
     * \brief Разрешает редактирование только ячеек значений.
     * \param index Индекс ячейки.
     * \return Флаги ячейки.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     * \brief Записывает новое значение координаты и перемещает объект.
     * \param index Индекс ячейки значения.
     * \param value Новое значение координаты.
     * \param role Роль данных; ожидается Qt::EditRole.
     * \return true, если значение принято.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    /**
     * \brief Назначает модели отображаемый объект.
     * \param icon Графический объект; nullptr очищает таблицу.
     */
    void setIcon(IconGraphicsItem *icon);

    /// \brief Возвращает текущий отображаемый объект.
    IconGraphicsItem *icon() const;

private slots:
    /**
     * \brief Обновляет значения таблицы после перемещения объекта.
     * \param topLeft Новые координаты верхнего левого угла.
     */
    void updatePosition(const QPoint &topLeft);

private:
    IconGraphicsItem *m_icon;  //!< Отображаемый объект (может быть nullptr).
};

#endif // ICONCOORDINATESMODEL_H
