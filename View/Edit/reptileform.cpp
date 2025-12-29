#include "reptileform.h"

ReptileForm::ReptileForm(QWidget* parent)
    : AnimalForm{parent}
{
    scaleType = new QComboBox;
    scaleType->setMinimumSize(100, 40);
    scaleType->setObjectName("addCombo");
    scaleType->insertItem(0, tr("Tubercular"));
    scaleType->insertItem(1, tr("Shielded"));
    scaleType->insertItem(2, tr("Imbricated"));
    scaleType->insertItem(3, tr("Armored"));

    form->addRow(tr("Scale type: "), scaleType);

    setWindowTitle(tr("Add a new reptile"));
}

int ReptileForm::getScaleType() const
{
    return scaleType->currentIndex();
}

