#include "reptile.h"

Reptile::Reptile(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat, Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::string& aNoisePath,
    double aWeight,
    Scale aScaleType
    )
    : Animal{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aNoisePath, aWeight},
    scaleType{aScaleType}
{

}

Scale Reptile::getScaleType() const
{
    return scaleType;
}

void Reptile::setScaleType(Scale aScaleType)
{
    scaleType = aScaleType;
}

unsigned int Reptile::score() const
{
    double bonus{0.0};
    if (scaleType != Scale::SHIELDED)
        bonus = 1.5;
    return isRare() ? std::lround(1.5 + bonus) : std::lround(bonus);
}

Size Reptile::size() const
{
    if (getLength() < 0.6)
        return Size::SMALL;
    if (getLength() < 1.2)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Reptile::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Reptile::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Reptile *Reptile::clone() const
{
    return new Reptile{*this};
}
