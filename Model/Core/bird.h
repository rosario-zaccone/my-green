#ifndef BIRD_H
#define BIRD_H

#include "animal.h"

class Bird : public Animal
{
public:
    Bird() = default;
    Bird(
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
        double aWingspan
        );
    ~Bird() = default;

    double getWingspan() const;
    void setWingspan(double aWingspan);

    unsigned int score() const override;
    Size size() const override;
    void accept(IVisitor& visitor) override;
    void accept(IConstVisitor& visitor) const override;

    Bird* clone() const override;
private:
    double wingspan;
};


#endif // BIRD_H
