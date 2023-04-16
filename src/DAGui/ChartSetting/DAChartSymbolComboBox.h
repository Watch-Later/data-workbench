﻿#ifndef DACHARTSYMBOLCOMBOBOX_H
#define DACHARTSYMBOLCOMBOBOX_H
#include <QComboBox>
#include "DAGuiAPI.h"
#include "qwt_symbol.h"
namespace DA
{
/**
 * @brief 针对QwtSymbol的combobox，此类参考qtiplot的SymbolBox
 */
class DAGUI_API DAChartSymbolComboBox : public QComboBox
{
public:
    DAChartSymbolComboBox(QWidget* par = 0);
    //
    void setSymbolStyle(const QwtSymbol::Style& s);
    QwtSymbol::Style getSymbolStyle() const;
    static QwtSymbol::Style style(int index);
    static int symbolIndex(const QwtSymbol::Style& style);
signals:
    /**
     * @brief symbolStyleChanged
     * @param s
     */
    void symbolStyleChanged(QwtSymbol::Style s);
private slots:
    void onCurrentIndexChanged(int index);

private:
    void buildItems();

private:
    static const QwtSymbol::Style symbols[];
};
}

#endif  // DACHARTSYMBOLCOMBOBOX_H
