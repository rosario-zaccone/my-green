#ifndef BIRDCARD_H
#define BIRDCARD_H


#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSoundEffect>

#include "./Model/Core/bird.h"

class BirdCard : public QWidget
{
    Q_OBJECT
public:
    BirdCard(const Bird& aValue, QWidget* parent = nullptr);
private:
    Bird value;

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

    QSoundEffect* noise;
protected:
    void paintEvent(QPaintEvent* e);
};

#endif // BIRDCARD_H
