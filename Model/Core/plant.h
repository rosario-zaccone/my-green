#ifndef PLANT_H
#define PLANT_H

#include "organism.h"

class Plant : public Organism
{
public:
    Plant() = default;
    Plant(
        const std::string& aName,
        const std::array<std::string, 4>& aTaxonomy,
        Habitat aHabitat,
        Conservation aCs,
        double aLength,
        const std::string& aImgPath,
        const std::string& aDescription,
        bool aRarity,
        const std::array<std::string, 3>& aLffImgPath
        );
    ~Plant() = default;

    std::array<std::string, 3> getLffImgPath() const;
    void setLffImgPath(const std::array<std::string, 3> &newLffImgPath);

private:
    std::array<std::string, 3> lffImgPath; // leaf fruit flower
};

#endif // PLANT_H
