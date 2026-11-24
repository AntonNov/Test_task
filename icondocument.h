#ifndef ICONDOCUMENT_H
#define ICONDOCUMENT_H

#include <QObject>

class QGraphicsScene;
class IconCoordinatesModel;
class IconGraphicsItem;
class IconRecordsModel;


class IconDocument : public QObject
{
    Q_OBJECT

public:

    explicit IconDocument(QGraphicsScene *scene, QObject *parent = nullptr);

    QGraphicsScene *scene() const { return m_scene; }

    IconRecordsModel *recordsModel() const { return m_records; }

    IconCoordinatesModel *coordinatesModel() const { return m_coordinates; }

    int currentRow() const { return m_currentRow; }

public slots:

    int createIcon(int iconId);

    void setCurrentRow(int row);

signals:

    void iconCreated(int row);


    void currentRowChanged(int row);

private:
    QGraphicsScene *m_scene;
    IconRecordsModel *m_records;
    IconCoordinatesModel *m_coordinates;
    int m_currentRow;
    qreal m_topZValue;

    Q_DISABLE_COPY(IconDocument)
};

#endif // ICONDOCUMENT_H
