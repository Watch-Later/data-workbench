﻿#ifndef DAGRAPHICSITEMGROUP_H
#define DAGRAPHICSITEMGROUP_H
#include <QGraphicsItemGroup>
#include "DAUtils/DAXMLFileInterface.h"
#include "DAGraphicsViewGlobal.h"
class QDomDocument;
class QDomElement;
class QGraphicsSceneHoverEvent;
namespace DA
{
/**
 * @brief QGraphicsItemGroup的继承
 */
class DAGRAPHICSVIEW_API DAGraphicsItemGroup : public QGraphicsItemGroup, public DAXMLFileInterface
{
    DA_DECLARE_PRIVATE(DAGraphicsItemGroup)
public:
    DAGraphicsItemGroup(QGraphicsItem* parent = nullptr);
    ~DAGraphicsItemGroup();
    // 保存到xml中
    virtual bool saveToXml(QDomDocument* doc, QDomElement* parentElement) const override;
    virtual bool loadFromXml(const QDomElement* parentElement) override;
    // 设置边框画笔，如果设置一个QPen,则不绘制边框
    void setBorderPen(const QPen& p);
    QPen getBorderPen() const;
    // 设置是否显示边框
    void setShowBorder(bool on);
    bool isShowBorder() const;
    // 背景
    void setBackgroundBrush(const QBrush& b);
    QBrush getBackgroundBrush() const;
    // 设置是否显示背景
    void setShowBackground(bool on);
    bool isShowBackground() const;

public:
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
};

}

#endif  // DAGRAPHICSITEM_H