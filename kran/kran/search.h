/**
 * @file search.h
 * @brief Заголовочный файл класса Search.
 */
#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}
/**
 * @class Search
 * @brief Класс диалогового окна упрощенного поиска.
 */
class Search : public QDialog
{
    Q_OBJECT

public:
    /**
     *  @brief Конструктор класса по умолчанию.
     *  @param parent Родительский объект.
     */
    explicit Search(QWidget *parent = nullptr);
    /**
     *  @brief Деструктор по умолчанию.
     */
    ~Search();
    /**
     *  @brief Геттер для результата.
     *  @return Результат, то что мы ввели в lineEdit.
     */
    QString getResult() const;

private slots:
    /**
     *  @brief Слот нажатия на кнопку "Ок".
     */
    void on_buttonBox_accepted();

private:
    Ui::Search *ui;
    QString result; /**< Результат считывания. */
};

#endif // SEARCH_H
