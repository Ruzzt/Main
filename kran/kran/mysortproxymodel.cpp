/**
 *  @file mysortproxymodel.cpp
 *  @brief Исходный код для класса MySortProxyModel.
 */
#include "mysortproxymodel.h"

QStringList MySortProxyModel::syntaxes() const
{
    /// Формируем список строк,
    /// добавляем необходимые значения,
    /// возвращаем его.
    QStringList syntaxes;
    syntaxes << tr("Regular Expression")
             << tr("Wildcard");
    // << tr("Fixed String");
    return syntaxes;
}

QStringList MySortProxyModel::columns() const
{
    /// Формируем список строк,
    /// добавляем необходимые значения,
    /// возвращаем его.
    QStringList columns;
    columns << tr("ID")
            << tr("Name")
            << tr("Address")
            << tr("Maxweight")
            << tr("Rating")
            << tr("People")
            << tr("ContactNumber")
            << tr("Years");
    return columns;
}

bool MySortProxyModel::hasSyntax(const QString &syntax) const
{
    /// Возвращаем результат проверки.
    return currentSyntax == syntax;
}

bool MySortProxyModel::hasColumn(const QString &column) const
{
    /// Возвращаем результат проверки.
    return currentColumn == column;
}

MySortProxyModel::MySortProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    /// Пустой конструктор.
}


bool MySortProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    /// Во-первых,
    /// получаем индекс текущего столбца.
    QStringList s;
    s = columns();
    int column = 0;
    for (int i = 0; i < s.count(); i++)
        if (currentColumn == s[i])
            column = i;
    QModelIndex index0;
    QModelIndex indexdate1;
    QModelIndex indexdate2;
    QString index0data;
    QString indexdatedata1;
    QString indexdatedata2;
    /// Далее находим индексы,
    /// отдельно для фильтра через lineEdit,
    /// второй для фильтра с помощью двух dateEdit.
    index0 = sourceModel()->index(sourceRow, column, sourceParent);
    /// Случай если НЕ дата.
    index0data = sourceModel()->data(index0).toString();
    indexdatedata1 = sourceModel()->data(indexdate1).toString();
    indexdatedata2 = sourceModel()->data(indexdate2).toString();
    /// Если синтаксис - Wildcard,
    /// ставим полное соотвествие, для более корректной работы масок.
    /// Если другой - проверяем на наличие.
    if(!hasSyntax(tr("Wildcard")))
        return (index0data.contains(filterRegularExpression()));
    else
        return (filterRegularExpression().match(index0data).hasMatch());
}

QString MySortProxyModel::setsyntax(const QString &newSyntax)
{
    /// Возвращаем новое значение текущего синтаксиса.
    return currentSyntax = newSyntax;
}

QString MySortProxyModel::setcolumn(const QString &newColumn)
{
    /// Возвращаем новое значение текущего столбца.
    return currentColumn = newColumn;
}
