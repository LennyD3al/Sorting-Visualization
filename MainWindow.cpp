//
// Created by lenny on 01/09/2020.
//



#include "MainWindow.h"

#include <QCoreApplication>
#include <QPushButton>

const int IdRole = Qt::UserRole;



MainWindow::MainWindow() {
    renderArea = new RenderArea;

    sortingAlgComboBox = new QComboBox();
    sortingAlgComboBox->addItem(tr("BubbleSort"), RenderArea::SortingAlgorithm::BubbleSort);
    sortingAlgComboBox->addItem(tr("QuickSort"), RenderArea::SortingAlgorithm::QuickSort );

    sortingAlgLabel = new QLabel(tr("&Sorting Algorithm: "));
    sortingAlgLabel->setBuddy(sortingAlgComboBox);

    delayLineEdit = new QLineEdit;
    delayLineEdit->setValidator(new QIntValidator(0, 200,  this));
    delayLineEdit->setText(tr("20"));

    delayLabel = new QLabel(tr("&Delay"));
    delayLabel->setBuddy(delayLineEdit);

    sortButton = new QPushButton(tr("Sort"));

    randomiseButton = new QPushButton(tr("Randomise"));

    arrayElementsLineEdit = new QLineEdit;
    arrayElementsLineEdit->setValidator(new QIntValidator(0, 200, this));
    arrayElementsLineEdit->setText(tr("10"));

    arrayElementsLabel = new QLabel(tr("&Array Elements: "));
    arrayElementsLabel->setBuddy(arrayElementsLineEdit);

    connect(sortButton, SIGNAL(released()), this, SLOT(sort()));
    connect(randomiseButton, SIGNAL(released()), this, SLOT(randomise()));

    connect(delayLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(delayChanged(const QString &)));
    connect(arrayElementsLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(arrayElementsChanged(const QString &)));

    connect(sortingAlgComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(sortingAlgChanged(int)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);

    mainLayout->addWidget(sortButton, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(randomiseButton, 2, 1, Qt::AlignRight);
    mainLayout->addWidget(sortingAlgLabel, 2, 2, Qt::AlignRight);
    mainLayout->addWidget(sortingAlgComboBox, 2, 3);

    mainLayout->addWidget(delayLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(delayLineEdit, 3, 1);

    mainLayout->addWidget(arrayElementsLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(arrayElementsLineEdit, 3, 3);


    setLayout(mainLayout);

    delayChanged(delayLineEdit->text());
    arrayElementsChanged(arrayElementsLineEdit->text());


    setWindowTitle(tr("Basic Drawing"));


}



void MainWindow::sort() {
    printf("Sort\n");
    renderArea->startSort();
}

void MainWindow::randomise() {
    renderArea->randomiseArray();
}

void MainWindow::delayChanged(const QString &text) {
    printf("Delay: %d\n", text.toInt());
    renderArea->setDelay(text.toInt());
}

void MainWindow::arrayElementsChanged(const QString &text) {
    printf("Array Elements: %d\n", text.toInt());
    renderArea->setArrayElements(text.toInt());
}

void MainWindow::sortingAlgChanged(int index) {
    printf("Sorting Alg: %d\n", index);
    RenderArea::SortingAlgorithm alg = RenderArea::SortingAlgorithm(sortingAlgComboBox->itemData(sortingAlgComboBox->currentIndex(), IdRole).toInt());
    renderArea->setSortingAlgorithm(alg);
}
