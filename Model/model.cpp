#include "model.h"


Model::Model(const std::string& aPath, QObject* parent)
    : QAbstractListModel{parent}, path{aPath}
{
    JSONReader reader{aPath};
    memory = reader.readJ();
}

Model::Model(QObject* parent)
    : QAbstractListModel{parent}
{

}

Model::~Model()
{
    for (auto it{memory.begin()}; it != memory.end(); it++)
        delete it->second;
}

void Model::store() const
{
    JSONWriter writer{path, memory};
    writer.writeJ();
}

void Model::store(const std::string& aPath) const
{
    JSONWriter writer{aPath, memory};
    writer.writeJ();
}

std::set<std::string> Model::allFamilies(const std::string& type) const
{
    TypeVisitor visitor{type};
    std::set<std::string> families;
    for (auto it{memory.begin()}; it != memory.end(); it++) {
        if (type == "All") {
            families.insert((it->second->getTaxonomy())[static_cast<int>(Taxonomy::FAMILY)]);
        }
        else {
            it->second->accept(visitor);
            if (visitor.getResult())
                families.insert((it->second->getTaxonomy())[static_cast<int>(Taxonomy::FAMILY)]);
        }
    }

    return families;
}

int Model::rowCount(const QModelIndex& parent) const
{
    return memory.size();
}

QVariant Model::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant{};

    if (role == Qt::DisplayRole) {
        auto it = memory.begin();
        for (int i{0}; it != memory.end() && index.row() != i; it++, i++) { }
        QString str{QString::fromStdString(Utility::displayfy(it->second->getName()))};
        return str;
    }

    return QVariant{};
}


void Model::insert(Organism* v)
{
    if (memory.find(v->getId()) != memory.end())
        throw std::invalid_argument{"key is already in the data"};
    beginInsertRows(QModelIndex(), 0, 0);
    memory.insert({v->getId(), v});
    endInsertRows();
}

void Model::remove(const std::string& k)
{
    auto it = memory.find(k);
    if (it == memory.end())
        throw std::invalid_argument{"key is not in the dataset"};
    memory.erase(it);
}


std::map<std::string, Organism*> Model::getMemory() const
{
    return memory;
}


