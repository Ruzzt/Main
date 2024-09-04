/**
 *  @file editdialog.h
 *  @brief Заголовочный файл для класса EditDialog.
 */
#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

#include "kranData.h"

namespace Ui {
class EditDialog;
}
/**
 * @class EditDialog
 * @brief Класс диалогового окна редактирования записи.
 */
class EditDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     *  @brief Конструктор класса EditDialog по умолчанию.
     *  @param parent Родительский объект.
     */
    explicit EditDialog(QWidget *parent = nullptr);
    /**
     *  @brief Конструктор класса EditDialog.
     *  @param parent Родительский объект.
     *  @param KranData::element Запись, которую будем редактировать.
     */
    explicit EditDialog(KranData::element KranTemp, QWidget *parent = nullptr);
    /**
     *  @brief Геттер для редактируемой структуры.
     *  @return Структура KranData::element;
     */
    KranData::element getKran();
    /**
     *  @brief Деструктор по умолчанию.
     */
    ~EditDialog();

private slots:
    /**
     *  @brief Слот нажатия на кнопку "Ок".
     */
    void on_buttonBox_accepted();

private:
    Ui::EditDialog *ui;
    KranData::element Kran; /**< Структура, в которую будут помещены текущие данные. */
};

#endif // EDITDIALOG_H
