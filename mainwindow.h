#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/**
 * \file mainwindow.h
 * \brief Главное окно приложения.
 */

class QGroupBox;
class QListView;
class QModelIndex;
class QTableView;
class IconListWidget;
class GraphicsCanvasView;
class IconDocument;


/**
 * \brief Главное окно: компоновка полей и связывание сигналов.
 *
 * Слева — графическая область фиксированного размера 1024x512, под ней список
 * созданных объектов и таблица координат; справа — каталог пиктограмм в
 * QGroupBox. Правила работы с данными живут в IconDocument, окно только
 * передаёт ему действия пользователя.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \brief Создаёт окно, собирает интерфейс и соединяет сигналы.
     * \param parent Родительский виджет.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    /**
     * \brief Показывает в строке состояния сообщение «clicked on icon».
     */
    void onIconActivated();

    /**
     * \brief Создаёт графический объект после перетаскивания иконки.
     * \param iconId Идентификатор перенесённой пиктограммы.
     */
    void onIconDropped(int iconId);

    /**
     * \brief Делает только что созданную строку текущей.
     * \param row Номер строки в списке объектов.
     */
    void onIconCreated(int row);

    /**
     * \brief Передаёт выбранную строку списка документу.
     * \param current Текущий индекс списка; недопустимый индекс снимает выбор.
     */
    void onRecordSelected(const QModelIndex &current);

private:
    /**
     * \brief Создаёт виджеты, задаёт фиксированные размеры и компоновку.
     */
    void setupUi();

    /**
     * \brief Соединяет сигналы представлений с документом.
     */
    void setupConnections();


    GraphicsCanvasView *m_canvasView;   //!< Графическая область.
    IconListWidget *m_iconList;         //!< Каталог пиктограмм.
    QGroupBox *m_controlsGroup;         //!< Контейнер каталога.
    QListView *m_recordsView;           //!< Список созданных объектов.
    QTableView *m_coordinatesView;      //!< Таблица координат.
    IconDocument *m_document;           //!< Документ с данными приложения.

};
#endif // MAINWINDOW_H
