/**
 *  @file editdialog.cpp
 *  @brief Исходный код для класса EditDialog.
 */
#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog)
{
    /// Стандартный конструктор, без изменений
    ui->setupUi(this);
}

EditDialog::EditDialog(KranData::element KranTemp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog),
    /// Инициализируем объект Kran аргументом KranTemp.
    Kran(KranTemp)
{
    ui->setupUi(this);
    /// Заполняем поля диалогового окна данными выбранной строки.
    ui->iDSpinBox->setValue(KranTemp.ID);
    ui->nameLineEdit->setText(KranTemp.Name);
    ui->addressLineEdit->setText(KranTemp.Address);
    ui->maxweightSpinBox->setValue(KranTemp.Maxweight);
    ui->ratingSpinBox->setValue(KranTemp.Rating);
    ui->peopleSpinBox->setValue(KranTemp.People);
    ui->contactNumberLineEdit->setText(KranTemp.ContactNumber);
    ui->yearsSpinBox->setValue(KranTemp.Years);
}

KranData::element EditDialog::getKran()
{
    /// Возвращаем объект Kran.
    return Kran;
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_buttonBox_accepted()
{
    /// При нажатии на кнопку "Ок",
    /// Заполняем объект Kran
    /// данными из полей диалогового окна.
    Kran = {
        ui->iDSpinBox->value(),
        ui->nameLineEdit->text(),
        ui->addressLineEdit->text(),
        ui->maxweightSpinBox->value(),
        ui->ratingSpinBox->value(),
        ui->peopleSpinBox->value(),
        ui->contactNumberLineEdit->text(),
        ui->yearsSpinBox->value()
    };
}
