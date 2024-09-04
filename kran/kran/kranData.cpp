/**
 *  @file kranData.cpp
 *  @brief Исходный код для класса KranData.
 */
#include "kranData.h"

#include <QFile>
#include <QTextStream>

KranData::KranData()
{

}

bool KranData::checkFile(QString fileName)
{
    /// Создаем объект класса QFile.
    QFile file(fileName);
    /// Открываем файл в режиме чтения.
    file.open(QIODevice::ReadOnly);
    /// Читаем первую строку из потока.
    QTextStream stream(&file);
    QString checkfile = stream.readLine();
    /// Закрываем файл.
    file.close();
    /// Если строка равна "Ruzavina", возвращаем true, иначе false.
    if (checkfile != "Ruzavina")
        return false;
    else
        return true;
}

void KranData::readFromFile(QString fileName)
{
    /// Создаем объект класса QFile.
    QFile file(fileName);
    /// Открываем файл для чтения.
    if(file.open(QIODevice::ReadOnly)) {
        /// Читаем строку из потока.
        QTextStream stream(&file);
        QString checkfile = stream.readLine();
        /// Пока не достигнут конец потока.
        while (!stream.atEnd()) {
            /// Считываем строку.
            QString str = stream.readLine();
            /// Если строка пустая, пропускаем итерацию.
            if (str.isEmpty())
                continue;
            /// Разделяем строку на части.
            QStringList part = str.split(";");
            /// Присваиваем временной структуре соответствующие данные.
            element temporary = {
                /// Преобразуем данные в нужные форматы, если необходимо.
                part.at(0).toInt(),
                part.at(1),
                part.at(2),
                part.at(3).toInt(),
                part.at(4).toFloat(),
                part.at(5).toInt(),
                part.at(6),
                part.at(7).toInt(),
            };
            /// Добавляем структуру в список.
            Kran.append(temporary);
        }
    }
    else
        return;
    /// Закрываем файл.
    file.close();
    return;
}

void KranData::writeToFile(QString fileName)
{
    /// Создаем объект класса QFile.
    QFile file(fileName);
    /// Открываем файл для записи.
    if(file.open(QIODevice::WriteOnly)){
        /// Пишем данные в поток.
        QTextStream stream(&file);
        /// Добавляем "ключ" для идентификации "своих" файлов.
        stream << "Ruzavina\n";
        /// Для каждого элемента в списке.
        for (int i = 0; i < Kran.count(); i++) {
            /// Присваиваем временной структуре элемент списка.
            element temporary = Kran.at(i);
            /// Записываем данные в поток с разделителем и правильным форматом.
            stream << temporary.ID << ";"
                   << temporary.Name << ";"
                   << temporary.Address << ";"
                   << temporary.Maxweight << ";"
                   << temporary.Rating << ";"
                   << temporary.People << ";"
                   << temporary.ContactNumber << ";"
                   << temporary.Years << ";" << "\n";
        }
    }else
        return;
    /// Закрываем файл.
    file.close();
    return;
}

void KranData::addToTable(element Kran)
{
    /// Добавляем аргумент Kran в список.
    this->Kran.append(Kran);
}

void KranData::editEntry(int i, element Kran)
{
    /// Присваиваем элементу списка под номером i аргумент Kran.
    this->Kran[i] = Kran;
}

void KranData::deleteEntry(int i)
{
    /// Удаляем элемент под номером i из списка.
    Kran.removeAt(i);
}

KranData::element KranData::get(int i)
{
    /// Возвращаем элемент под номером i.
    return Kran.at(i);
}

int KranData::rowsCount()
{
    /// Возвращаем количество элементов в списке.
    return Kran.count();
}

void KranData::removeAll()
{
    /// Полностью очищаем список.
    Kran.clear();
}

void KranData::setid(int pos, int temp)
{
    /// Заменяем ID структуры element на позиции pos в списке аргументом temp.
    Kran[pos].ID = temp;
}

void KranData::setname(int pos, QString temp)
{
    /// Заменяем Name структуры element на позиции pos в списке аргументом temp.
    Kran[pos].Name = temp;
}

void KranData::setaddress(int pos, QString temp)
{
    /// Заменяем Address структуры element на позиции pos в списке аргументом temp.
    Kran[pos].Address = temp;
}

void KranData::setmaxweight(int pos, int temp)
{
    /// Заменяем Maxweight структуры element на позиции pos в списке аргументом temp.
    Kran[pos].Maxweight = temp;
}

void KranData::setrating(int pos, float temp)
{
    /// Заменяем Rating структуры element на позиции pos в списке аргументом temp.
    Kran[pos].Rating = temp;
}

void KranData::setpeople(int pos, int temp)
{
    /// Заменяем People структуры element на позиции pos в списке аргументом temp.
    Kran[pos].People = temp;
}

void KranData::setcontactnumber(int pos, QString temp)
{
    /// Заменяем ContactNumber структуры element на позиции pos в списке аргументом temp.
    Kran[pos].ContactNumber = temp;
}

void KranData::setyears(int pos, int temp)
{
    /// Заменяем Years структуры element на позиции pos в списке аргументом temp.
    Kran[pos].Years = temp;
}

void KranData::setlist(QList<element> &KranTemp)
{
    /// Заменяем элементы нашего списка элементами списка KranTemp.
    for (int i = 0; i < Kran.count(); i++) {
        Kran.replace(i, KranTemp.at(i));
    }
}
