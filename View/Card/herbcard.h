#ifndef HERBCARD_H
#define HERBCARD_H


#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "labelimage.h"
#include "./Model/Core/herb.h"

class HerbCard : public QWidget
{
    Q_OBJECT
public:
    HerbCard(const Herb& aValue, QWidget* parent = nullptr);
private:
    Herb value;

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
    LabelImage* lff;
    LabelImage* uses;

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // HERBCARD_H
