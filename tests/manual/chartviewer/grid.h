/****************************************************************************
**
** Copyright (C) 2014 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.io
**
** This file is part of the Qt Charts module.
**
** Licensees holding valid commercial license for Qt may use this file in
** accordance with the Qt License Agreement provided with the Software
** or, alternatively, in accordance with the terms contained in a written
** agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.io
**
****************************************************************************/

#ifndef GRID_H_
#define GRID_H_

#include "model.h"
#include <QtWidgets/QGraphicsWidget>
#include <QtCharts/QChartGlobal>

class QGraphicsGridLayout;
class Chart;

QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Grid : public QGraphicsWidget
{
    Q_OBJECT
public:
    enum State { NoState = 0, ZoomState, ScrollState};

    Grid(int size, QGraphicsItem *parent = 0);
    ~Grid();

    QList<QChart *> charts();
    void createCharts(const QString &category = QString());
    void createCharts(const QString &category, const QString &subcategory, const QString &name);
    void replaceChart(QChart *oldChart, Chart *newChart);
    void setState(State state);
    State state() const { return m_state; };
    void setRubberPen(const QPen &pen);
    void setSize(int size);
    int size() const {return m_size;}

Q_SIGNALS:
    void chartSelected(QChart *chart);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    void clear();

private:
    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    int m_size;
    DataTable m_dataTable;
    QHash<QChart *, int> m_chartHash;
    QHash<int, QChart *> m_chartHashRev;
    State m_state;
    State m_currentState;
    QPointF m_origin;
    QGraphicsRectItem *m_rubberBand;
    QGraphicsGridLayout *m_gridLayout;
};

#endif /* GRID_H_ */
