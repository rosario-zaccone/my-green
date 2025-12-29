#ifndef CARDVISITOR_H
#define CARDVISITOR_H

#include <QWidget>
#include "Model/Core/iconstvisitor.h"
#include "Model/Core/organism.h"
#include "View/Card/amphibiancard.h"
#include "View/Card/birdcard.h"
#include "View/Card/mammalcard.h"
#include "View/Card/reptilecard.h"
#include "View/Card/herbcard.h"
#include "View/Card/treecard.h"


class CardVisitor : public IConstVisitor
{
public:

    void visit(const Amphibian& amphibian) override;
    void visit(const Bird& bird) override;
    void visit(const Mammal& amphibian) override;
    void visit(const Reptile& amphibian) override;
    void visit(const Herb& herb) override;
    void visit(const Tree& tree) override;

    QWidget* getWidget() const;

private:
    QWidget* widget;
};

#endif // CARDVISITOR_H
