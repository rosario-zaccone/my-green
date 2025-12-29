#include "plantform.h"

PlantForm::PlantForm(QWidget* parent)
    : OrganismForm{parent}
{
    QHBoxLayout* leafLayout{new QHBoxLayout};
    QHBoxLayout* flowerLayout{new QHBoxLayout};
    QHBoxLayout* fruitLayout{new QHBoxLayout};

    leafButton = new QPushButton{tr("Load")};
    leafButton->setFixedSize(100, 40);
    leafButton->setObjectName("addButton");

    leafStatus = new QLabel;
    leafStatus->setFixedSize(100, 40);
    leafStatus->setObjectName("addString");

    flowerButton = new QPushButton{tr("Load")};
    flowerButton->setFixedSize(100, 40);
    flowerButton->setObjectName("addButton");


    flowerStatus = new QLabel;
    flowerButton->setFixedSize(100, 40);
    flowerStatus->setObjectName("addString");

    fruitButton = new QPushButton{tr("Load")};
    fruitButton->setFixedSize(100, 40);
    fruitButton->setObjectName("addButton");


    fruitStatus = new QLabel;
    fruitStatus->setFixedSize(100, 40);
    fruitStatus->setObjectName("addString");

    leafLayout->addWidget(leafButton);
    leafLayout->addWidget(leafStatus);

    flowerLayout->addWidget(flowerButton);
    flowerLayout->addWidget(flowerStatus);

    fruitLayout->addWidget(fruitButton);
    fruitLayout->addWidget(fruitStatus);

    form->addRow(tr("Leaf photo: "), leafLayout);
    form->addRow(tr("Flower photo: "), flowerLayout);
    form->addRow(tr("Fruit photo: "), fruitLayout);

    connect(leafButton, &QPushButton::clicked, this, &PlantForm::loadLeaf);
    connect(this, &PlantForm::loadedLeaf, this, &PlantForm::updateLeafStatus);

    connect(flowerButton, &QPushButton::clicked, this, &PlantForm::loadFlower);
    connect(this, &PlantForm::loadedFlower, this, &PlantForm::updateFlowerStatus);

    connect(fruitButton, &QPushButton::clicked, this, &PlantForm::loadFruit);
    connect(this, &PlantForm::loadedFruit, this, &PlantForm::updateFruitStatus);
}

std::string PlantForm::getLeafPath() const
{
    return leafPath.toStdString();
}

std::string PlantForm::getFlowerPath() const
{
    return flowerPath.toStdString();
}

std::string PlantForm::getFruitPath() const
{
    return fruitPath.toStdString();
}

void PlantForm::loadLeaf()
{
    QString absLeafPath = QFileDialog::getOpenFileName(this, tr("Load a leaf photo"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    leafPath = dir.relativeFilePath(absLeafPath);
    emit loadedLeaf();
}

void PlantForm::updateLeafStatus()
{
    leafStatus->setText("Leaf photo loaded");
}

void PlantForm::loadFlower()
{
    QString absFlowerPath = QFileDialog::getOpenFileName(this, tr("Load a flower photo"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    flowerPath = dir.relativeFilePath(absFlowerPath);
    emit loadedFlower();
}

void PlantForm::updateFlowerStatus()
{
    flowerStatus->setText("Flower photo loaded");
}

void PlantForm::loadFruit()
{
    QString absFruitPath = QFileDialog::getOpenFileName(this, tr("Load a fruit photo"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    fruitPath = dir.relativeFilePath(absFruitPath);
    emit loadedFruit();
}

void PlantForm::updateFruitStatus()
{
    fruitStatus->setText("Fruit photo loaded");
}
