#include "animal.h"
#include <stdexcept>

Animal::Animal(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::string& aNoisePath,
    double aWeight
    )
    : Organism{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity},
    noisePath{aNoisePath},
    weight{aWeight}
{
    if (aWeight <= 0.0)
        throw std::invalid_argument{"weight must be positive"};
}

std::string Animal::getNoisePath() const {
    return noisePath;
}

void Animal::setNoisePath(const std::string& aNoisePath) {
    noisePath = aNoisePath;
}

double Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(double aWeight) {
    if (aWeight <= 0.0)
        throw std::invalid_argument{"weight must be positive"};
    weight = aWeight;
}
