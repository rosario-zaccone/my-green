#include "mammalform.h"

MammalForm::MammalForm(QWidget* parent)
    : AnimalForm{parent}
{
    QHBoxLayout* footprintLayout{new QHBoxLayout};

    footprintButton = new QPushButton{tr("Load")};
    footprintButton->setMinimumSize(100, 40);
    footprintButton->setObjectName("addButton");

    footprintStatus = new QLabel;
    footprintStatus->setMinimumSize(100, 40);
    footprintStatus->setObjectName("addString");

    footprintLayout->addWidget(footprintButton);
    footprintLayout->addWidget(footprintStatus);

    form->addRow(tr("Footprint image: "), footprintLayout);

    connect(footprintButton, &QPushButton::clicked, this, &MammalForm::loadFootprint);
    connect(this, &MammalForm::loadedFootprint, this, &MammalForm::updateFootprintStatus);

    setWindowTitle(tr("Add a new mammal"));
}

std::string MammalForm::getFootprintPath() const
{
    return footprintPath.toStdString();
}

void MammalForm::loadFootprint()
{
    QString absfootprintPath = QFileDialog::getOpenFileName(this, tr("Load footprint photo"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    footprintPath = dir.relativeFilePath(absfootprintPath);
    emit loadedFootprint();
}

void MammalForm::updateFootprintStatus()
{
    footprintStatus->setText(tr("Footprint stage image loaded"));
}

