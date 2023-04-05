﻿#include "DADataPyObject.h"
#include "DAPybind11QtTypeCast.h"
//===================================================
// using DA namespace -- 禁止在头文件using！！
//===================================================

using namespace DA;

//===================================================
// DADataPyObject
//===================================================
DADataPyObject::DADataPyObject() : DAAbstractData()
{
}

DADataPyObject::DADataPyObject(const DAPyObjectWrapper& d)
{
    _pyObject = d;
}

DADataPyObject::~DADataPyObject()
{
}

DAAbstractData::DataType DADataPyObject::getDataType() const
{
    return TypePythonObject;
}

QVariant DADataPyObject::toVariant() const
{
    return DA::PY::toVariant(_pyObject.object());
}

/**
 * @brief 设置值
 * @param v
 * @return 永远返回true
 */
bool DADataPyObject::setValue(const QVariant& v)
{
    pybind11::object obj = DA::PY::toPyObject(v);
    _pyObject.object()   = obj;
    return true;
}

/**
 * @brief 判断是否为null
 * @return
 */
bool DADataPyObject::isNull() const
{
    return _pyObject.isNone();
}

/**
 * @brief 获取python object
 * @return
 */
DAPyObjectWrapper& DADataPyObject::object()
{
    return _pyObject;
}

const DAPyObjectWrapper& DADataPyObject::object() const
{
    return _pyObject;
}
