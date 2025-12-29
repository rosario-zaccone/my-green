#ifndef REPTILEFORM_H
#define REPTILEFORM_H

#include "animalform.h"

class ReptileForm : public AnimalForm
{
    Q_OBJECT
public:
    ReptileForm(QWidget* parent = nullptr);

    int getScaleType() const;
private:
    QComboBox* scaleType;
};

#endif // REPTILEFORM_H
