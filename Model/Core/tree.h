#ifndef TREE_H
#define TREE_H

#include "plant.h"

class Tree : public Plant
{
public:
    Tree() = default;
    Tree(
        const std::string& aName,
        const std::array<std::string, 4>& aTaxonomy,
        Habitat aHabitat,
        Conservation aCs,
        double aLength,
        const std::string& aImgPath,
        const std::string& aDescription,
        bool aRarity,
        const std::array<std::string, 3>& aLffImgPath,
        double aDiameter
        );
    ~Tree() = default;

    double getDiameter() const;
    void setDiameter(double aDiameter);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Tree* clone() const override;
private:
    double diameter;
};

#endif // TREE_H
