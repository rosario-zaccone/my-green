#ifndef AMPHIBIAN_H
#define AMPHIBIAN_H

#include "animal.h"

class Amphibian : public Animal
{
public:
    Amphibian() = default;
    Amphibian(
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
        const std::string& aLarvalStageImgPath
        );
    ~Amphibian() = default;

    std::string getLarvalStageImgPath() const;
    void setLarvalStageImgPath(const std::string& aLarvalStageImgPath);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Amphibian* clone() const override;

private:
    std::string larvalStageImgPath;
};

#endif // AMPHIBIAN_H
