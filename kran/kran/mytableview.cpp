/**
 *  @file mytableview.cpp
 *  @brief Исходный код для класса MyTableView.
 */
#include "mytableview.h"

void MyTableView::mousePressEvent(QMouseEvent *event)
{
    /// Выделяем строку при нажатии левой кнопкой мыши.
    if (event->button() == Qt::LeftButton) {
        this->selectRow(this->indexAt(event->pos()).row());
    }
    /// Сохраняем индекс.
    index = this->indexAt(event->pos());
}

void MyTableView::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    /// Если индекс валидный и данные существуют.
    if(index.isValid() && !index.data().isNull()) {

        M = model();
        /// Получаем количество строк и выбранную строку.
        entries = model()->rowCount();
        row = this->currentIndex().row();
        /// Строка с переносом строки.
        QString newstr = "\r\n";

        /// Проходим по всем строкам.
        for (int i = 0; i < entries; i++)
            /// Если найдена нужная строка,
            if (i == row)
                /// Записываем данные в строку с разделителем.
                res =
                    M->data(M->index(i, 0)).toString() + ";"
                    + M->data(M->index(i, 1)).toString() + ";"
                    + M->data(M->index(i, 2)).toString() + ";"
                    + M->data(M->index(i, 3)).toString() + ";"
                    + M->data(M->index(i, 4)).toString() + ";"
                    + M->data(M->index(i, 5)).toString() + ";"
                    + M->data(M->index(i, 6)).toString() + ";"
                    + M->data(M->index(i, 7)).toString() + ";";
        /// Если MIME-тип - текст, добавляем перенос строки.
        if(!currentMimeType.contains("Qt") && currentMimeType != "")
            res += newstr;
        QMimeData *mimeData = new QMimeData();
        QDrag *drag = new QDrag(this);
        QByteArray array = QByteArray::fromBase64((res.toUtf8()).toBase64());
        /// Если переносим в приложение,
        /// устанавливаем тип "app".
        if(currentMimeType.contains("Qt")) {
            mimeData->setData("app", array);
            mimeData->setText(res);
            mimeData->setParent(this);
        }
        /// Если переносим в текстовый редактор,
        /// устанавливаем тип "text".
        else if(currentMimeType != "") {
            mimeData->setData("text", array);
            mimeData->setText(res);
            mimeData->setParent(this);
        }

        drag->setMimeData(mimeData);
        /// Если переносим текст,
        /// запускаем объект класса QDrag
        /// с аргументом CopyAction,
        /// иначе без аргумента.
        if(currentMimeType.contains("Qt"))
            drag->exec();
        else if(currentMimeType != "")
            drag->exec(Qt::CopyAction);

        return;
    }
}

MyTableView::MyTableView(QWidget *parent) : QTableView(parent)
{
    this->acceptDrops();
}

QString MyTableView::setMimeType(const QString &newMimeType)
{
    /// Возвращаем новый тип MIME.
    return currentMimeType = newMimeType;
}
