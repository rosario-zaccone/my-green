#ifndef PLANTFORM_H
#define PLANTFORM_H

#include "organismform.h"

class PlantForm : public OrganismForm
{
    Q_OBJECT
public:
    PlantForm(QWidget* parent = nullptr);

    std::string getLeafPath() const;
    std::string getFlowerPath() const;
    std::string getFruitPath() const;

public slots:
    void loadLeaf();
    void updateLeafStatus();

    void loadFlower();
    void updateFlowerStatus();

    void loadFruit();
    void updateFruitStatus();
signals:
    void loadedLeaf();
    void loadedFruit();
    void loadedFlower();

private:
    QString leafPath;
    QPushButton* leafButton;
    QLabel* leafStatus;

    QString flowerPath;
    QPushButton* flowerButton;
    QLabel* flowerStatus;

    QString fruitPath;
    QPushButton* fruitButton;
    QLabel* fruitStatus;
};

#endif // PLANTFORM_H
