/**
 *  @file kranModel.cpp
 *  @brief Исходный код для класса KranModel.
 */
#include "kranModel.h"
#include "editdialog.h"

KranModel::KranModel(QObject *parent):
    QAbstractTableModel{parent},
    /// Инициализация переменных: количество колонок и индикатор редактирования.
    columnsNum(8),
    edited(false)
{
    /// Создаем новый экземпляр класса KranData.
    Kran = new KranData();
}

int KranModel::rowCount(const QModelIndex &parent) const
{
    /// Возвращает количество строк, если индекс родительского элемента является недопустимым.
    return parent.isValid() ? 0 : Kran->rowsCount();
}

int KranModel::columnCount(const QModelIndex &parent) const
{
    /// Возвращает количество колонок, если индекс родительского элемента является недопустимым.
    return parent.isValid() ? 0 : columnsNum;
}

QVariant KranModel::data(const QModelIndex &index, int role) const
{
    /// Если индекс недействительный, возвращаем пустой QVariant.
    if(!index.isValid())
        return QVariant();
    /// Получаем строку и колонку.
    int row = index.row();
    int col = index.column();
    /// Переключатель для ролей.
    switch (role) {
    /// Если роль отображения или редактирования,
    case Qt::DisplayRole:
    case Qt::EditRole:
        /// В зависимости от номера колонки,
        if (col == 0)
            /// возвращаем ID.
            return Kran->get(row).ID;
        if (col == 1)
            /// возвращаем Имя.
            return Kran->get(row).Name;
        if (col == 2)
            /// возвращаем Адрес.
            return Kran->get(row).Address;
        if (col == 3)
            /// возвращаем Максимальный вес.
            return Kran->get(row).Maxweight;
        if (col == 4)
            /// возвращаем Рейтинг.
            return Kran->get(row).Rating;
        if (col == 5)
            /// возвращаем Количество людей.
            return Kran->get(row).People;
        if (col == 6)
            /// возвращаем Контактный номер.
            return Kran->get(row).ContactNumber;
        if (col == 7)
            /// возвращаем Количество лет.
            return Kran->get(row).Years;
        break;
    }
    /// Возвращаем пустой QVariant, если ничего не было выполнено.
    return QVariant();
}

QVariant KranModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    /// Если горизонтальная ориентация и роль отображения.
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        /// В зависимости от номера секции (колонки),
        case 0:
            /// возвращаем ID.
            return QString(tr("ID"));

        case 1:
            /// возвращаем Имя.
            return QString(tr("Name"));

        case 2:
            /// возвращаем Адрес.
            return QString(tr("Address"));

        case 3:
            /// возвращаем Максимальный вес.
            return QString(tr("Maxweight"));

        case 4:
            /// возвращаем Рейтинг.
            return QString(tr("Rating"));

        case 5:
            /// возвращаем Количество людей.
            return QString(tr("People"));

        case 6:
            /// возвращаем Контактный номер.
            return QString(tr("ContactNumber"));

        case 7:
            /// возвращаем Количество лет.
            return QString(tr("Years"));
        }
    }
    /// Если вертикальная ориентация и роль отображения.
    if (orientation == Qt::Vertical && role == Qt::DisplayRole)
        /// Возвращаем номер секции + 1, чтобы нумерация начиналась с единицы.
        return QString::number(section + 1);
    /// Если ничего не было возвращено, то пустой QVariant.
    return QVariant();
}

bool KranModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    /// Если индекс недействительный
    if (!checkIndex(index, CheckIndexOption::IndexIsValid))
        /// то возвращаем false.
        return false;
    /// Получаем значения строки и колонки.
    int row = index.row();
    int col = index.column();
    /// Если роль редактирования,
    if (role == Qt::EditRole) {
        /// В зависимости от номера колонки,
        if (col == 0)
            /// меняем ID.
            Kran->setid(row, value.toInt());
        if (col == 1)
            /// меняем Имя.
            Kran->setname(row, value.toString());
        if (col == 2)
            /// меняем Адрес.
            Kran->setaddress(row, value.toString());
        if (col == 3)
            /// меняем Максимальный вес.
            Kran->setmaxweight(row, value.toInt());
        if (col == 4)
            /// меняем Рейтинг.
            Kran->setrating(row, value.toFloat());
        if (col == 5)
            /// меняем Количество людей.
            Kran->setpeople(row, value.toInt());
        if (col == 6)
            /// меняем Контактный номер.
            Kran->setcontactnumber(row, value.toString());
        if (col == 7)
            /// меняем Количество лет.
            Kran->setyears(row, value.toInt());
        /// Сигнал модели об изменении данных.
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});
        /// Устанавливаем индикатор редактирования на true и возвращаем true.
        edited = true;
        return true;
    }
    /// Если не роль редактирования, возвращаем false.
    return false;
}

Qt::ItemFlags KranModel::flags(const QModelIndex &index) const
{
    /// Если индекс является действительным, возвращаем
    if (index.isValid())
        return  /// флаг, разрешающий использование элемента.
            Qt::ItemIsEnabled |
            /// флаг, разрешающий выделение элемента.
            Qt::ItemIsSelectable |
            /// флаг, разрешающий редактирование элемента.
            Qt::ItemIsEditable |
            /// флаг, разрешающий перетаскивание элемента.
            Qt::ItemIsDragEnabled;
    else
        /// Возвращаем отсутствие флагов, если индекс недействительный.
        return Qt::NoItemFlags;
}

KranModel::~KranModel()
{
    /// Удаляем динамически созданный экземпляр Kran.
    delete Kran;
}

bool KranModel::checkModel(QString fileName)
{
    /// Если функция checkFile из KranData
    /// вернула true, возвращаем true,
    /// если false, то false соответственно.
    if (Kran->checkFile(fileName))
        return true;
    else
        return false;
}

void KranModel::readModel(QString fileName)
{
    /// Начинаем сброс модели,
    /// вызываем функцию чтения файла
    /// Вызываем функции окончания сброса.
    this->beginResetModel();
    Kran->readFromFile(fileName);
    this->endResetModel();
    /// Если файл был только что открыт, то edited = false.
    edited = false;
}

void KranModel::writeModel(QString fileName)
{
    /// Вызываем функцию записи файла.
    Kran->writeToFile(fileName);
    /// Если файл был сохранен, то edited = false.
    edited = false;
}

void KranModel::addModel()
{
    /// Начинаем сброс модели.
    this->beginResetModel();
    /// Динамически создаем экземпляр диалогового окна редактирования.
    EditDialog *Dialog = new EditDialog();
    /// Устанавливаем заголовок.
    Dialog->setWindowTitle(tr("Add Entry"));
    /// Если нажата кнопка "Ок" то,
    if(Dialog->exec() == QDialog::Accepted)
        /// Вызываем функцию добавления в список,
        /// в качестве аргумента выбираем ту структуру,
        /// которую вернул диалог.
        Kran->addToTable(Dialog->getKran());
    /// Окончание сброса.
    this->endResetModel();
    /// Данные были изменены.
    edited = true;
}

void KranModel::editModel(int at)
{
    /// Создаем диалоговое окно редактирования,
    /// в конструктор передаем выбранную строку (структуру).
    EditDialog *Dialog = new EditDialog(Kran->get(at));
    /// Устанавливаем заголовок.
    Dialog->setWindowTitle(tr("Edit Entry"));
    if (Dialog->exec() == QDialog::Accepted)
        /// Если нажата кнопка "Ок",
        /// то вызываем функцию редактирования,
        /// аргументы - позиция и структура, которую вернул диалог.
        Kran->editEntry(at, Dialog->getKran());
    /// Данные были изменены.
    edited = true;
}

void KranModel::deleteModel(int at)
{
    /// Начинаем сброс модели,
    /// вызываем функцию удаления элемента
    /// Вызываем функции окончания сброса.
    this->beginResetModel();
    Kran->deleteEntry(at);
    this->endResetModel();
    /// Данные были изменены.
    edited = true;
}

void KranModel::removeAllModel()
{
    /// Начинаем сброс модели,
    /// вызываем функцию очистки списка.
    /// Вызываем функции окончания сброса.
    this->beginResetModel();
    Kran->removeAll();
    this->endResetModel();
    /// edited = false, так как функция нужна для закрытия файла.
    edited = false;
}

bool KranModel::getedited()
{
    /// Возвращаем индикатор.
    return edited;
}

void KranModel::setedited(bool edited)
{
    /// Меняем индикатор на аргумент.
    this->edited = edited;
}

void KranModel::add(KranData::element Kran)
{
    /// Начинаем сброс модели,
    /// вызываем функцию добавления элемента без диалогового окна
    /// Вызываем функции окончания сброса.
    this->beginResetModel();
    this->Kran->addToTable(Kran);
    this->endResetModel();
    /// Данные были изменены.
    edited = true;
}
