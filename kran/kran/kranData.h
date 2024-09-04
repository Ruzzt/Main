/**
 *  @file kranData.h
 *  @brief Заголовочный файл для класса KranData.
 */
#ifndef KRANDATA_H
#define KRANDATA_H

#include <QString>
#include <QDate>
/**
 * @class KranData
 * @brief Класс для представления отделочных материалов.
 */
class KranData
{
public:
    /**
     *  @brief Структура, описывающая одну запись файла.
     */
    struct element
    {
        int ID; /**< ID объекта kranlass */
        QString Name;/**< Название объекта kranlass  */
        QString Address;/**< Адрес объекта kranlass */
        int Maxweight;/**< Максимальная грузоподъёмность объекта kranlass */
        float Rating;/**< Рейтинг объекта kranlass */
        int People;/**< Количество сотрудников объекта kranlass */
        QString ContactNumber;/**< Контактный номер объекта kranlass */
        int Years;/**< Количество лет объекта kranlass */
    };

    /**
     *  @brief Конструктор по умолчанию для KranData.
     */
    KranData();
    /**
     *  @brief Метод проверки файла на соотвествие типу, принимаемому программой.
     *  @param fileName Имя файла.
     *  @return true, если проверка пройдена, false, если нет.
     */
    bool checkFile(QString fileName);
    /**
     *  @brief Метод чтения данных из файла.
     *  @param fileName Имя файла.
     */
    void readFromFile(QString fileName);
    /**
     *  @brief Метод записи данных в файл.
     *  @param fileName Имя файла.
     */
    void writeToFile(QString fileName);
    /**
     *  @brief Метод добавления записи в список с данными.
     *  @param Kran Элемент списка.
     */
    void addToTable(element Kran);
    /**
     *  @brief Метод редактирования элемента списка.
     *  @param i Позиция элемента.
     *  @param Kran Элемент, на который меняем существующий на позиции i.
     */
    void editEntry(int i, element Kran);
    /**
     *  @brief Метод удаления элемента из списка.
     *  @param i Позиция удаляемого элемента.
     */
    void deleteEntry(int i);
    /**
     *  @brief Метод, возвращающий элемент списка на позиции i.
     *  @param i Позиция элемента в списке.
     *  @return Элемент позиции i.
     */
    element get(int i);
    /**
     *  @brief Метод, возвращающий количество строк, или же элементов списка.
     *  @return Количество элементов списка.
     */
    int rowsCount();
    /**
     *  @brief Метод, полносью очищающий список с данными.
     */
    void removeAll();
    /**
     *  @brief Сеттер для id  определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение id.
     */
    void setid(int pos, int temp);
    /**
     *  @brief Сеттер для Имени определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение Имени.
     */
    void setname(int pos, QString temp);
    /**
     *  @brief Сеттер для адреса кампании определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение адреса кампании.
     */
    void setaddress(int pos, QString temp);
    /**
     *  @brief Сеттер для максимальной грузоподъёмности определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение максимальной грузоподъёмности.
     */
    void setmaxweight(int pos, int temp);
    /**
     *  @brief Сеттер для рейтинга кампании определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение рейтинга кампании.
     */
    void setrating(int pos, float temp);
    /**
     *  @brief Сеттер для количества людей определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение количества людей
     */
    void setpeople(int pos, int temp);
    /**
     *  @brief Сеттер для контактного телефона определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение контактного телефона.
     */
    void setcontactnumber(int pos, QString temp);
    /**
     *  @brief Сеттер для количества лет кампании определенного элемента списка данных.
     *  @param pos Позиция элемента, в котором произойдут изменения.
     *  @param temp Новое значение количества лет кампании.
     */
    void setyears(int pos, int temp);
    /**
     *  @brief Заменяет наш список с данными на другой.
     *  @param KranTemp Список, на который мы хотим произвести замену.
     */
    void setlist(QList<element> &KranTemp);

private:
    QList<element> Kran; /**< Список, хранящий данные нашего файлы.*/

};

#endif // KRANDATA_H
