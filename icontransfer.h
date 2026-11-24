#ifndef ICONTRANSFER_H
#define ICONTRANSFER_H

class QMimeData;
class QString;


QString mimeType();
QMimeData *createMimeData(int iconId);
bool canDecode(const QMimeData *mimeData);
int decodeIconId(const QMimeData *mimeData);

#endif // ICONTRANSFER_H
