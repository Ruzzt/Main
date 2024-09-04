/**
 *  @file kranModel.h
 *  @brief Заголовочный файл для класса kranModel.
 */
#ifndef KRANMODEL_H
#define KRANMODEL_H

#include <QAbstractTableModel>
#include "kranData.h"
/**
 * @class KranModel
 * @brief Класс для представления модели данных для объектов KranData.
 */
class KranModel : public QAbstractTableModel
{

    Q_OBJECT;
    KranData *Kran; /**< Указатель на объект класса KranData. */
    const int columnsNum; /**< Количество столбцов в модели. */
    bool edited;

public:
    /**
     * @brief Конструктор по умолчанию для KranModel.
     * @param parent Родительский объект.
     */
    explicit KranModel(QObject *parent = nullptr);
    /**
     * @brief Метод получения количества строк в модели.
     * @param parent Родительский индекс.
     * @return Количество строк.
    */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief Метод получения количества столбцов в модели.
     * @param parent Родительский индекс.
     * @return Количество столбцов.
    */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    /**
     * @brief Получить данные для определенной ячейки модели.
     * @param index Индекс ячейки.
     * @param role Роль данных.
     * @return Данные для ячейки.
    */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    /**
     * @brief Получить данные для заголовка столбца или строки.
     * @param section Номер строки или столбца.
     * @param orientation Ориентация заголовка.
     * @param role Роль данных.
     * @return Данные для заголовка.
    */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    /**
     * @brief Установить данные для определенной ячейки модели.
     * @param index Индекс ячейки.
     * @param value Новое значение для ячейки.
     * @param role Роль данных.
     * @return true, если успешно, false, если нет.
    */
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    /**
     * @brief Получить флаги для определенной ячейки модели.
     * @param index Индекс ячейки.
     * @return Флаги для ячейки.
    */
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    /**
     * @brief Деструктор класса KranModel.
    */
    ~KranModel();
    /**
     *  @brief Метод проверки файла на соотвествие типу, принимаемому программой. Метод вызывает checkFile из KranData, с добавлением некоторых комманд.
     *  @param fileName Имя файла.
     *  @return true, если проверка пройдена, false, если нет.
     */
    bool checkModel(QString fileName);
    /**
     *  @brief Метод чтения данных из файла. Метод вызывает readFromFile из KranData, с добавлением некоторых комманд.
     *  @param fileName Имя файла.
     */
    void readModel(QString fileName);
    /**
     *  @brief Метод записи данных в файл. Метод вызывает writeToFile из KranData, с добавлением некоторых комманд.
     *  @param fileName Имя файла.
     */
    void writeModel(QString fileName);
    /**
     *  @brief Метод добавления записи в список с данными. Метод вызывает addToTable из KranData, с добавлением некоторых комманд. Используется с диалоговым окном.
     */
    void addModel();
    /**
     *  @brief Метод редактирования элемента списка. Метод вызывает editEntry из KranData, с добавлением некоторых комманд. Используется с диалоговым окном.
     *  @param at Позиция элемента.
     */
    void editModel(int at);
    /**
     *  @brief Метод удаления элемента из списка. Метод вызывает deleteEntry из KranData, с добавлением некоторых комманд.
     *  @param at Позиция удаляемого элемента.
     */
    void deleteModel(int at);
    /**
     *  @brief Метод, полносью очищающий список с данными. Метод вызывает removeAll из KranData, с добавлением некоторых комманд.
     */
    void removeAllModel();
    /**
     *  @brief Геттер для поля класса KranModel edited.
     *  @return Переменная edited, показывающая был файл отредактирован или нет.
     */
    bool getedited();
    /**
     *  @brief Сеттер для поля класса KranModel edited.
     *  @param edited Переменная, показывающая был файл отредактирован или нет.
     */
    void setedited(bool edited);
    /**
     *  @brief Метод добавления записи в список с данными. Используется без диалогового окна.
     *  @param Kran Элемент списка, структура element.
     */
    void add(KranData::element Kran);

};

#endif // KRANMODEL_H
