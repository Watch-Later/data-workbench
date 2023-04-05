﻿#ifndef DADATAPYDATAFRAME_H
#define DADATAPYDATAFRAME_H

#include "DADataAPI.h"
#include <memory>
#include "DAAbstractData.h"
#include "DAPyObjectWrapper.h"
#include "pandas/DAPyDataFrame.h"
#include "DADataPyObject.h"
namespace DA
{
/**
 * @brief DAPyDataFrame 的封装
 */
class DADATA_API DADataPyDataFrame : public DADataPyObject
{
public:
    DADataPyDataFrame(const DAPyDataFrame& d);
    ~DADataPyDataFrame();
    //变量类型
    DataType getDataType() const override;
    //变量值
    QVariant toVariant() const override;
    bool setValue(const QVariant& v) override;
    //获取dataframe
    DAPyDataFrame& dataframe();
    const DAPyDataFrame& dataframe() const;

protected:
    DAPyDataFrame _df;
};
}  // namespace DA
#endif  // DADATAPYDATAFRAME_H
