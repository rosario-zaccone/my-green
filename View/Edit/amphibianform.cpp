#include "amphibianform.h"

AmphibianForm::AmphibianForm(QWidget* parent)
    : AnimalForm{parent}
{
    QHBoxLayout* lsLayout{new QHBoxLayout};

    lsButton = new QPushButton{tr("Load")};
    lsButton->setMinimumSize(100, 40);
    lsButton->setObjectName("addButton");


    lsStatus = new QLabel;
    lsStatus->setMinimumSize(100, 40);
    lsStatus->setObjectName("addString");

    lsLayout->addWidget(lsButton);
    lsLayout->addWidget(lsStatus);

    form->addRow(tr("Larval stage image: "), lsLayout);

    connect(lsButton, &QPushButton::clicked, this, &AmphibianForm::loadLs);
    connect(this, &AmphibianForm::loadedLs, this, &AmphibianForm::updateLsStatus);

    setWindowTitle(tr("Add a new amphibian"));
}

std::string AmphibianForm::getLsPath() const
{
    return lsPath.toStdString();
}

void AmphibianForm::loadLs()
{
    QString absLsPath = QFileDialog::getOpenFileName(this, tr("Load larval stage photo"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    lsPath = dir.relativeFilePath(absLsPath);
    emit loadedLs();
}

void AmphibianForm::updateLsStatus()
{
    lsStatus->setText(tr("Larval stage image loaded"));
}
