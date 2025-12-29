#ifndef AMPHIBIANFORM_H
#define AMPHIBIANFORM_H

#include "animalform.h"

class AmphibianForm : public AnimalForm
{
    Q_OBJECT
public:
    AmphibianForm(QWidget* parent = nullptr);

    std::string getLsPath() const;
public slots:
    void loadLs();
    void updateLsStatus();
signals:
    void loadedLs();
private:
    QPushButton* lsButton;
    QString lsPath;
    QLabel* lsStatus;
};

#endif // AMPHIBIANFORM_H

