#include "amphibian.h"

Amphibian::Amphibian(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat, Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::string& aNoisePath,
    double aWeight,
    const std::string& aLarvalStageImgPath
    )
    : Animal{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity, aNoisePath, aWeight},
    larvalStageImgPath{aLarvalStageImgPath}
{

}

std::string Amphibian::getLarvalStageImgPath() const
{
    return larvalStageImgPath;
}

void Amphibian::setLarvalStageImgPath(const std::string& aLarvalStageImgPath)
{
    larvalStageImgPath = aLarvalStageImgPath;
}

unsigned int Amphibian::score() const
{
    double bonus{0.0};
    if (getHabitat() == Habitat::GRASSLAND)
        bonus = 1.5;
    return isRare() ? std::lround(1.5 + bonus) : std::lround(bonus);
}

Size Amphibian::size() const
{
    if (getLength() <= 0.05)
        return Size::SMALL;
    if (getLength() <= 30.0)
        return Size::MEDIUM;
    return Size::LARGE;
}

void Amphibian::accept(IVisitor& visitor)
{
    visitor.visit(*this);
}

void Amphibian::accept(IConstVisitor& visitor) const
{
    visitor.visit(*this);
}

Amphibian *Amphibian::clone() const
{
    return new Amphibian{*this};
}
