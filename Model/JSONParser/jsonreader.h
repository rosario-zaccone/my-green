#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <vector>
#include <qfile.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <qjsonvalue.h>
#include <qjsonobject.h>
#include "./Model/Core/amphibian.h"
#include "./Model/Core/bird.h"
#include "./Model/Core/mammal.h"
#include "./Model/Core/reptile.h"
#include "./Model/Core/herb.h"
#include "./Model/Core/tree.h"
#include <map>


class JSONReader
{
public:
    JSONReader(const std::string aPath);

    std::map<std::string, Organism*> readJ();
    Organism* readAmphibian(const QJsonObject& obj);
    Organism* readBird(const QJsonObject& obj);
    Organism* readMammal(const QJsonObject& obj);
    Organism* readReptile(const QJsonObject& obj);

    Organism* readHerb(const QJsonObject& obj);
    Organism* readTree(const QJsonObject& obj);

    std::string getPath() const;
private:
    const std::string path;
};

#endif // JSONREADER_H
