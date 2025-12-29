#ifndef TYPEVISITOR_H
#define TYPEVISITOR_H

#include "Core/iconstvisitor.h"
#include <string>


class TypeVisitor : public IConstVisitor
{
private:
    std::string type;
    bool result;
public:
    TypeVisitor(const std::string& aType);

    void visit(const Amphibian &amphibian) override;
    void visit(const Bird& bird) override;
    void visit(const Mammal& mammal) override;
    void visit(const Reptile& reptile) override;
    void visit(const Herb& herb) override;
    void visit(const Tree& tree) override;

    bool getResult() const;
};

#endif // TYPEVISITOR_H
