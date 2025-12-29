#ifndef REPTILECARD_H
#define REPTILECARD_H


#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSoundEffect>

#include "labelimage.h"
#include "./Model/Core/reptile.h"

class ReptileCard : public QWidget
{
    Q_OBJECT
public:
    ReptileCard(const Reptile& aValue, QWidget* parent = nullptr);
private:
    Reptile value;

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
    LabelImage* scale;

    QSoundEffect* noise;
protected:
    void paintEvent(QPaintEvent* e);
};


#endif // REPTILECARD_H
