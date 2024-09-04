/**
 * @file mytableview.h
 * @brief Заголовочный файл класса MyTableView.
 */
#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QtWidgets>
#include <QObject>
/**
 * @class MyTableView
 * @brief Класс пользовательского tableView.
 */
class MyTableView : public QTableView
{

    QAbstractItemModel *M; /**< Указатель на QAbstractItemModel. */
    QModelIndex index;
    QString currentMimeType; /**< Текущий режим DragNDrop. */
    QString res; /**< Результат считывания строки. */
    int entries; /**< Кол-во строк. */
    int row; /**< Выбранная строка. */

private slots:
    /**
     * @brief Слот, вызываемый при нажатии кнопки мыши.
     * @param event Событие, происходящее при нажатии кнопки.
     */
    virtual void mousePressEvent(QMouseEvent *event);
    /**
     * @brief Слот, вызываемый при перемещении кнопки мыши.
     * @param event Событие, происходящее при нажатии кнопки.
     */
    virtual void mouseMoveEvent(QMouseEvent *event);

public:
    /**
     *  @brief Конструктор класса по умолчанию.
     *  @param parent Родительский объект.
     */
    MyTableView(QWidget *parent = nullptr);

public slots:
    /**
     * @brief Сеттер для режима DragNDrop.
     * @param newMimeType Присваиваемый режим.
     * @return Текущий режим после присвоения.
     */
    QString setMimeType(const QString &newMimeType);

};

#endif // MYTABLEVIEW_H
