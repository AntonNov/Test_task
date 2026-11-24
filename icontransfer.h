#ifndef ICONTRANSFER_H
#define ICONTRANSFER_H

/**
 * \file icontransfer.h
 * \brief MIME-протокол переноса пиктограммы из каталога в графическую область.
 */

class QMimeData;
class QString;


/**
 * \brief Возвращает MIME-тип, которым помечаются перетаскиваемые пиктограммы.
 * \return Строка MIME-типа.
 */
QString mimeType();

/**
 * \brief Формирует MIME-данные с идентификатором пиктограммы.
 * \param iconId Идентификатор пиктограммы каталога.
 * \return Новый объект QMimeData; владение переходит вызывающей стороне.
 */
QMimeData *createMimeData(int iconId);

/**
 * \brief Проверяет, что данные переноса созданы каталогом пиктограмм.
 * \param mimeData Данные переноса; допускается nullptr.
 * \return true, если данные содержат корректный идентификатор.
 */
bool canDecode(const QMimeData *mimeData);

/**
 * \brief Извлекает идентификатор пиктограммы из данных переноса.
 * \param mimeData Данные переноса; допускается nullptr.
 * \return Идентификатор пиктограммы или -1, если данные некорректны.
 */
int decodeIconId(const QMimeData *mimeData);

#endif // ICONTRANSFER_H
