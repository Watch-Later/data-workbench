﻿#ifndef DACHARTPLOTITEMSETTINGWIDGET_H
#define DACHARTPLOTITEMSETTINGWIDGET_H

#include <QWidget>
#include <QPointer>
#include "DAGuiAPI.h"
#include "DAAbstractChartItemSettingWidget.h"
class QAbstractButton;
class QwtPlotItem;
class QwtPlot;
namespace Ui
{
class DAChartPlotItemSettingWidget;
}
namespace DA
{
/**
 * @brief QwtPlotItem的设置窗口
 */
class DAGUI_API DAChartPlotItemSettingWidget : public DAAbstractChartItemSettingWidget
{
    Q_OBJECT

public:
	explicit DAChartPlotItemSettingWidget(QWidget* parent = nullptr);
	~DAChartPlotItemSettingWidget();

	// 设置item,此界面可以不设置item，仅仅当作参数获取，如果设置了item，会在对应的界面联动
	void setPlotItem(QwtPlotItem* item);
	// 清除
	void clear();
	// 根据item值刷新ui内容，此函数不会触发信号
	void updateUI(const QwtPlotItem* item);
	// 根据ui更新plotitem
	void updatePlotItem(QwtPlotItem* item);
	// 更新坐标轴的设置
	void updateAxis(const QwtPlotItem* item);

	// 设置标题
	void setItemTitle(const QString& t);
	QString getItemTitle() const;
	// 获取设置的轴id
	QPair< int, int > getAxisIDs() const;
private slots:
	void onItemTitleEditingFinished();
	void onItemZValueChanged(double z);
	void onButtonGroupAxisClicked(QAbstractButton* btn);

private:
	Ui::DAChartPlotItemSettingWidget* ui;
};
}
#endif  // DACHARTPLOTITEMSETTINGWIDGET_H
