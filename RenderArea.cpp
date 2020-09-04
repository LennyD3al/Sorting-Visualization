//
// Created by lenny on 01/09/2020.
//



#include "RenderArea.h"

#include <functional>
#include <iostream>

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent) {

    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    sorting = false;
}

QSize RenderArea::sizeHint() const {
    return QSize(600, 400);
}

QSize RenderArea::minimumSizeHint() const {
    return QSize(100, 100);
}


void RenderArea::paintEvent(QPaintEvent * /* event */) {

    QPainter painter(this);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);

    painter.drawRects(rects);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void RenderArea::addRect(const QRectF &rect) {
    rects.push_back(rect);
    update();
}

void RenderArea::addRect(const QRectF &rect, const int &i) {
    rects.insert(i, rect);

}

void RenderArea::removeRect(const QRectF &rect) {
    rects.removeOne(rect);

}

void RenderArea::removeRect(const int &index) {
    rects.remove(index);

}

void RenderArea::removeAllRects() {
    rects.clear();

}

void RenderArea::setArray(int *arr, int s) {
    m_array.reset();
    m_array = std::make_unique<ArrayCB>(arr, s);
    m_array->add_array_accessed_cb([this] { accessCB(); });
    m_array->add_array_swapped_cb([this] { swapCB(); });
    m_array->add_array_swapped_cb([this] { sleep(); });
    updateLines();
    update();
}

void RenderArea::accessCB() {
    // printf("Access CB\n");
    // updateLines();
    update();
}

void RenderArea::swapCB() {


    updateLines();
    update();
}

void RenderArea::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    removeAllRects();
    updateLines();
}

void RenderArea::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);


}

void RenderArea::updateLines() {


    int arraySize = m_array->size();

    // Calculate width
    float recWidth = width() / arraySize;

    if (rects.isEmpty() && m_array != nullptr) {
        // No Rects

        for (int i = 0; i < arraySize; i++) {

            float recHeight = scale((*m_array)[i], height(), m_array->largest_element());

            float xPos = i * recWidth;

            QRectF rect(xPos, height(), recWidth, -recHeight);

            addRect(rect);

        }

        last_drawn = ArrayCB(*m_array);

    } else {
        std::vector<bool> pos_changed = m_array->position_changed(last_drawn);

        for (int i = 0; i < m_array->size(); i++) {
            if (pos_changed[i]) {
                removeRect(i);

                float recHeight = scale((*m_array)[i], height(), m_array->largest_element());

                float xPos = i * recWidth;

                QRectF rect(xPos, height(), recWidth, -recHeight);

                addRect(rect, i);
            }

        }

        last_drawn = ArrayCB(*m_array);

        // removeAllRects();
        // updateLines();
    }
}

float RenderArea::scale(const float &val, const float &out_max, const float &in_max) {
    return val * out_max / in_max;
}

void RenderArea::sleep() {
    std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
}

void RenderArea::startSort() {
    sortingThread = new std::thread([this] {
        this->sorting = true;
        BubbleSort::sort(*(this->m_array), this->m_array->size());
        this->sorting = false;
    });
}

void RenderArea::randomiseArray() {
    if (!sorting) {
        for (int i = 0; i < m_array->size(); i++) {
            (*m_array)[i] = rand() % 1000;
        }
        updateLines();
    }
}

void RenderArea::setSortingAlgorithm(const RenderArea::SortingAlgorithm &alg) {

}

void RenderArea::setDelay(const int &delay) {
    m_delay = delay;
}

void RenderArea::setArrayElements(const int &elements) {
    if (!sorting) {
        int *arr = new int[elements];
        for (int i = 0; i < elements; i++) {
            arr[i] = rand() % 1000;
        }
        setArray(arr, elements);
        delete[] arr;
    }
}








