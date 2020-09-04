#include <iostream>
#include <cstdio>

#include "MainWindow.h"
#include <thread>


int main(int argc, char **argv) {
    QApplication app(argc, argv);

    MainWindow widget;

    widget.show();

    return app.exec();
}