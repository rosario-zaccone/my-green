#ifndef MODEL_H
#define MODEL_H

#include "JSONParser/jsonreader.h"
#include "JSONParser/jsonwriter.h"
#include "typevisitor.h"
#include "./Core/organism.h"
#include <QAbstractListModel>
#include <set>
#include <map>

class Model : public QAbstractListModel
{
    Q_OBJECT
public:
    Model(const std::string& aPath, QObject* parent = nullptr);
    Model(QObject* parent = nullptr);
    ~Model();

    void store() const;
    void store(const std::string& aPath) const;

    //DataResult search(const std::string& key, const std::string& type, const std::string& family, Habitat habitat, Conservation cs) const;
    std::set<std::string> allFamilies(const std::string& type) const;


    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    void insert(Organism* v);
    void remove(const std::string& k);
    std::map<std::string, Organism*> getMemory() const;
private:
    const std::string path;
    std::map<std::string, Organism*> memory;
};

#endif // MODEL_H
