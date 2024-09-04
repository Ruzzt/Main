/**
 *  @file mainwindow.cpp
 *  @brief Файл исходного кода для класса MainWindow.
 */
#include "mainwindow.h"
#include "printpreview.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QContextMenuEvent>
#include <QFileDialog>
#include <QLibraryInfo>
#include <QMessageBox>
#include <QPrinter>
#include <QSettings>

#include "chart.h"
#include "search.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    /// Инициализируем список языков и выбранный язык пустыми значениями.
    , languageActionGroup(nullptr)
    , checkedAction(nullptr)
{
    ui->setupUi(this);
    /// Настройки tableView для работы DragNDrop.
    ui->tableView->viewport()->setAcceptDrops(true);
    ui->tableView->setDragDropMode(QAbstractItemView::NoDragDrop);
    ui->tableView->setSelectionMode(QTableWidget::SingleSelection);
    ui->tableView->setSelectionBehavior(QTableWidget::SelectRows);
    ui->tableView->setDragDropOverwriteMode(true);
    ui->tableView->setDropIndicatorShown(true);
    ui->tableView->setFocus();
    /// Добавляем в comboBox с синтаксисом фильтра необходимые элементы
    ui->comboBox->addItem(tr("Regular Expression"));
    ui->comboBox->addItem(tr("Wildcard"));
    //ui->comboBox->addItem(tr("Fixed String"));
    /// Соединяем сигнал textChanged lineEdit фильтра
    /// с функцией textFilterChanged для вызова функции при
    /// кажом изменении текста в строке.
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::textFilterChanged);
    /// Соединяем сигнал currentIndexChanged комбо бокса
    /// с типами синтаксисов с функцией textFilterChanged
    /// для вызова функции при выборе типа синтаксиса.
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(textFilterChanged()));
    /// Соединяем сигнал dateChanged dateEdit фильтра
    /// с функцией dateFilterChanged для вызова функции при
    /// кажом изменении даты.
    this->setAcceptDrops(1);
    this->acceptDrops();
    /// Создаем объект модели и пользовательской прокси-модели.
    Model = new KranModel();
    proxyModel = new MySortProxyModel(this);
    proxyModel->setSourceModel(Model);
    /// Соединяем комбобокс выбора режима DragNDrop с
    /// функцией setMimeType пользовательского tableView.
    connect(ui->comboBox_MimeType,
            &QComboBox::currentTextChanged,
            ui->tableView,
            &MyTableView::setMimeType);
    /// Ставим пустой заголовок окна
    /// и создаем контекстные меню.
    setWindowTitle(" ");
    ContextMenuEdit = ui->menuEdit;
    ContextMenuFile = ui->menuFile;
    /// Подключим переменные, которые в будущем будут
    /// содержать переводы к нашему приложению.
    qApp->installTranslator(&appTranslator);
    qApp->installTranslator(&qtTranslator);
    /// Прописываем путь .qm файлов.
    qmPath = "./translations";
    /// Вызываем методы создания списка языков
    /// и чтения сохраненных настроек приложения.
    createLanguageMenu();
    readSettings();
}

MainWindow::~MainWindow()
{
    /// Сохраняем настройки интерфейса приложения
    /// и удаляем динамически созданные объекты.
    writeSettings();
    delete ui;
    delete Model;
    delete proxyModel;
}

void MainWindow::switchLanguage(QAction *action)
{
    /// Делаем опцию активной.
    action->setChecked(true);
    /// Определяем какая локаль выбрана.
    locale = action->data().toString();
    /// Загружаем перевод, который
    /// соответствует локали.
    appTranslator.load("kran_" + locale, qmPath);
    locale.chop(3);
    /// Для перевода стандартных сообщений Qt.
    qtTranslator.load("qt_" + locale + ".qm",
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    ui->retranslateUi(this);
    /// Заново заполняем элементы comboBox.
    ui->comboBox->clear();
    ui->comboBox->addItem(tr("Regular Expression"));
    ui->comboBox->addItem(tr("Wildcard"));
}

void MainWindow::createLanguageMenu()
{
    /// Создаем список языков.
    languageActionGroup = new QActionGroup(this);
    /// Определяем каталог с .qm файлами.
    QDir dir(qmPath);
    qDebug() << qmPath;
    /// Ставим связь пунктов меню со слотом смены языка приложения.
    connect(languageActionGroup, &QActionGroup::triggered, this, &MainWindow::switchLanguage);
    /// Получаем список .qm файлов.
    QStringList fileNames = dir.entryList(QStringList("kran*.qm"));
    /// Количество итераций равно количеству файлов.
    for (int i = 0; i < fileNames.size(); i++) {
        /// Получаем локаль.
        QString newlocale = fileNames[i];
        /// Удаляем символы по "_".
        newlocale.remove(0, newlocale.indexOf('_') + 1);
        /// Удаляем символы, начиная с точки.
        newlocale.truncate(newlocale.lastIndexOf('.'));
        /// Создаем временную переменную перевода.
        QTranslator translator;
        /// Загружаем перевод>
        translator.load(fileNames[i], qmPath);
        /// Создаем имя пункта, имя меняем в Linguist.
        QString language = translator.translate("MainWindow", "English");
        /// Создаем пункт в меню с номером и названием языка.
        QAction *action = new QAction(tr("&%1 %2").arg(i + 1).arg(language), this);
        /// Задаем свойство держать пункт выбранным
        /// и задаем данные пункту.
        action->setCheckable(true);
        action->setData(newlocale);
        /// Добавляем пункт в меню на форме
        /// и в группу пунктов.
        ui->menuLanguage->addAction(action);
        languageActionGroup->addAction(action);
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    /// Выводим сообщение "aboutQt".
    QApplication::aboutQt();
}

void MainWindow::on_actionAbout_App_triggered()
{
    /// Выводим сообщение с информацией о программе.
    QMessageBox::about(this,
                       tr("About App"),
                       tr("This program was created to account for Kran.\n"
                          "The program was written by ICTMS-2-4 student\n"
                          "Ruzavina Tatiana"));
}

void MainWindow::on_actionExit_triggered()
{
    /// Закрываем объект.
    this->close();
}

void MainWindow::readSettings()
{
    /// Начало группы settings.
    QSettings settings("MySoft", "Kran");
    settings.beginGroup("Window");
    /// Меняем размер, если нету сохраненных данных
    /// берется второй аргумент.
    resize(settings.value("size", QSize(400, 400)).toSize());
    /// Меняем позицию, если нету сохраненных данных
    /// берется второй аргумент.
    move(settings.value("position", QPoint(200, 200)).toPoint());
    /// Получаем значение выбранного языка,
    /// если нету, берем английский.
    QString langchecked = settings.value("lang", "en_US").toString();
    QList<QAction *> Actions;
    Actions = languageActionGroup->actions();
    /// Проходимся по всем пунктам в группе,
    for (int i = 0; i < Actions.count(); i++) {
        /// если полученный язык равен пункту в группе,
        if (Actions[i]->data() == langchecked)
            /// переключаемся на него.
            switchLanguage(Actions[i]);
    }
    /// Конец группы.
    settings.endGroup();
}

void MainWindow::writeSettings()
{
    /// Начало группы.
    QSettings settings("MySoft", "Kran");
    settings.beginGroup("Window");
    /// Запоминаем размер.
    settings.setValue("size", size());
    /// Запоминаем позицию.
    settings.setValue("position", pos());
    /// Запоминаем выбранную локаль.
    settings.setValue("lang", languageActionGroup->checkedAction()->data());
    /// Конец группы.
    settings.endGroup();
}

void MainWindow::on_actionOpen_triggered()
{
    /// Если открытая модель была отредактирована, предложим сохранить.
    if (Model->getedited())
        SaveBefore();
    fileName = "";
    /// Получаем имя файла (путь) из диалогового окна.
    fileName = QFileDialog::getOpenFileName(this,
                                            tr("Open file"),
                                            "",
                                            FileFilter,
                                            nullptr,
                                            QFileDialog::DontUseNativeDialog);
    /// Если пустое, выходим.
    if (fileName == "")
        return;
    /// Если имя содержит ключевое слово, продолжаем.
    if (fileName.contains("kran")) {
        /// Меняем заголовок на имя.
        setWindowTitle(fileName);
        /// Проверка на наличие ключевого слова внутри файла.
        if (!Model->checkModel(fileName)) {
            /// Если нету, Warning и выход.
            QMessageBox::warning(this, tr("Warning"), tr("Not appropriate file type!"));
            return;
        }
        /// Если все ок, читаем файл
        /// и выводим в tableView.
        Model->readModel(fileName);
        ui->tableView->setModel(proxyModel);
        /// Пункт редактирования теперь активен.
        ui->menuEdit->setEnabled(true);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    } else
        /// Если имя не содержит ключевого слова, выводим Warning.
        QMessageBox::warning(this, tr("Warning"), tr("Not appropriate file name!"));
}

void MainWindow::on_actionSave_triggered()
{
    if (fileName == "") {
        /// Если файл был создан пользователем,
        /// то сохраняем и выводим имя в заголовок.
        fileName = QFileDialog::getSaveFileName(this,
                                                tr("Save file"),
                                                "Untitled.db",
                                                FileFilter,
                                                nullptr,
                                                QFileDialog::DontUseNativeDialog);
        setWindowTitle(fileName);
        Model->writeModel(fileName);
    }
    if (Model->getedited()) {
        /// Если файл существовал и был отредактирован,
        /// то просто сохраняем.
        Model->writeModel(fileName);
    }
}

void MainWindow::on_actionNew_triggered()
{
    /// Закрываем текущий файл и делаем имя пустым.
    on_actionClose_triggered();
    fileName = "";
    setWindowTitle("Untitled.db");
    /// Выводим в tableview.
    ui->tableView->setModel(proxyModel);
    ui->menuEdit->setEnabled(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void MainWindow::on_actionClose_triggered()
{
    /// Предложить сохранить изменения.
    if (Model->getedited())
        SaveBefore();
    /// Очищаем имя файла и саму модель.
    fileName = "";
    Model->removeAllModel();
    /// Делаем заголовок окна пустым.
    setWindowTitle(" ");
    ui->menuEdit->setEnabled(false);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void MainWindow::SaveBefore()
{
    /// Если ответ на предложение сохранить был положительным,
    /// вызываем функцию сохранения.
    if (QMessageBox::question(this, tr("Save file"), tr("Save file before closing?"))
        == QMessageBox::Yes)
        on_actionSave_triggered();
}

void MainWindow::on_actionEdit_triggered()
{
    /// Получаем выбранную строку.
    QModelIndexList rows = ui->tableView->selectionModel()->selectedRows();
    /// Если ничего не было получено, выходим.
    if (rows.isEmpty())
        return;
    /// Вызываем метод editModel
    /// с аргументом в виде номера строки,
    /// которую хотим редактировать.
    /// Метод mapToSource необходим для перевода
    /// индекса из прокси модели в исходную.
    Model->editModel(proxyModel->mapToSource(rows[0]).row());
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
    /// Не закрываем до ответа.
    event->ignore();
    /// Если отредактировано,
    if (Model->getedited()) {
        /// предлагаем сохранить.
        SaveBefore();
    }
    /// Спрашиваем действительно ли пользовтаель хочет выйти.
    if (QMessageBox::Yes
        == QMessageBox::question(this,
                                 tr("Exit"),
                                 tr("Do you really want to exit?"),
                                 QMessageBox::Yes | QMessageBox::No)) {
        /// Если да, выходим.
        event->accept();
    }
}

void MainWindow::on_actionAdd_triggered()
{
    /// Вызываем метод addModel
    /// который вызовет диалоговое окно и т.д.
    Model->addModel();
}

void MainWindow::on_actionDelete_triggered()
{
    /// Получаем выбранную строку.
    QModelIndexList row = ui->tableView->selectionModel()->selectedRows();
    /// Если строка не была получена,
    if (row.isEmpty())
        /// то выходим.
        return;
    /// Вызываем метод deleteModel
    /// с аргументом в виде номера строки,
    /// которую хотим удалить.
    /// Метод mapToSource необходим для перевода
    /// индекса из прокси модели в исходную.
    Model->deleteModel(proxyModel->mapToSource(row[0]).row());
}

void MainWindow::on_actionSearch_2_triggered()
{
    /// Создаем объект класса Search
    /// и ставим заголовок.
    Search *SSearch = new Search();
    SSearch->setWindowTitle(tr("Search"));
    /// Если была нажата кнопка "Ок".
    if (SSearch->exec() == QDialog::Accepted) {
        /// Получаем результат для строки
        /// и для даты с помощью методов класса Search.
        QString res = SSearch->getResult();
        int entries = ui->tableView->model()->rowCount();
        /// Идем по всем строкам.
        for (int i = 0; i < entries; i++) {
            /// Создаем указатель на модель.
            QAbstractItemModel *M = ui->tableView->model();
            /// Получаем из него значения столбцов строки
            /// с нужными нам форматами.
            QString ID = M->data(M->index(i, 0)).toString();
            QString Name = M->data(M->index(i, 1)).toString();
            QString Address = M->data(M->index(i, 2)).toString();
            QString Maxweight = M->data(M->index(i, 3)).toString();
            QString Rating = M->data(M->index(i, 4)).toString();
            QString People = M->data(M->index(i, 5)).toString();
            QString ContactNumber = M->data(M->index(i, 6)).toString();
            QString Years = M->data(M->index(i, 7)).toString();
            /// Изначально индикатор = true,
            /// то есть строка отображается.
            bool indicator = true;

            /// Если в строку поиска не было ничего введено
            /// или нашлось совпадение, то логически умножаем на true,
            if (res == "" || ID == res || Name.contains(res) || Address.contains(res)
                || Maxweight == res || Rating == res || People == res || ContactNumber.contains(res)
                || Years == res)
                indicator &= true;
            else
                /// иначе на false.
                indicator &= false;

            /// Если индикатор true, то показываем строку,
            /// иначе скрываем.
            if (indicator)
                ui->tableView->showRow(i);
            else
                ui->tableView->hideRow(i);
        }
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    /// Сохраняем настройки,
    /// создаем объект класса MainWindow и отображаем.
    writeSettings();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->show();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    /// Если пункт меню "Редактировать" отключен,
    /// отображаем пункт "Файл" в контекстном.
    if (ContextMenuFile && !(ui->menuEdit->isEnabled()))
        ContextMenuFile->exec(event->globalPos());
    /// Если пункт меню "Редактировать" включен,
    /// отображаем пункт "Редактировать" в контекстном.
    if (ContextMenuEdit && ui->menuEdit->isEnabled())
        ContextMenuEdit->exec(event->globalPos());
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e)
{
    /// Получаем данные типа "text".
    QString temp = e->mimeData()->data("text");
    /// Если в mimeData есть данные помимо типа "text",
    /// принимаем, иначе отклоняем.
    if (e->mimeData()->hasText() && temp.isEmpty())
        e->setAccepted(true);
    else
        e->setAccepted(false);
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *e)
{
    /// Принимаем возможность выхода из виджета.
    e->setAccepted(true);
}

void MainWindow::dropEvent(QDropEvent *e)
{
    QString tempstr;
    QStringList templist;
    /// Получаем данные типа "app"
    tempstr = e->mimeData()->data("app");
    /// Вносим в список, учитывая разделитель.
    templist = tempstr.split(';');
    /// Если список не пуст.
    if (!templist.isEmpty() || templist.contains(";")) {
        /// Записываем данные в структуру
        /// и добавляем ее в список с нашими данными.
        KranData::element tempstruct = {templist.at(0).toInt(),
                                        templist.at(1),
                                        templist.at(2),
                                        templist.at(3).toInt(),
                                        templist.at(4).toFloat(),
                                        templist.at(5).toInt(),
                                        templist.at(6),
                                        templist.at(7).toInt()};
        Model->add(tempstruct);
    }
}

void MainWindow::on_actionPrint_triggered()
{
    // Получаем имя файла от пользователя
    QString fileName = QInputDialog::getText(this, tr("Имя файла"), tr("Введите имя файла:"));

    // Если имя файла пустое, выходим
    if (fileName.isEmpty()) {
        return;
    }

    // Создаем объект QString и QTextStream
    QString strStream;
    QTextStream out(&strStream);

    // Получаем количество строк и столбцов
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount = ui->tableView->model()->columnCount();

    // Заголовок таблицы
    QString tableHeader = tr("Accounting of finishing Kran");

    // Формируем HTML-код
    out << "<html>\n"
        << "<head>\n"
        << "<meta Content=\"Text/html; charset=UTF-8\">\n"
        << QString("<title>%1</title>\n").arg(fileName) << "</head>\n"
        << "<body bgcolor=#ffffff link=#5000A0>\n"
        << QString("<h3 style=\"text-align:center\"><font color=\"black\">%1</font></h3>\n")
               .arg(tableHeader)
        << "<table align=\"center\" bgcolor=\"black\" cellpadding=5>\n"
        << "<thead><tr bgcolor=\"lightgrey\">";

    // Заполняем заголовок таблицы
    for (int column = 0; column < columnCount; column++) {
        if (!ui->tableView->isColumnHidden(column)) {
            out << QString("<th><font color=\"black\">%1</font></th>")
                       .arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        }
    }

    out << "</tr></thead>\n";

    QString data;

    // Заполняем данные таблицы
    for (int row = 0; row < rowCount; row++) {
        out << "<tr bgcolor=\"white\">";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tableView->isColumnHidden(column)) {
                // Вставляем данные без форматирования
                data = ui->tableView->model()
                           ->data(ui->tableView->model()->index(row, column))
                           .toString();
                out << QString("<td bkcolor=0><font color=\"black\">%1</font></td>")
                           .arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                // }
            }
        }
        out << "</tr>\n";
    }

    // Закрываем теги
    out << "</table>\n"
           "</body>\n"
           "</html>\n";

    // Создаем объект PrintPreview
    PrintPreview *tb = new PrintPreview(nullptr, &strStream);
    tb->setWindowTitle(tr("Print Preview"));
    tb->show();
}

void MainWindow::on_actionChart_triggered()
{
    /// Если имя файла пустое,
    /// то выходим
    if (fileName == "")
        return;
    /// Чистим списки для возможности
    /// корректного повторного отображения графика.
    NamessList.clear();
    WeightList.clear();
    /// Заполняем списки.
    QAbstractItemModel *M = ui->tableView->model();
    int entries = ui->tableView->model()->rowCount();
    /// Заполняем список с фамилиями ответственных.
    for (int i = 0; i < entries; i++) {
        QString Namess = M->data(M->index(i, 1)).toString();
        if (!NamessList.contains(Namess))
            NamessList.append(Namess);
    }
    /// Заполняем список со стоимостями.
    for (int i = 0; i < NamessList.count(); i++) {
        /// Во втором списке стоимости должны соотвествовать фамилиям.
        WeightList.append(0);
        for (int j = 0; j < entries; j++) {
            int Weight = M->data(M->index(j, 3)).toInt();
            /// Если фамилия в модели равна имени в списке.
            if (M->data(M->index(j, 1)).toString() == NamessList.at(i))
                /// Прибавляем к стоимости списка стоимость из модели.
                WeightList[i] += Weight;
        }
    }
    /// Создаем объект класса Chart,
    /// передаем ему два списка.
    Chart *Chart = new class Chart(nullptr, NamessList, WeightList);
    /// Ставим заголовок и показываем виджет.
    Chart->setWindowTitle(tr("Chart"));
    Chart->show();
}

void MainWindow::textFilterChanged()
{
    /// Вытаскиваем синтаксис из комбобокса.
    int syntax = ui->comboBox->currentIndex();
    QString pattern = ui->lineEdit->text();
    switch (syntax) {
    case 1:
        pattern = QRegularExpression::wildcardToRegularExpression(pattern);
        break;
    case 2:
        pattern = QRegularExpression::escape(pattern);
        break;
    default:
        break;
    }
    /// Создаем объект класса QRegExp,
    /// передаем ему текст, синтаксис,
    /// устанавливаем чувствительность к регистру.
    QRegularExpression::PatternOptions options = QRegularExpression::CaseInsensitiveOption;
    /// Устанавливаем фильтр.
    QRegularExpression regularExpression(pattern, options);
    proxyModel->setFilterRegularExpression(regularExpression);
}
