#ifndef PROXY_H
#define PROXY_H

#include <QSortFilterProxyModel>
#include "./Core/organism.h"
#include "model.h"
#include "typevisitor.h"

class Proxy : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    Proxy(QObject* parent = nullptr);
    bool filterAcceptsRow(int sRow, const QModelIndex& sParent) const override;

    void setName(const std::string& aName);
    void setType(const std::string& aType);
    void setFamily(const std::string& aFamily);
    void setHabitat(int index);
    void setCs(int index);

public slots:

private:
    std::string name;
    std::string type;
    std::string family;
    Habitat habitat;
    Conservation cs;
};

#endif // PROXY_H
