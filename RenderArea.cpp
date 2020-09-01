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
    return QSize(400, 200);
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

    painter.drawLines(lines);

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}

void RenderArea::addLine(const QLineF &line) {
    lines.push_back(line);
    update();
}

void RenderArea::removeLine(const QLineF &line) {
    lines.removeOne(line);
    update();
}

void RenderArea::removeAllLines() {
    lines.clear();
    update();
}

void RenderArea::setArray(ArrayCB *arr) {
    array = arr;
    array->add_array_accessed_cb([this] { accessCB(); });
    array->add_array_swapped_cb([this] { swapCB(); });
}

void RenderArea::accessCB() {
    printf("Access CB\n");
    update();
}

void RenderArea::swapCB() {
    printf("Swap CB\n");
    update();
}


