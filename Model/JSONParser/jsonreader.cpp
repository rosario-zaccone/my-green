#include "jsonreader.h"


JSONReader::JSONReader(const std::string aPath)
    : path{aPath}
{

}

std::map<std::string, Organism*> JSONReader::readJ()
{
    std::map<std::string, Organism*> result;
    std::string type;

    QFile fin{path.c_str()};
    fin.open(QIODevice::ReadOnly);
    QByteArray data = fin.readAll();
    fin.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray items = doc.array();
    Organism* tmp;
    for (const QJsonValue& value: items) {
        QJsonObject obj = value.toObject();
        type = obj.value("type").toString().toStdString();
        if (type == "amphibian") {
            tmp = readAmphibian(obj);
            result.insert({tmp->getId(), tmp});
        }
        else if (type == "bird") {
            tmp = readBird(obj);
            result.insert({tmp->getId(), tmp});
        }
        else if (type == "mammal") {
            tmp = readMammal(obj);
            result.insert({tmp->getId(), tmp});
        }
        else if (type == "reptile") {
            tmp = readReptile(obj);
            result.insert({tmp->getId(), tmp});
        }
        else if (type == "herb") {
            tmp = readHerb(obj);
            result.insert({tmp->getId(), tmp});
        }
        else if (type == "tree") {
            tmp = readTree(obj);
            result.insert({tmp->getId(), tmp});
        }
    }

    return result;
}

Organism* JSONReader::readAmphibian(const QJsonObject& obj) {
    std::array<std::string, 4> taxonomy;
    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};
    std::string noisePath{obj.value("noisePath").toString().toStdString()};
    double weight{obj.value("weight").toDouble()};
    std::string larvalStageImgPath {obj.value("larvalStageImgPath").toString().toStdString()};

    return new Amphibian{name, taxonomy, habitat, cs, length, imgPath, description, rarity, noisePath, weight, larvalStageImgPath};
}

Organism* JSONReader::readBird(const QJsonObject& obj)
{
    std::array<std::string, 4> taxonomy;
    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};
    std::string noisePath{obj.value("noisePath").toString().toStdString()};
    double weight{obj.value("weight").toDouble()};
    double wingspan {obj.value("wingspan").toDouble()};

    return new Bird{name, taxonomy, habitat, cs, length, imgPath, description, rarity, noisePath, weight, wingspan};
}

Organism* JSONReader::readMammal(const QJsonObject &obj)
{
    std::array<std::string, 4> taxonomy;
    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};
    std::string noisePath{obj.value("noisePath").toString().toStdString()};
    double weight{obj.value("weight").toDouble()};
    std::string footprintImgPath{obj.value("footprintImgPath").toString().toStdString()};

    return new Mammal{name, taxonomy, habitat, cs, length, imgPath, description, rarity, noisePath, weight, footprintImgPath};
}

Organism* JSONReader::readReptile(const QJsonObject &obj)
{
    std::array<std::string, 4> taxonomy;
    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};
    std::string noisePath{obj.value("noisePath").toString().toStdString()};
    double weight{obj.value("weight").toDouble()};
    Scale scaleType{static_cast<Scale>(obj.value("footprintImgPath").toInt())};

    return new Reptile{name, taxonomy, habitat, cs, length, imgPath, description, rarity, noisePath, weight, scaleType};
}

Organism* JSONReader::readHerb(const QJsonObject &obj)
{
    std::array<std::string, 4> taxonomy;
    std::array<std::string, 3> lffImgPath;
    std::array<bool, 3> uses;
    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};

    QJsonArray lJArray{obj.value("lffImgPath").toArray()};
    for (int i{0}; i < 3; i++) {
        lffImgPath[i] = lJArray[0][i].toString().toStdString();
    }

    QJsonArray uJArray{obj.value("uses").toArray()};
    for (int i{0}; i < 3; i++) {
        uses[i] = uJArray[0][i].toBool();
    }

    return new Herb{name, taxonomy, habitat, cs, length, imgPath, description, rarity, lffImgPath, uses};
}

Organism* JSONReader::readTree(const QJsonObject &obj)
{
    std::array<std::string, 4> taxonomy;
    std::array<std::string, 3> lffImgPath;

    std::string name{obj.value("name").toString().toStdString()};
    QJsonArray tJArray{obj.value("taxonomy").toArray()};
    for (int i{0}; i < 4; i++) {
        taxonomy[i] = tJArray[0][i].toString().toStdString();
    }
    Habitat habitat{static_cast<Habitat>(obj.value("habitat").toInt())};
    Conservation cs{static_cast<Conservation>(obj.value("cs").toInt())};
    double length{obj.value("length").toDouble()};
    std::string imgPath{obj.value("imgPath").toString().toStdString()};
    std::string description{obj.value("description").toString().toStdString()};
    bool rarity{obj.value("rarity").toBool()};

    QJsonArray lJArray{obj.value("lffImgPath").toArray()};
    for (int i{0}; i < 3; i++) {
        lffImgPath[i] = lJArray[0][i].toString().toStdString();
    }

    double diameter{obj.value("diameter").toDouble()};

    return new Tree{name, taxonomy, habitat, cs, length, imgPath, description, rarity, lffImgPath, diameter};
}

std::string JSONReader::getPath() const
{
    return path;
}
