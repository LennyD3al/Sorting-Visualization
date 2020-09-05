//
// Created by lenny on 01/09/2020.
//

#ifndef SORTING_VIS_MAINWINDOW_H
#define SORTING_VIS_MAINWINDOW_H


#include <QtWidgets>
#include "RenderArea.h"
#include "../Sorting Algorithms /BubbleSort.h"

class MainWindow: public QWidget {
Q_OBJECT

public:
    MainWindow();

private slots:
    void sort();
    void randomise();
    void reset();

    void delayChanged(const QString &text);
    void arrayElementsChanged(const QString &text);

    void sortingAlgChanged(int index);

private:
    RenderArea *renderArea;

    QPushButton *sortButton;
    QPushButton *randomiseButton;
    QPushButton *resetButton;

    QLabel *delayLabel;
    QLineEdit *delayLineEdit;

    QLabel *sortingAlgLabel;
    QComboBox *sortingAlgComboBox;

    QLabel *arrayElementsLabel;
    QLineEdit *arrayElementsLineEdit;


};


#endif //SORTING_VIS_MAINWINDOW_H
