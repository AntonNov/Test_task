#include "icontransfer.h"

#include <QByteArray>
#include <QMimeData>
#include <QString>


const char ICON_MIME_TYPE[] = "application/x-qticon-catalog-item";

QString mimeType()
{
    return QString::fromLatin1(ICON_MIME_TYPE);
}

QMimeData *createMimeData(int iconId)
{
    QMimeData *mimeData = new QMimeData;
    mimeData->setData(ICON_MIME_TYPE, QByteArray::number(iconId));
    return mimeData;
}

bool canDecode(const QMimeData *mimeData)
{
    return mimeData != nullptr && mimeData->hasFormat(ICON_MIME_TYPE);
}

int decodeIconId(const QMimeData *mimeData)
{
    if (!canDecode(mimeData))
        return -1;

    bool ok = false;
    const int iconId = mimeData->data(ICON_MIME_TYPE).toInt(&ok);
    return ok ? iconId : -1;
}
