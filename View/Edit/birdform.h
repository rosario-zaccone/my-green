#ifndef BIRDFORM_H
#define BIRDFORM_H

#include "animalform.h"

class BirdForm : public AnimalForm
{
    Q_OBJECT
public:
    BirdForm(QWidget* parent = nullptr);

    double getWingspan() const;
private:
    QDoubleSpinBox* wingspan;
};

#endif // BIRDFORM_H
