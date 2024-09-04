/**
 * @file printpreview.h
 * @brief Заголовочный файл класса PrintPreview.
 */
#ifndef PRINTPREVIEW_H
#define PRINTPREVIEW_H

#include <QDialog>

namespace Ui {
class PrintPreview;
}
/**
 * @class PrintPreview
 * @brief Класс виджета с предпросмотром печати.
 */
class PrintPreview : public QDialog
{
    Q_OBJECT

public:
    /**
     *  @brief Конструктор класса.
     *  @param parent Родительский объект.
     *  @param html Строка с html кодом.
     */
    explicit PrintPreview(QWidget *parent = nullptr, QString *html = nullptr);
    /**
     *  @brief Деструктор по умолчанию.
     */
    ~PrintPreview();

private slots:
    /**
     *  @brief Слот нажатия на кнопку "Ок".
     */
    void on_buttonBox_accepted();

private:

    Ui::PrintPreview *ui;

};

#endif // PRINTPREVIEW_H
