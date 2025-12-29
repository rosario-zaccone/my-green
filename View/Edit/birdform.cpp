#include "birdform.h"

BirdForm::BirdForm(QWidget* parent)
    : AnimalForm{parent}
{
    wingspan = new QDoubleSpinBox;
    wingspan->setMinimumSize(100, 40);
    wingspan->setObjectName("addSpin");
    wingspan->setDecimals(3);

    form->addRow(tr("Wingspan (m): "), wingspan);

    setWindowTitle(tr("Add a new bird"));
}

double BirdForm::getWingspan() const
{
    return wingspan->value();
}
