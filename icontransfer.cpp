#include "icontransfer.h"

#include <QByteArray>
#include <QMimeData>
#include <QString>


const char kIconMimeType[] = "application/x-qticon-catalog-item";

QString IconTransfer::mimeType()
{
    return QString::fromLatin1(kIconMimeType);
}

QMimeData *IconTransfer::createMimeData(int iconId)
{
    auto *mimeData = new QMimeData;
    mimeData->setData(kIconMimeType, QByteArray::number(iconId));
    return mimeData;
}

bool IconTransfer::canDecode(const QMimeData *mimeData)
{
    return mimeData != nullptr && mimeData->hasFormat(kIconMimeType);
}

int IconTransfer::decodeIconId(const QMimeData *mimeData)
{
    if (!canDecode(mimeData))
        return -1;

    bool ok = false;
    const int iconId = mimeData->data(kIconMimeType).toInt(&ok);
    return ok ? iconId : -1;
}
