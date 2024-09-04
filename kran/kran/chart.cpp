/**
 *  @file chart.cpp
 *  @brief Файл исходного кода для класса Chart.
 */
#include "chart.h"
#include "ui_chart.h"

Chart::Chart(QWidget *parent, QList<QString> MList, QList<int> NList)
    : QWidget(parent)
    , ui(new Ui::Chart)
{
    ui->setupUi(this);

    /// Создаем объект класса QBarSeries.
    QBarSeries *barseries = new QBarSeries();
    /// Идем по списку MList.
    for (int i = 0; i < MList.count(); i++) {
        /// Создаем объект класса QBarSet,
        /// в качестве аргумента конструктора
        /// используем элемент списка MList,
        /// т.е. фамилию, в соответствие фамилии
        /// помещаем сумму стоимостей, соответствующих ей.
        QBarSet *set = new QBarSet(MList[i]);
        *set << NList[i];
        /// Добавляем в объект класса QBarSeries объект set.
        barseries->append(set);
    }

    /// Создаем объект класса QChart;
    QChart *chart = new QChart();
    /// Помещаем в него данные из barseries.
    chart->addSeries(barseries);
    /// Устанавливаем заголовок графика.
    chart->setTitle(tr("Correlation between Maxweigth and Name"));
    /// Устанавливаем анимации и
    /// помещаем легенду вниз.
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->legend()->setAlignment(Qt::AlignBottom);

    /// Ищем максимальное значение в списке NList,
    /// создаем объект QValueAxis,
    /// ось Y будет заканчиваться нашим макс. значением.
    /// Помещаем ось на график слева.
    int max = *std::max_element(NList.begin(), NList.end());
    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, max);
    chart->addAxis(axisY, Qt::AlignLeft);
    barseries->attachAxis(axisY);

    /// Создаем объект класса QChartView,
    /// объект класса QVBoxLayout
    /// Помещаем chartView в layout.
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    QVBoxLayout *layout = new QVBoxLayout(ui->frame);
    layout->addWidget(chartView);
}

Chart::~Chart()
{
    delete ui;
}
