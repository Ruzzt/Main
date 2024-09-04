/**
 *  @file printpreview.cpp
 *  @brief Исходный код для класса PrintPreview.
 */
#include "printpreview.h"
#include "qprintdialog.h"
#include "qprinter.h"
#include "ui_printpreview.h"

PrintPreview::PrintPreview(QWidget *parent, QString *html) :
    QDialog(parent),
    ui(new Ui::PrintPreview)
{
    ui->setupUi(this);
    /// Передаем textBrowser строку с HTML-кодом.
    ui->textBrowser->setHtml(*html);
}

PrintPreview::~PrintPreview()
{
    delete ui;
}

void PrintPreview::on_buttonBox_accepted()
{
    /// Создаем экземпляр класса QPrinter.
    QPrinter printer;
    /// Создаем диалоговое окно печати.
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    /// Устанавливаем заголовок.
    dialog->setWindowTitle(tr("Print Document"));
    /// Если нажата кнопка "Ок",
    /// выполняем печать, если нет, выходим.
    if (dialog->exec() != QDialog::Accepted)
        return;
    ui->textBrowser->print(&printer);
}
