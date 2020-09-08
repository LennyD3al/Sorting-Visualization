//
// Created by lenny on 01/09/2020.
//



#include "MainWindow.h"


const int IdRole = Qt::UserRole;



MainWindow::MainWindow() {

    renderArea = new RenderArea;

    sortingAlgComboBox = new QComboBox();
    sortingAlgComboBox->addItem(tr("BubbleSort"), SortingAlgorithm::BubbleSort);
    sortingAlgComboBox->addItem(tr("InsertionSort"), SortingAlgorithm::InsertionSort);
    sortingAlgComboBox->addItem(tr("QuickSort"), SortingAlgorithm::QuickSort );

    sortingAlgLabel = new QLabel(tr("&Sorting Algorithm: "));
    sortingAlgLabel->setBuddy(sortingAlgComboBox);

    delayLineEdit = new QLineEdit;
    delayLineEdit->setValidator(new QIntValidator(0, 200,  this));
    delayLineEdit->setText(tr("20"));

    delayLabel = new QLabel(tr("&Delay"));
    delayLabel->setBuddy(delayLineEdit);

    sortButton = new QPushButton(tr("Sort"));

    randomiseButton = new QPushButton(tr("Randomise"));

    resetButton = new QPushButton(tr("Reset"));

    arrayElementsLineEdit = new QLineEdit;
    arrayElementsLineEdit->setValidator(new QIntValidator(0, 1000, this));
    arrayElementsLineEdit->setText(tr("10"));

    arrayElementsLabel = new QLabel(tr("&Array Elements: "));
    arrayElementsLabel->setBuddy(arrayElementsLineEdit);

    connect(sortButton, SIGNAL(released()), this, SLOT(sort()));
    connect(randomiseButton, SIGNAL(released()), this, SLOT(randomise()));
    connect(resetButton, SIGNAL(released()), this, SLOT(reset()));

    connect(delayLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(delayChanged(const QString &)));
    connect(arrayElementsLineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(arrayElementsChanged(const QString &)));

    connect(sortingAlgComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(sortingAlgChanged(int)));

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->addWidget(renderArea, 0, 0, 1, 4);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(sortButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->addWidget(randomiseButton);

    mainLayout->addLayout(buttonLayout, 2, 0, 1, 2);

    mainLayout->addWidget(randomiseButton, 2, 1, Qt::AlignRight);

    mainLayout->addWidget(sortingAlgLabel, 2, 2 , Qt::AlignRight);
    mainLayout->addWidget(sortingAlgComboBox, 2, 3);

    mainLayout->addWidget(delayLabel, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(delayLineEdit, 3, 1);

    mainLayout->addWidget(arrayElementsLabel, 3, 2, Qt::AlignRight);
    mainLayout->addWidget(arrayElementsLineEdit, 3, 3);


    setLayout(mainLayout);

    delayChanged(delayLineEdit->text());
    arrayElementsChanged(arrayElementsLineEdit->text());
    sortingAlgChanged(sortingAlgComboBox->currentIndex());


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
    renderArea->setDelay(text.toInt());
}

void MainWindow::arrayElementsChanged(const QString &text) {
    renderArea->setArrayElements(text.toInt());
}

void MainWindow::sortingAlgChanged(int index) {
    SortingAlgorithm alg = SortingAlgorithm(sortingAlgComboBox->itemData(sortingAlgComboBox->currentIndex(), IdRole).toInt());
    renderArea->setSortingAlgorithm(alg);
}

void MainWindow::reset() {
    renderArea->reset();
}
