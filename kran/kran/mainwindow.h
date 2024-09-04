/**
 * @file mainwindow.h
 * @brief Заголовочный файл класса главного окна приложения.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QMetaType>
#include <QRegularExpression>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>
#include <QTranslator>
#include <mutex>

#include "kranModel.h"
#include "mysortproxymodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class QActionGroup;
/**
 * @class MainWindow
 * @brief Класс главного окна приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     *  @brief Конструктор класса MainWindow по умолчанию.
     *  @param parent Родительский объект.
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     *  @brief Деструктор по умолчанию.
     */
    ~MainWindow();

private slots:
    /**
     * @brief Слот, вызываемый при выборе пункта меню для переключения языка
     * @param action Указатель на выбранный пункт меню
     */
    void switchLanguage(QAction *action);
    /**
     * @brief Слот, вызываемый при выборе пункта "О Qt" в меню About.
     */
    void on_actionAbout_Qt_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "О Программе" в меню About.
     */
    void on_actionAbout_App_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Выход" в меню файла.
     */
    void on_actionExit_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Открыть" в меню файла.
     */
    void on_actionOpen_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Сохранить" в меню файла.
     */
    void on_actionSave_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Новый файл" в меню файла.
     */
    void on_actionNew_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Закрыть" в меню файла.
     */
    void on_actionClose_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Редактировать" в меню "Edit".
     */
    void on_actionEdit_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Добавить запись" в меню "Edit".
     */
    void on_actionAdd_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Удалить запись" в меню "Edit".
     */
    void on_actionDelete_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Простой" в меню "Search".
     */
    void on_actionSearch_2_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Новое окно" в меню файла.
     */
    void on_actionNew_Window_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "Печать" в меню файла.
     */
    void on_actionPrint_triggered();
    /**
     * @brief Слот, вызываемый при выборе пункта "График" в меню файла.
     */
    void on_actionChart_triggered();
    /**
     * @brief Слот, вызываемый при изменении значения в "lineEdit" фильтра.
     */
    void textFilterChanged();

private:
    Ui::MainWindow *ui;
    /**
     * @brief Метод, применяющий сохраненные настройки интерфейса.
     */
    void readSettings();
    /**
     * @brief Метод, запоминающий текущие настройки интерфейса.
     */
    void writeSettings();
    /**
     * @brief Метод, отвечающий за появление диалогового окна о сохранении файла перед закрытием.
     */
    void SaveBefore();
    /**
     * @brief Метод, вызываемый перед закрытием программы.
     */
    void closeEvent(QCloseEvent *event);
    /**
     * @brief Метод, выполняющийся при вызове контекстного меню.
     */
    void contextMenuEvent(QContextMenuEvent *event);
    /**
     * @brief Метод, отвечающий за создание языкового меню.
     */
    void createLanguageMenu();

    QString fileName; /**< Имя(путь) файла. */
    const QString FileFilter = "Database files (*.db);;All files (*)";
    KranModel *Model;             /**< Указатель на объект модели. */
    MySortProxyModel *proxyModel; /**< Указатель на объект пользовтаельской прокси-модели. */
    QMenu *ContextMenuEdit;
    QMenu *ContextMenuFile;
    QTranslator appTranslator; /**< Объект, управляющий переводом слов из приложения. */
    QTranslator qtTranslator; /**< Объект, управляющий переводом слов из стандартных сообщений Qt. */
    QActionGroup *languageActionGroup; /**< Список доступных переводов будет тут. */
    QAction *checkedAction;
    QString qmPath;         /**< Путь к файлам .qm. */
    QString locale;         /**< Выбранная локаль. */

    QList<QString> NamessList; /**< Список c названиями кампаний. */
    QList<int> WeightList; /**< Список с максмальной грузоподъёмностью. */

protected:
    /**
     * @brief Метод, вызываемый при входе объекта DragNDrop в виджет.
     * @param e Событие, отправляемое виджету при вхождении действия DragNDrop в него.
     */
    virtual void dragEnterEvent(QDragEnterEvent *e);
    /**
     * @brief Метод, вызываемый при выходе объекта DragNDrop из виджета.
     * @param e Событие, отправляемое виджету при выходе действия DragNDrop из него.
     */
    virtual void dragLeaveEvent(QDragLeaveEvent *e);
    /**
     * @brief Метод, вызываемый при совершении действия DragNDrop.
     * @param e Событие, отправляемое виджету при совершении действия DragNDrop.
     */
    virtual void dropEvent(QDropEvent *e);
};
#endif // MAINWINDOW_H
