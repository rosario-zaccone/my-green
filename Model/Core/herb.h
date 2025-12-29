#ifndef HERB_H
#define HERB_H

#include "plant.h"
#include <array>

enum class Use {
    CULINARY,
    COSMETIC,
    MEDICINAL
};

class Herb : public Plant
{
public:
    Herb()  = default;
    Herb(
        const std::string& aName,
        const std::array<std::string, 4>& aTaxonomy,
        Habitat aHabitat,
        Conservation aCs,
        double aLength,
        const std::string& aImgPath,
        const std::string& aDescription,
        bool aRarity,
        const std::array<std::string, 3>& aLffImgPath,
        const std::array<bool, 3>& aUses
        );
    ~Herb() = default;

    std::array<bool, 3> getUses() const;
    void setUses(const std::array<bool, 3> &aUses);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Herb* clone() const override;

private:
    std::array<bool, 3> uses;
};

#endif // HERB_H
