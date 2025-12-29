#include "plant.h"

Plant::Plant(
    const std::string& aName,
    const std::array<std::string, 4>& aTaxonomy,
    Habitat aHabitat,
    Conservation aCs,
    double aLength,
    const std::string& aImgPath,
    const std::string& aDescription,
    bool aRarity,
    const std::array<std::string, 3>& aLffImgPath
    )
    : Organism{aName, aTaxonomy, aHabitat, aCs, aLength, aImgPath, aDescription, aRarity},
    lffImgPath{aLffImgPath}
{

}

std::array<std::string, 3> Plant::getLffImgPath() const
{
    return lffImgPath;
}

void Plant::setLffImgPath(const std::array<std::string, 3> &newLffImgPath)
{
    lffImgPath = newLffImgPath;
}
