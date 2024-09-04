/**
 * @file mysortproxymodel.h
 * @brief Заголовочный файл класса MySortProxyModel.
 */
#ifndef MYSORTPROXYMODEL_H
#define MYSORTPROXYMODEL_H

#include <QDate>
#include <QSortFilterProxyModel>
/**
 * @class MySortProxyModel
 * @brief Класс пользовательской прокси-модели.
 */
class MySortProxyModel : public QSortFilterProxyModel
{

    Q_OBJECT
    QString currentSyntax;
    QString currentColumn;
    /**
     * @brief Метод, проверяющий синтаксис на соответствие.
     * @param syntax Сравниваем этот аргумент с текущим синтаксисом.
     * @return true, если соответствует, false, если нет.
     */
    bool hasSyntax(const QString &syntax) const;
    /**
     * @brief Метод, проверяющий столбец на соответствие.
     * @param column Сравниваем этот аргумент с текущим столбцом.
     * @return true, если соответствует, false, если нет.
     */
    bool hasColumn(const QString &column) const;
    /**
     * @brief Метод, определяющий все синтаксисы.
     * @return Список синтаксисов.
     */
    QStringList syntaxes() const;
    /**
     * @brief Метод, определяющий все столбцы.
     * @return Список столбцов.
     */
    QStringList columns() const;

public:
    /**
     *  @brief Конструктор класса по умолчанию.
     *  @param parent Родительский объект.
     */
    MySortProxyModel(QObject *parent = 0);

    /**
     * @brief Геттер для minDate.
     * @return Нижний порог даты.
     */


protected:
    /**
     * @brief Метод, определяющий функционирование фильтра.
     * @param sourceRow Номер строки.
     * @param sourceParent Родительский индекс.
     * @return true, если строка подходит, false, если нет.
     */
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;

private:


public slots:
    /**
     * @brief Сеттер для синтаксиса.
     * @param newSyntax Присваиваемый синтаксис.
     * @return Текущий синтаксис после присвоения.
     */
    QString setsyntax(const QString &newSyntax);
    /**
     * @brief Сеттер для столбца.
     * @param newColumn Присваиваемый столбец.
     * @return Текущий столбец после присвоения.
     */
    QString setcolumn(const QString &newColumn);

};


#endif // MYSORTPROXYMODEL_H
