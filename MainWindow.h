//
// Created by lenny on 01/09/2020.
//

#ifndef SORTING_VIS_MAINWINDOW_H
#define SORTING_VIS_MAINWINDOW_H


#include <QtWidgets>
#include "RenderArea.h"
#include "BubbleSort.h"

class MainWindow: public QWidget {
Q_OBJECT

public:
    MainWindow();

    ArrayCB& array();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();

private:
    RenderArea *renderArea;
    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *brushStyleLabel;
    QLabel *otherOptionsLabel;
    QComboBox *shapeComboBox;
    QSpinBox *penWidthSpinBox;
    QComboBox *penStyleComboBox;
    QComboBox *penCapComboBox;
    QComboBox *penJoinComboBox;
    QComboBox *brushStyleComboBox;
    QCheckBox *antialiasingCheckBox;
    QCheckBox *transformationsCheckBox;

};


#endif //SORTING_VIS_MAINWINDOW_H
