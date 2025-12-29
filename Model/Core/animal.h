#ifndef ANIMAL_H
#define ANIMAL_H

#include "organism.h"

class Animal : public Organism
{
public:
    Animal() = default;
    Animal(
        const std::string& aName,
        const std::array<std::string, 4>& aTaxonomy,
        Habitat aHabitat, Conservation aCs,
        double aLength, const std::string& aImgPath,
        const std::string& aDescription,
        bool aRarity,
        const std::string& aNoisePath,
        double aWeight
        );
    ~Animal() = default;

    std::string getNoisePath() const;
    void setNoisePath(const std::string& aNoisePath);
    double getWeight() const;
    void setWeight(double aWeight);



private:
    std::string noisePath;
    double weight;
};

#endif // ANIMAL_H
