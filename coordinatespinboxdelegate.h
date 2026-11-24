#ifndef COORDINATESPINBOXDELEGATE_H
#define COORDINATESPINBOXDELEGATE_H

#include <QStyledItemDelegate>

/**
 * \file coordinatespinboxdelegate.h
 * \brief Редактор значений координат в таблице.
 */

/**
 * \brief Делегат, который редактирует координату счётчиком QSpinBox.
 *
 * Счётчик не даёт ввести буквы и отрицательные числа, а диапазон ограничен
 * размерами сцены: 0…960 для x и 0…448 для y.
 */
class CoordinateSpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    /**
     * \brief Создаёт делегат с заданными пределами значений.
     * \param maximumX Наибольшая допустимая координата x.
     * \param maximumY Наибольшая допустимая координата y.
     * \param parent Родительский объект.
     */
    explicit CoordinateSpinBoxDelegate(int maximumX, int maximumY, QObject *parent = nullptr);

    /**
     * \brief Создаёт счётчик для ячейки значения.
     * \param parent Родительский виджет редактора.
     * \param option Параметры отрисовки ячейки.
     * \param index Индекс редактируемой ячейки.
     * \return Готовый редактор.
     */
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /**
     * \brief Переносит текущее значение из модели в счётчик.
     * \param editor Редактор ячейки.
     * \param index Индекс редактируемой ячейки.
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    /**
     * \brief Записывает значение счётчика обратно в модель.
     * \param editor Редактор ячейки.
     * \param model Модель таблицы.
     * \param index Индекс редактируемой ячейки.
     */
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    /**
     * \brief Растягивает редактор на всю ячейку.
     * \param editor Редактор ячейки.
     * \param option Параметры отрисовки ячейки.
     * \param index Индекс редактируемой ячейки.
     */
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;

private:
    int m_maximumX;  //!< Верхняя граница координаты x.
    int m_maximumY;  //!< Верхняя граница координаты y.
};

#endif // COORDINATESPINBOXDELEGATE_H
