#ifndef TREEFORM_H
#define TREEFORM_H

#include "plantform.h"

class TreeForm : public PlantForm
{
    Q_OBJECT
public:
    TreeForm(QWidget* parent = nullptr);

    double getDiameter() const;
private:
    QDoubleSpinBox* diameter;
};

#endif // TREEFORM_H
