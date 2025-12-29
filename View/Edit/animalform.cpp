#include "animalform.h"

AnimalForm::AnimalForm(QWidget* parent)
    : OrganismForm{parent}
{
    QHBoxLayout* noiseLayout{new QHBoxLayout};

    noiseButton = new QPushButton{tr("Load")};
    noiseButton->setMinimumSize(100, 40);
    noiseButton->setObjectName("addButton");


    noiseStatus = new QLabel;
    noiseStatus->setMinimumSize(100, 40);
    noiseStatus->setObjectName("addString");

    weight = new QDoubleSpinBox;
    weight->setMaximum(2000.0);
    weight->setMinimumSize(100, 40);
    weight->setObjectName("addSpin");
    weight->setDecimals(3);

    noiseLayout->addWidget(noiseButton);
    noiseLayout->addWidget(noiseStatus);

    form->addRow(tr("Animal noise: "), noiseLayout);
    form->addRow(tr("Weight (kg): "), weight);

    connect(noiseButton, &QPushButton::clicked, this, &AnimalForm::loadNoise);
    connect(this, &AnimalForm::loadedNoise, this, &AnimalForm::updateNoiseStatus);
}

void AnimalForm::loadNoise()
{
    QString absNoisePath = QFileDialog::getOpenFileName(this, tr("Load an animal noise"), "../myGreen/Media/Sounds", "WAV files (*.wav)");
    QDir dir{QDir::currentPath()};
    noisePath = dir.relativeFilePath(absNoisePath);
    emit loadedNoise();
}

void AnimalForm::updateNoiseStatus()
{
    noiseStatus->setText("Animal noise loaded");
}

std::string AnimalForm::getNoisePath() const
{
    return noisePath.toStdString();
}

double AnimalForm::getWeight() const
{
    return weight->value();
}
