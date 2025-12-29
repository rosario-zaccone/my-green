#include "herb.h"

Herb::Herb(
    const std::string &aName,
    const std::array<std::string, 4> &aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string &aImgPath,
    const std::string &aDescription,
    bool aRarity,
    const std::array<std::string, 3>& aLffImgPath,
    const std::array<bool, 3>& aUses
    )
    : Plant{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aLffImgPath},
    uses{aUses}
{

}

std::array<bool, 3> Herb::getUses() const
{
    return uses;
}

void Herb::setUses(const std::array<bool, 3>& aUses)
{
    uses = aUses;
}

unsigned int Herb::score() const
{
    double bonus{0.0};
    for (int i{0}; i < 3; i++) {
        if (uses[i])  bonus++;
    }
    return isRare() ? std::lround(1 + bonus/2.0) : std::lround(bonus/2.0);
}

Size Herb::size() const
{
    if (getLength() < 0.61)
        return Size::SMALL;
    if (getLength() <= 0.85)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Herb::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Herb::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Herb *Herb::clone() const
{
    return new Herb{*this};
}
