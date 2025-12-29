#ifndef MAMMALCARD_H
#define MAMMALCARD_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSoundEffect>

#include "labelimage.h"
#include "./Model/Core/mammal.h"

class MammalCard : public QWidget
{
    Q_OBJECT
public:
    MammalCard(const Mammal& aValue, QWidget* parent = nullptr);
private:
    Mammal value;

    QLabel* name;
    QLabel* type;
    QLabel* score;
    QLabel* size;

    QLabel* taxonomy;
    QLabel* dimension;

    QLabel* habitat;
    QLabel* cs;

    QLabel* description;

    //right side
    QLabel* image;
    QPushButton* noiseButton;
    LabelImage* footprint;

    QSoundEffect* noise;
protected:
    void paintEvent(QPaintEvent* e);
};


#endif // MAMMALCARD_H
