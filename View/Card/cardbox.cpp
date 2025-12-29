#include "cardbox.h"
#include <QVBoxLayout>

CardBox::CardBox(QWidget* parent)
    : QWidget{parent}
{
    layout = new QVBoxLayout;
    card = new QWidget;
    layout->addWidget(card);
    setLayout(layout);
}

void CardBox::setCard(QWidget* aCard)
{
    card = aCard;
    QLayoutItem* item;
    while ( (item = layout->takeAt( 0 )) != nullptr)
    {
        delete item->widget();
        delete item;
    }
    layout->addWidget(card);
}
