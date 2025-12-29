#ifndef JSONWRITER_H
#define JSONWRITER_H

#include "jsonwritevisitor.h"
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


class JSONWriter
{
public:
    JSONWriter(const std::string& aPath, const std::map<std::string, Organism*>& aElems);

    void writeJ() const;
private:
    const std::string path;
    std::map<std::string, Organism*> elems;
};

#endif // JSONWRITER_H
