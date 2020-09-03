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

    void setArray(ArrayCB *arr);


public slots:
    void setShape(Shape shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setAntialiased(bool antialiased);
    void setTransformed(bool transformed);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;

    QVector<QRectF> rects;

    ArrayCB *m_array;

private:
    void accessCB();
    void swapCB();

    void addRect(const QRectF &rect);
    void removeRect(const QRectF &rect);
    void removeAllRects();

    static float scale(const float &val, const float &out_max, const float &in_max);

    void updateLines();
};

#endif //SORTING_VIS_RENDERAREA_H
