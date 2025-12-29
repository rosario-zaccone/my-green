#include "bird.h"
#include <stdexcept>

Bird::Bird(
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
    double aWingspan
    )
    : Animal{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aNoisePath, aWeight},
    wingspan{aWingspan}
{
    if (aWingspan <= 0)
        throw std::invalid_argument{"wingspan must be positive"};
}

double Bird::getWingspan() const
{
    return wingspan;
}

void Bird::setWingspan(double aWingspan)
{
    wingspan = aWingspan;
}

unsigned int Bird::score() const
{
    return isRare() ? std::lround(1.5 + wingspan/2) : std::lround(wingspan/2);
}

Size Bird::size() const
{
    if (getLength() <= 0.25)
        return Size::SMALL;
    if (getLength() <= 0.50)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Bird::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Bird::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Bird *Bird::clone() const
{
    return new Bird{*this};
}
