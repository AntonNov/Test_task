#ifndef ICONDOCUMENT_H
#define ICONDOCUMENT_H

#include <QObject>

/**
 * \file icondocument.h
 * \brief Документ приложения: графические объекты и их координаты.
 */

class QGraphicsScene;
class IconCoordinatesModel;
class IconGraphicsItem;
class IconRecordsModel;


/**
 * \brief Управляет содержимым рабочей области и связывает модели.
 *
 * Класс не зависит от виджетов: создаёт графические объекты, наполняет
 * IconRecordsModel и назначает IconCoordinatesModel текущий объект. Поэтому
 * MainWindow остаётся слоем компоновки. Графическими объектами владеет сцена.
 */
class IconDocument : public QObject
{
    Q_OBJECT

public:

    /**
     * \brief Создаёт документ для указанной сцены.
     * \param scene Сцена рабочей области; не может быть nullptr.
     * \param parent Родительский объект.
     */
    explicit IconDocument(QGraphicsScene *scene, QObject *parent = nullptr);

    /**
     * \brief Возвращает сцену, которой принадлежат объекты документа.
     * \return Указатель на сцену.
     */
    QGraphicsScene *scene() const { return m_scene; }

    /**
     * \brief Возвращает модель списка созданных объектов.
     * \return Указатель на модель; владение остаётся у документа.
     */
    IconRecordsModel *recordsModel() const { return m_records; }

    /**
     * \brief Возвращает модель координат текущего объекта.
     * \return Указатель на модель; владение остаётся у документа.
     */
    IconCoordinatesModel *coordinatesModel() const { return m_coordinates; }

    /**
     * \brief Возвращает номер текущей строки списка.
     * \return Номер строки или -1, если объект не выбран.
     */
    int currentRow() const { return m_currentRow; }

public slots:

    /**
     * \brief Создаёт графический объект, строку в списке и выбирает его.
     *
     * По заданию объект всегда создаётся в точке (0, 0) размером 64x64 пикселя
     * и получает больший Z-порядок, чем предыдущие.
     *
     * \param iconId Идентификатор пиктограммы из каталога.
     * \return Номер созданной строки списка.
     */
    int createIcon(int iconId);

    /**
     * \brief Назначает текущую строку списка.
     * \param row Номер строки; отрицательное значение снимает выбор.
     */
    void setCurrentRow(int row);

signals:

    /**
     * \brief Сигнал о создании нового объекта.
     * \param row Номер добавленной строки списка.
     */
    void iconCreated(int row);


    /**
     * \brief Сигнал об изменении текущей строки.
     * \param row Номер строки или -1, если выбор снят.
     */
    void currentRowChanged(int row);

private:
    QGraphicsScene *m_scene;             //!< Сцена рабочей области.
    IconRecordsModel *m_records;         //!< Модель списка объектов.
    IconCoordinatesModel *m_coordinates; //!< Модель координат текущего объекта.
    int m_currentRow;                    //!< Текущая строка списка.
    qreal m_topZValue;                   //!< Z-порядок: новые объекты рисуются поверх.

    Q_DISABLE_COPY(IconDocument)
};

#endif // ICONDOCUMENT_H
