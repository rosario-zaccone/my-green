#ifndef HERBFORM_H
#define HERBFORM_H

#include "plantform.h"

class HerbForm : public PlantForm
{
    Q_OBJECT
public:
    HerbForm(QWidget* parent = nullptr);

    bool isCulinary() const;
    bool isCosmetic() const;
    bool isMedicinal() const;
private:
    QCheckBox* culinary;
    QCheckBox* cosmetic;
    QCheckBox* medicinal;
};

#endif // HERBFORM_H
