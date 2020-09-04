//
// Created by lenny on 01/09/2020.
//

#ifndef SORTING_VIS_RENDERAREA_H
#define SORTING_VIS_RENDERAREA_H


#include <QtWidgets>
#include <chrono>
#include <thread>
#include <stdlib.h>

#include "ArrayCB.h"
#include "BubbleSort.h"

class RenderArea: public QWidget {
Q_OBJECT


public:

    enum SortingAlgorithm {
        BubbleSort,
        QuickSort,
    };

    RenderArea(QWidget *parent = 0);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    void setArray(int *arr, int s);


public slots:

    void startSort();
    void randomiseArray();

    void setDelay(const int &delay);
    void setArrayElements(const int &elements);

    void setSortingAlgorithm(const SortingAlgorithm &alg);

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:

    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;

    SortingAlgorithm sortingAlgorithm;
    int m_delay;

    QVector<QRectF> rects;

    std::unique_ptr<ArrayCB> m_array;
    ArrayCB last_drawn;

    std::thread *sortingThread;
    std::atomic<bool> sorting;

private:
    void accessCB();
    void swapCB();

    void sleep();

    void addRect(const QRectF &rect);
    void addRect(const QRectF &rect, const int &i);
    void removeRect(const QRectF &rect);
    void removeRect(const int &index);
    void removeAllRects();

    static float scale(const float &val, const float &out_max, const float &in_max);

    void updateLines();
};

#endif //SORTING_VIS_RENDERAREA_H
