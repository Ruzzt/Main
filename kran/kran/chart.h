/**
 *  @file chart.h
 *  @brief Заголовочный файл для класса Chart.
 */
#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>

namespace Ui {
class Chart;
}
/**
 * @class Chart
 * @brief Класс для вывода графика.
 */
class Chart : public QWidget
{
    Q_OBJECT

public:
    /**
     *  @brief Конструктор класса Chart.
     *  @param parent Родительский объект.
     *  @param NList Список с названиями кампаний.
     *  @param WList Список с максимальной грузоподъёмностью.
     */
    explicit Chart(QWidget *parent, QList<QString> NList, QList<int> WList);
    /**
     * @brief Деструктор класса Chart.
    */
    ~Chart();

private:
    Ui::Chart *ui;
};

#endif // CHART_H
