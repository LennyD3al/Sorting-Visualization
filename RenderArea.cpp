//
// Created by lenny on 01/09/2020.
//



#include "RenderArea.h"

#include <functional>

RenderArea::RenderArea(QWidget *parent)
        : QWidget(parent)
{
    shape = Polygon;
    antialiased = false;
    transformed = false;
    pixmap.load(":/images/qt-logo.png");

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::sizeHint() const
{
    return QSize(600, 400);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}

void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */) {

    QPainter painter(this);
    painter.setPen(pen);
    painter.setBrush(brush);
    if (antialiased)
        painter.setRenderHint(QPainter::Antialiasing, true);

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

void RenderArea::removeRect(const QRectF &rect) {
    rects.removeOne(rect);
    update();
}

void RenderArea::removeAllRects() {
    rects.clear();
    update();
}

void RenderArea::setArray(ArrayCB *arr) {
    m_array = arr;
    m_array->add_array_accessed_cb([this] { accessCB(); });
    m_array->add_array_swapped_cb([this] { swapCB(); });
    m_array->add_array_swapped_cb(sleep);
    printf("SetArray\n");

}

void RenderArea::accessCB() {
    printf("Access CB\n");
    // updateLines();
    update();
}

void RenderArea::swapCB() {
    printf("Swap CB\n");
    updateLines();
    update();
}

void RenderArea::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    int width = event->size().width();
    int height = event->size().height();

    // printf("Width: %d, Height: %d\n", width, height);
}

void RenderArea::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    int width = this->width();
    int height = this->height();

    printf("Width: %d, Height: %d\n", width, height);

}

void RenderArea::updateLines() {


    int arraySize = m_array->size();

    if (rects.isEmpty() && m_array != nullptr) {
        printf("Update Lines\n");
        // No Rects

        // Calculate width
        float recWidth = width() / arraySize;

        for (int i = 0; i < arraySize; i++) {

            float recHeight = scale((*m_array)[i], height(), m_array->largest_element());

            float xPos = i * recWidth;

            QRectF rect(xPos, height(), recWidth, -recHeight);

            addRect(rect);

        }
    } else {
        removeAllRects();
        updateLines();
    }
}

float RenderArea::scale(const float &val, const float &out_max, const float &in_max) {
    return val * out_max / in_max;
}

void RenderArea::sleep() {
    printf("Sleep\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}




