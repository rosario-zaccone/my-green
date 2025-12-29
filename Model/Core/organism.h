#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <array>
#include "ivisitor.h"
#include "iconstvisitor.h"
#include <cmath>
#include "./Model/Utilities/utility.h"

enum class Habitat {
    FOREST = 0,
    SCRUBLAND,
    GRASSLAND,
    WETLAND,
    MOUNTAIN,
    AQUATIC,
    URBAN,
    NONE
};

enum class Conservation {
    NE = 0,
    DD,
    LC,
    NT,
    VU,
    EN,
    CR,
    EW,
    EX,
    NONE
};

enum class Size {
    SMALL = 0,
    MEDIUM,
    LARGE
};

enum class Taxonomy {
    SPECIES = 0,
    GENUS,
    FAMILY,
    ORDER
};

class Organism
{
public:
    Organism() = default;
    Organism(
        const std::string& aName,
        const std::array<std::string, 4>& aTaxonomy,
        Habitat aHabitat,
        Conservation aCs,
        double aLength,
        const std::string& aImgPath,
        const std::string& aDescription,
        bool aRarity
        );
    virtual ~Organism() = default;

    std::string getName() const;
    std::array<std::string, 4> getTaxonomy() const;
    Habitat getHabitat() const;
    void setHabitat(Habitat aHabitat);
    Conservation getCs() const;
    void setCs(Conservation aCs);
    double getLength() const;
    void setLength(double aLength);
    std::string getImgPath() const;
    void setImgPath(const std::string& aImgPath);
    std::string getDescription() const;
    void setDescription(const std::string& aDescription);
    bool isRare() const;
    void setRarity(bool aRarity);

    virtual unsigned int score() const = 0;
    virtual Size size() const = 0;
    virtual void accept(IVisitor& visitor) = 0;
    virtual void accept(IConstVisitor& visitor) const = 0;

    std::string getId();


    virtual Organism* clone() const = 0;
private:
    std::string name;
    std::array<std::string, 4> taxonomy;
    Habitat habitat;
    Conservation cs;
    double length;
    std::string imgPath;
    std::string description;
    bool rarity;
};

#endif // ORGANISM_H
