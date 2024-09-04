/**
 *  @file search.cpp
 *  @brief Исходный код для класса Search.
 */
#include "search.h"
#include "ui_search.h"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    /// Конструктор по умолчанию.
    ui->setupUi(this);
}

Search::~Search()
{
    /// Деструктор по умолчанию.
    delete ui;
}

QString Search::getResult() const
{
    /// Возвращаем результат.
    return result;
}

void Search::on_buttonBox_accepted()
{
    /// Присваиваем результату значение из lineEdit.
    result = ui->lineEdit_Search->text();
}
