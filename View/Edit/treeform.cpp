#include "treeform.h"

TreeForm::TreeForm(QWidget* parent)
    : PlantForm{parent}
{
    diameter = new QDoubleSpinBox;
    diameter->setMinimumSize(100, 40);
    diameter->setObjectName("addSpin");
    diameter->setDecimals(3);

    form->addRow(tr("Diameter (m): "), diameter);

    setWindowTitle(tr("Add a new tree"));
}

double TreeForm::getDiameter() const
{
    return diameter->value();
}
