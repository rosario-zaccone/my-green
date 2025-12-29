#include "mammal.h"

Mammal::Mammal(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::string& aNoisePath,
    double aWeight,
    const std::string& aFootprintImgPath
    )
    : Animal{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aNoisePath, aWeight},
    footprintImgPath{aFootprintImgPath}
{

}

std::string Mammal::getFootprintImgPath() const
{
    return footprintImgPath;
}

void Mammal::setFootprintImgPath(const std::string& aFootprintImgPath)
{
    footprintImgPath = aFootprintImgPath;
}

unsigned int Mammal::score() const
{
    return isRare() ? 3 : 2;
}

Size Mammal::size() const
{
    if (getWeight() < 2.0)
        return Size::SMALL;
    if (getWeight() < 5.0)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Mammal::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Mammal::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Mammal *Mammal::clone() const
{
    return new Mammal{*this};
}
