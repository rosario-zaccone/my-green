#ifndef ICONSTVISITOR_H
#define ICONSTVISITOR_H

class Amphibian;
class Bird;
class Mammal;
class Reptile;
class Herb;
class Tree;


class IConstVisitor {
public:
    virtual ~IConstVisitor() = default;
    virtual void visit(const Amphibian& amphibian) = 0;
    virtual void visit(const Bird& bird) = 0;
    virtual void visit(const Mammal& mammal) = 0;
    virtual void visit(const Reptile& reptile) = 0;
    virtual void visit(const Herb& herb) = 0;
    virtual void visit(const Tree& tree) = 0;
};

#endif // ICONSTVISITOR_H
