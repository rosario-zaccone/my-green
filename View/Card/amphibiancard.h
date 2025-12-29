#ifndef AMPHIBIANCARD_H
#define AMPHIBIANCARD_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSoundEffect>

#include "labelimage.h"
#include "./Model/Core/amphibian.h"


class AmphibianCard : public QWidget
{
    Q_OBJECT
public:
    AmphibianCard(const Amphibian& aValue, QWidget* parent = nullptr);
private:
    Amphibian value;

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
    LabelImage* larvalStage;

    QSoundEffect* noise;
protected:
    void paintEvent(QPaintEvent* e);
};



#endif // AMPHIBIANCARD_H
