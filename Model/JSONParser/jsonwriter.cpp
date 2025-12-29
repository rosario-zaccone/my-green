#include "jsonwriter.h"

JSONWriter::JSONWriter(const std::string& aPath, const std::map<std::string, Organism*>& aElems)
    : path{aPath},
    elems{aElems}
{

}

void JSONWriter::writeJ() const
{
    JSONWriteVisitor visitor;
    QJsonArray items;
    QJsonObject obj;
    for (auto it = elems.begin(); it != elems.end(); it++) {
        it->second->accept(visitor);
        obj = visitor.getObj();
        items.push_back(obj);
    }

    QJsonDocument doc{items};
    QFile fout{path.c_str()};
    fout.open(QIODevice::WriteOnly);
    fout.write(doc.toJson());
    fout.close();
}
