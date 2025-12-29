#ifndef REPTILE_H
#define REPTILE_H

#include "animal.h"

enum class Scale{
    TUBERCULAR = 0, // tubercoliformi
    SHIELDED,  // scudate
    IMBRICATED, // embricate
    ARMORED  // corazzate
};

class Reptile : public Animal
{
public:
    Reptile() = default;
    Reptile(
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
        Scale aScaleType
        );
    ~Reptile() = default;

    Scale getScaleType() const;
    void setScaleType(Scale aScaleType);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Reptile* clone() const override;
private:
    Scale scaleType;
};

#endif // REPTILE_H
