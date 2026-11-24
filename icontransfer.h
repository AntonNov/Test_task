#ifndef ICONTRANSFER_H
#define ICONTRANSFER_H

class QByteArray;
class QMimeData;
class QString;

namespace IconTransfer{
    QString mimeType();
    QMimeData *createMimeData(int iconId);
    bool canDecode(const QMimeData *mimeData);
    int decodeIconId(const QMimeData *mimeData);
}
#endif // ICONTRANSFER_H
