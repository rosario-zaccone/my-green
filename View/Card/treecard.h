#ifndef TREECARD_H
#define TREECARD_H


#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "labelimage.h"
#include "./Model/Core/tree.h"

class TreeCard : public QWidget
{
    Q_OBJECT
public:
    TreeCard(const Tree& aValue, QWidget* parent = nullptr);
private:
    Tree value;

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

protected:
    void paintEvent(QPaintEvent* e);
};

#endif // TREECARD_H
