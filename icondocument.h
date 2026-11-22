#ifndef ICONDOCUMENT_H
#define ICONDOCUMENT_H

#include <QObject>

class IconDocument : public QObject
{
    Q_OBJECT
public:
    explicit IconDocument(QObject *parent = nullptr);

signals:
};

#endif // ICONDOCUMENT_H
