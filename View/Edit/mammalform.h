#ifndef MAMMALFORM_H
#define MAMMALFORM_H


#include "animalform.h"

class MammalForm : public AnimalForm
{
    Q_OBJECT
public:
    MammalForm(QWidget* parent = nullptr);

    std::string getFootprintPath() const;
public slots:
    void loadFootprint();
    void updateFootprintStatus();
signals:
    void loadedFootprint();
private:
    QPushButton* footprintButton;
    QString footprintPath;
    QLabel* footprintStatus;
};

#endif // MAMMALFORM_H
