#ifndef JSONWRITEVISITOR_H
#define JSONWRITEVISITOR_H


#include "./Model/Core/iconstvisitor.h"
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

class JSONWriteVisitor : public IConstVisitor
{
public:
    JSONWriteVisitor() = default;

    QJsonObject getObj() const;

    void visit(const Amphibian& amphibian) override;
    void visit(const Bird& bird) override;
    void visit(const Mammal& mammal) override;
    void visit(const Reptile& reptile) override;
    void visit(const Herb& herb) override;
    void visit(const Tree& tree) override;
private:
    QJsonObject obj;
};

#endif // JSONWRITEVISITOR_H
