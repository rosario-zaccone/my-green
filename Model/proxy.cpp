#include "proxy.h"
#include <iostream>

Proxy::Proxy(QObject* parent)
    : QSortFilterProxyModel{parent}, name{""}, type{"All"}, habitat{Habitat::NONE}, cs{Conservation::NONE}
{

}

bool Proxy::filterAcceptsRow(int sRow, const QModelIndex& sParent) const
{
    QModelIndex i = sourceModel()->index(sRow, 0, sParent);
    std::string key{sourceModel()->data(i).toString().toStdString()};
    Model* model{dynamic_cast<Model*>(sourceModel())};

    try {
        Organism* value{(model->getMemory()).at(Utility::keyfy(key))};
        TypeVisitor visitor{type};
        value->accept(visitor);
        std::string enteredName{Utility::lowerize(name)};
        std::string valueName{Utility::lowerize(Utility::displayfy(value->getName()))};
        return ((name == "" || valueName.find(enteredName) != std::string::npos)
                &&(habitat == Habitat::NONE || value->getHabitat() == habitat)
                && (cs == Conservation::NONE || value->getCs() == cs)
                && (type == "All" || visitor.getResult())
                && (family == "All" || (value->getTaxonomy())[static_cast<int>(Taxonomy::FAMILY)] == family));
    }
    catch (const std::out_of_range& ex) {
        return false;
    }
}

void Proxy::setName(const std::string& aName)
{
    name = aName;
    invalidateFilter();
}

void Proxy::setType(const std::string& aType)
{
    type = aType;
    invalidateFilter();
}

void Proxy::setFamily(const std::string& aFamily)
{
    family = aFamily;
    invalidateFilter();
}

void Proxy::setHabitat(int index)
{
    habitat = static_cast<Habitat>(index);
    invalidateFilter();
}

void Proxy::setCs(int index)
{
    cs = static_cast<Conservation>(index);
    invalidateFilter();
}
