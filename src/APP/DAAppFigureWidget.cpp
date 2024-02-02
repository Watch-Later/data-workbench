﻿#include "DAAppFigureWidget.h"
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QDebug>
#include "MimeData/DAMimeDataForData.h"
#include "MimeData/DAMimeDataFormats.h"
#include "Dialog/DADialogChartGuide.h"
#include "DAWaitCursorScoped.h"
#include "DAColorTheme.h"
#include "DAChartUtil.h"
namespace DA
{
class DAAppFigureWidgetPrivate
{
public:
    DA_IMPL_PUBLIC(DAAppFigureWidget)
    DAAppFigureWidgetPrivate(DAAppFigureWidget* p);
    // 获取dlg指针，如果为nullptr，则创建
    DADialogChartGuide* getDlgDataframeToPointVector();
    // 绘制,如果没成功，返回nullptr
    QwtPlotItem* plotWithGuideDialog(const DAData& data = DAData());

public:
    bool _isStartDrag { false };
    DADialogChartGuide* _dlgDataframePlot { nullptr };
    DADataManager* _dataManager { nullptr };
    DAColorTheme mColorTheme;  ///< 当前的颜色主题
};
DAAppFigureWidgetPrivate::DAAppFigureWidgetPrivate(DAAppFigureWidget* p)
    : q_ptr(p), _dlgDataframePlot(nullptr), _dataManager(nullptr), mColorTheme(DAColorTheme::ColorTheme_Cassatt2)
{
}

DADialogChartGuide* DAAppFigureWidgetPrivate::getDlgDataframeToPointVector()
{
    if (!_dlgDataframePlot) {
        _dlgDataframePlot = new DADialogChartGuide(q_ptr);
        _dlgDataframePlot->setDataManager(_dataManager);
    }
    return _dlgDataframePlot;
}

/**
 * @brief 绘图，如果没有返回nullptr
 * @param data
 * @return
 */
QwtPlotItem* DAAppFigureWidgetPrivate::plotWithGuideDialog(const DAData& data)
{
    DADialogChartGuide* dlg = getDlgDataframeToPointVector();
    if (data) {
        dlg->setCurrentData(data);
    } else {
        dlg->updateData();
    }
    if (QDialog::Accepted != dlg->exec()) {
        return nullptr;
    }
    DAWaitCursorScoped wait;
    Q_UNUSED(wait);
    QwtPlotItem* item = dlg->createPlotItem();
    if (nullptr == item) {
        return nullptr;
    }
    QColor clr = mColorTheme.current();
    if (DAChartUtil::setPlotItemColor(item, clr)) {
        // 成功设置颜色，就把主题颜色下移一个
        mColorTheme.moveToNext();
    }
    qDebug() << "color:" << clr.name() << "  |  ColorTheme = " << mColorTheme;
    return item;
}

//==============================================================
// DAAppFigureWidget
//==============================================================

DAAppFigureWidget::DAAppFigureWidget(QWidget* parent)
    : DAFigureWidget(parent), d_ptr(new DAAppFigureWidgetPrivate(this))
{

    setAcceptDrops(true);
}

DAAppFigureWidget::~DAAppFigureWidget()
{
}

/**
 * @brief 设置dmgr
 * @param mgr
 */
void DAAppFigureWidget::setDataManager(DADataManager* mgr)
{
    d_ptr->_dataManager = mgr;
}

/**
 * @brief 带引导界面的曲线添加
 * @return
 * @note 用户有可能换其他曲线，所以返回不一定是折线
 */
QwtPlotItem* DAAppFigureWidget::addPlotWithGuide_()
{
    DAChartWidget* chart = getCurrentChart();
    if (chart == nullptr) {
        return nullptr;
    }
    return d_ptr->plotWithGuideDialog();
}

/**
 * @brief 设置颜色主题
 * @param th
 */
void DAAppFigureWidget::setColorTheme(DAColorTheme::ColorTheme th)
{
    d_ptr->mColorTheme = th;
}

/**
 * @brief 获取当前的颜色主题
 * @return
 */
DAColorTheme::ColorTheme DAAppFigureWidget::getColorTheme() const
{
    return d_ptr->mColorTheme.getCurrentColorTheme();
}

/**
 * @brief 拖曳进入
 *
 * 此事件需要accept,否则move事件不会触发
 * @param e
 */
void DAAppFigureWidget::dragEnterEvent(QDragEnterEvent* e)
{
    if (!e) {
        return;
    }
    qDebug() << "DAAppFigureWidget::dragEnterEvent";
    if (e->source() == this || nullptr == e->source()) {
        return;
    }
    const QMimeData* mimeData = e->mimeData();
    if (mimeData->hasFormat(DAMIMEDATA_FORMAT_DADATA)) {
        e->acceptProposedAction();
    } else {
        qDebug() << "DAAppFigureWidget::dragEnterEvent get unknow format:" << mimeData->formats();
    }
}

void DAAppFigureWidget::dragMoveEvent(QDragMoveEvent* e)
{
    if (!e) {
        return;
    }
    if (e->source() == this || nullptr == e->source()) {
        return;
    }
    const QMimeData* mimeData = e->mimeData();
    if (mimeData->hasFormat(DAMIMEDATA_FORMAT_DADATA)) {
        // 数据
        QWidget* w = getWidgetUnderPos(e->pos());
        if (nullptr == w) {
            e->setDropAction(Qt::IgnoreAction);
            return;
        }
        if (DAChartWidget* chart = qobject_cast< DAChartWidget* >(w)) {
            Q_UNUSED(chart);
            e->setDropAction(Qt::CopyAction);
            e->accept();
            return;
        }
    }
    e->setDropAction(Qt::IgnoreAction);
}

void DAAppFigureWidget::dragLeaveEvent(QDragLeaveEvent* e)
{
    if (!e) {
        return;
    }
    d_ptr->_isStartDrag = false;
    e->accept();
}

void DAAppFigureWidget::dropEvent(QDropEvent* e)
{
    d_ptr->_isStartDrag = false;
    if (!e) {
        return;
    }
    if (e->source() == this || nullptr == e->source()) {
        return;
    }

    const QMimeData* mimeData = e->mimeData();
    if (mimeData->hasFormat(DAMIMEDATA_FORMAT_DADATA)) {
        // 数据
        const DAMimeDataForData* datamime = qobject_cast< const DAMimeDataForData* >(mimeData);
        if (nullptr == datamime) {
            return;
        }
        QWidget* w = getWidgetUnderPos(Qt5Qt6Compat_QXXEvent_Pos(e));
        if (nullptr == w) {
            return;
        }
        if (DAChartWidget* chart = qobject_cast< DAChartWidget* >(w)) {
            if (getCurrentChart() != chart) {
                // 如果当前绘图不是放下的绘图，则把当前绘图设置为放下数据的绘图
                setCurrentChart(chart);
            }
            QwtPlotItem* pi = d_ptr->plotWithGuideDialog(datamime->getDAData());
            if (nullptr == pi) {
                e->ignore();
                return;
            } else {
                // 加入
                addItem_(pi);
            }
            e->acceptProposedAction();
        }
    }
}

}
