#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QGroupBox;
class QListView;
class QModelIndex;
class QTableView;
class IconListWidget;
class GraphicsCanvasView;
class IconDocument;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
private slots:
    void onIconActivated();
    void onIconDropped(int iconId);
    void onIconCreated(int row);
    void onRecordSelected(const QModelIndex &current);

private:
    void setupUi();
    void setupConnections();


    GraphicsCanvasView *m_canvasView;
    IconListWidget *m_iconList;
    QGroupBox *m_controlsGroup;
    QListView *m_recordsView;
    QTableView *m_coordinatesView;
    IconDocument *m_document;

};
#endif // MAINWINDOW_H
