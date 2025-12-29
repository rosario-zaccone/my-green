#include "jsonwritevisitor.h"


QJsonObject JSONWriteVisitor::getObj() const
{
    return obj;
}

void JSONWriteVisitor::visit(const Amphibian& amphibian)
{
    QJsonArray tArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("amphibian"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(amphibian.getName())));
    for (const std::string& value: amphibian.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(amphibian.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(amphibian.getCs())));
    obj.insert("length", QJsonValue::fromVariant(amphibian.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(amphibian.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(amphibian.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(amphibian.isRare()));
    obj.insert("noisePath", QJsonValue::fromVariant(QString::fromStdString(amphibian.getNoisePath())));
    obj.insert("weight", QJsonValue::fromVariant(amphibian.getWeight()));
    obj.insert("larvalStageImgPath", QJsonValue::fromVariant(QString::fromStdString(amphibian.getLarvalStageImgPath())));
}

void JSONWriteVisitor::visit(const Bird& bird)
{
    QJsonArray tArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("bird"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(bird.getName())));
    for (const std::string& value: bird.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(bird.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(bird.getCs())));
    obj.insert("length", QJsonValue::fromVariant(bird.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(bird.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(bird.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(bird.isRare()));
    obj.insert("noisePath", QJsonValue::fromVariant(QString::fromStdString(bird.getNoisePath())));
    obj.insert("weight", QJsonValue::fromVariant(bird.getWeight()));
    obj.insert("wingspan", QJsonValue::fromVariant(bird.getWingspan()));
}

void JSONWriteVisitor::visit(const Mammal& mammal)
{
    QJsonArray tArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("mammal"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(mammal.getName())));
    for (const std::string& value: mammal.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(mammal.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(mammal.getCs())));
    obj.insert("length", QJsonValue::fromVariant(mammal.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(mammal.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(mammal.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(mammal.isRare()));
    obj.insert("noisePath", QJsonValue::fromVariant(QString::fromStdString(mammal.getNoisePath())));
    obj.insert("weight", QJsonValue::fromVariant(mammal.getWeight()));
    obj.insert("footprintImgPath", QJsonValue::fromVariant(QString::fromStdString(mammal.getFootprintImgPath())));
}

void JSONWriteVisitor::visit(const Reptile& reptile)
{
    QJsonArray tArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("reptile"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(reptile.getName())));
    for (const std::string& value: reptile.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(reptile.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(reptile.getCs())));
    obj.insert("length", QJsonValue::fromVariant(reptile.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(reptile.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(reptile.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(reptile.isRare()));
    obj.insert("noisePath", QJsonValue::fromVariant(QString::fromStdString(reptile.getNoisePath())));
    obj.insert("weight", QJsonValue::fromVariant(reptile.getWeight()));
    obj.insert("scaleType", QJsonValue::fromVariant(static_cast<int>(reptile.getScaleType())));
}

void JSONWriteVisitor::visit(const Herb& herb)
{
    QJsonArray tArray;
    QJsonArray lffArray;
    QJsonArray uArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("herb"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(herb.getName())));
    for (const std::string& value: herb.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(herb.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(herb.getCs())));
    obj.insert("length", QJsonValue::fromVariant(herb.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(herb.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(herb.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(herb.isRare()));
    for (const std::string& value: herb.getLffImgPath()) {
        lffArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("lffImgPath", lffArray);
    for (bool value: herb.getUses()) {
        uArray.push_back(QJsonValue::fromVariant(value));
    }
    obj.insert("uses", uArray);
}

void JSONWriteVisitor::visit(const Tree& tree)
{
    QJsonArray tArray;
    QJsonArray lffArray;
    obj = QJsonObject{};
    obj.insert("type", QJsonValue::fromVariant("tree"));
    obj.insert("name", QJsonValue::fromVariant(QString::fromStdString(tree.getName())));
    for (const std::string& value: tree.getTaxonomy()) {
        tArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("taxonomy", tArray);
    obj.insert("habitat", QJsonValue::fromVariant(static_cast<int>(tree.getHabitat())));
    obj.insert("cs", QJsonValue::fromVariant(static_cast<int>(tree.getCs())));
    obj.insert("length", QJsonValue::fromVariant(tree.getLength()));
    obj.insert("imgPath", QJsonValue::fromVariant(QString::fromStdString(tree.getImgPath())));
    obj.insert("description", QJsonValue::fromVariant(QString::fromStdString(tree.getDescription())));
    obj.insert("rarity", QJsonValue::fromVariant(tree.isRare()));
    for (const std::string& value: tree.getLffImgPath()) {
        lffArray.push_back(QJsonValue::fromVariant(QString::fromStdString(value)));
    }
    obj.insert("lffImgPath", lffArray);
    obj.insert("diameter", QJsonValue::fromVariant(tree.getDiameter()));
}
