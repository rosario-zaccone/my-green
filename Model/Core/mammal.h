#ifndef MAMMAL_H
#define MAMMAL_H

#include "animal.h"

class Mammal : public Animal
{
public:
    Mammal() = default;
    Mammal(
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
        const std::string& footprintImgPath
        );
    ~Mammal() = default;

    std::string getFootprintImgPath() const;
    void setFootprintImgPath(const std::string& aFootprintImgPath);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Mammal* clone() const override;

private:
    std::string footprintImgPath;
};

#endif // MAMMAL_H
