#ifndef ANIMALFORM_H
#define ANIMALFORM_H

#include "organismform.h"

class AnimalForm : public OrganismForm
{
    Q_OBJECT
public:
    AnimalForm(QWidget* parent = nullptr);

    double getWeight() const;
    std::string getNoisePath() const;

public slots:
    void loadNoise();
    void updateNoiseStatus();
signals:
    void loadedNoise();
private:
    QPushButton* noiseButton;
    QString noisePath;
    QLabel* noiseStatus;

    QDoubleSpinBox* weight;
};

#endif // ANIMALFORM_H

