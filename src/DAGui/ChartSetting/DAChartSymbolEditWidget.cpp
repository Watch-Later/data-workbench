#include "DAChartSymbolEditWidget.h"
#include "ui_DAChartSymbolEditWidget.h"

DAChartSymbolEditWidget::DAChartSymbolEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DAChartSymbolEditWidget)
{
    ui->setupUi(this);
}

DAChartSymbolEditWidget::~DAChartSymbolEditWidget()
{
    delete ui;
}
