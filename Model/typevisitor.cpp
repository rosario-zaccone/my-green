#include "typevisitor.h"


TypeVisitor::TypeVisitor(const std::string& aType)
    : type{aType}, result{false}
{

}

void TypeVisitor::visit(const Amphibian& amphibian)
{
    result = type == "Amphibian";
}

void TypeVisitor::visit(const Bird& bird)
{
    result = type == "Bird";
}

void TypeVisitor::visit(const Mammal& mammal)
{
    result = type == "Mammal";
}

void TypeVisitor::visit(const Reptile& reptile)
{
    result = type == "Reptile";
}

void TypeVisitor::visit(const Herb& herb)
{
    result = type == "Herb";
}

void TypeVisitor::visit(const Tree& tree)
{
    result = type == "Tree";
}

bool TypeVisitor::getResult() const
{
    return result;
}
