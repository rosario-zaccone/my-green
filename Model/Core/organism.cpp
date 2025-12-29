#include "organism.h"
#include <stdexcept>

Organism::Organism(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity
    )
    : name{Utility::codify(aName)},
    habitat{aHabitat},
    cs{aCs},
    length{aLength},
    imgPath{aImgPath},
    description{aDescription},
    rarity{aRarity}
{
    if (aLength <= 0.0)
        throw std::invalid_argument{"length must be positive"};
    for (int i{0}; i < 4; i++)
        taxonomy[i] = Utility::codify(aTaxonomy[i]);
}

std::string Organism::getName() const
{
    return name;
}

std::array<std::string, 4> Organism::getTaxonomy() const
{
    return taxonomy;
}

Habitat Organism::getHabitat() const
{
    return habitat;
}

void Organism::setHabitat(Habitat aHabitat)
{
    habitat = aHabitat;
}

Conservation Organism::getCs() const
{
    return cs;
}

void Organism::setCs(Conservation aCs)
{
    cs = aCs;
}

double Organism::getLength() const
{
    return length;
}

void Organism::setLength(double aLength)
{
    length = aLength;
}

std::string Organism::getImgPath() const
{
    return imgPath;
}

void Organism::setImgPath(const std::string& aImgPath)
{
    imgPath = aImgPath;
}

std::string Organism::getDescription() const
{
    return description;
}

void Organism::setDescription(const std::string& aDescription)
{
    description = aDescription;
}

bool Organism::isRare() const
{
    return rarity;
}

void Organism::setRarity(bool aRarity)
{
    rarity = aRarity;
}

std::string Organism::getId()
{
    return Utility::keyfy(name);
}
