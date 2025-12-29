#ifndef IVISITOR_H
#define IVISITOR_H

class Amphibian;
class Bird;
class Mammal;
class Reptile;
class Herb;
class Tree;


class IVisitor {
public:
    virtual ~IVisitor() = default;
    virtual void visit(Amphibian& amphibian) = 0;
    virtual void visit(Bird& bird) = 0;
    virtual void visit(Mammal& mammal) = 0;
    virtual void visit(Reptile& reptile) = 0;
    virtual void visit(Herb& herb) = 0;
    virtual void visit(Tree& tree) = 0;
};

#endif // IVISITOR_H
