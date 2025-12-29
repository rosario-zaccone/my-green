#include "tree.h"
#include <stdexcept>

Tree::Tree(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::array<std::string, 3>& aLffImgPath,
    double aDiameter
    )
    : Plant{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aLffImgPath},
    diameter{aDiameter}
{
    if (aDiameter <= 0.0)
        throw std::invalid_argument{"diameter must be positive"};
}

double Tree::getDiameter() const
{
    return diameter;
}

void Tree::setDiameter(double aDiameter)
{
    if (aDiameter <= 0.0)
        throw std::invalid_argument{"diameter must be positive"};
    diameter = aDiameter;
}

unsigned int Tree::score() const
{
    return isRare() ? std::lround(1 + getLength()/30.0 + diameter) : std::lround(getLength()/30.0 + diameter);
}

Size Tree::size() const
{
    if (getLength() + diameter < 7)
        return Size::SMALL;
    if (getLength() + diameter <= 14)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Tree::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Tree::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Tree *Tree::clone() const
{
    return new Tree{*this};
}
