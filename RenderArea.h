//
// Created by lenny on 01/09/2020.
//

#ifndef SORTING_VIS_RENDERAREA_H
#define SORTING_VIS_RENDERAREA_H


#include <QtWidgets>
#include "ArrayCB.h"

class RenderArea: public QWidget {
Q_OBJECT


public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
        Chord, Pie, Path, Text, Pixmap };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void addLine(const QLineF &line);
    void removeLine(const QLineF &line);
    void removeAllLines();

    void setArray(ArrayCB *arr);

public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;

    QVector<QLineF> lines;

    ArrayCB *array;

private:

    void accessCB();
    void swapCB();
};

#endif //SORTING_VIS_RENDERAREA_H
