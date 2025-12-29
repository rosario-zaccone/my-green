#include "herbform.h"

HerbForm::HerbForm(QWidget* parent)
    : PlantForm{parent}
{
    culinary = new QCheckBox;
    cosmetic = new QCheckBox;
    medicinal = new QCheckBox;

    form->addRow(tr("Culinary use"), culinary);
    form->addRow(tr("Cosmetic use"), cosmetic);
    form->addRow(tr("Medicinal use"), medicinal);

    setWindowTitle(tr("Add a new herb"));
}

bool HerbForm::isCulinary() const
{
    return culinary->isChecked();
}

bool HerbForm::isCosmetic() const
{
    return cosmetic->isChecked();
}

bool HerbForm::isMedicinal() const
{
    return medicinal->isChecked();
}
