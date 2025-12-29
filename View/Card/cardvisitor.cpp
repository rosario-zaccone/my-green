#include "cardvisitor.h"
#include <iostream>

void CardVisitor::visit(const Amphibian& amphibian)
{
    widget = new AmphibianCard(amphibian);
}

void CardVisitor::visit(const Bird& bird)
{
    widget = new BirdCard(bird);
}

void CardVisitor::visit(const Mammal& mammal)
{
    widget = new MammalCard(mammal);
}

void CardVisitor::visit(const Reptile& reptile)
{
    widget = new ReptileCard(reptile);
}

void CardVisitor::visit(const Herb& herb)
{
    widget = new HerbCard(herb);
}

void CardVisitor::visit(const Tree& tree)
{
    widget = new TreeCard(tree);
}

QWidget* CardVisitor::getWidget() const
{
    return widget;
}
