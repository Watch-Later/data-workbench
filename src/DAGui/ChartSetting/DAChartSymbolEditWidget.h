#ifndef DACHARTSYMBOLEDITWIDGET_H
#define DACHARTSYMBOLEDITWIDGET_H

#include <QWidget>

namespace Ui {
class DAChartSymbolEditWidget;
}

class DAChartSymbolEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DAChartSymbolEditWidget(QWidget *parent = nullptr);
    ~DAChartSymbolEditWidget();

private:
    Ui::DAChartSymbolEditWidget *ui;
};

#endif // DACHARTSYMBOLEDITWIDGET_H
