#ifndef ORGANISMFORM_H
#define ORGANISMFORM_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QCheckBox>
#include <QString>
#include <QPushButton>
#include <QFormLayout>
#include <QFileDialog>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "./Model/Utilities/utility.h"

class OrganismForm : public QDialog
{
    Q_OBJECT
public:
    OrganismForm(QWidget* parent = nullptr);


    std::string getName() const;
    std::string getSpecies() const;
    std::string getGenus() const;
    std::string getFamily() const;
    std::string getOrder() const;
    int getHabitat() const;
    int getCs() const;
    double getLength() const;
    std::string getImgPath() const;
    std::string getDescription() const;
    bool getRarity() const;

public slots:
    void loadImg();
    void updateImgStatus();
signals:
    void loadedImg();
private:
    QLineEdit* name;

    QLineEdit* species;
    QLineEdit* genus;
    QLineEdit* family;
    QLineEdit* order;

    QComboBox* habitat;
    QComboBox* cs;

    QDoubleSpinBox* length;
    QString imgPath;
    QPushButton* imgButton;
    QLabel* imgStatus;

    QTextEdit* description;
    QCheckBox* rarity;

    QPushButton* add;
    QPushButton* exit;
protected:
    QFormLayout* form;
};

#endif // ORGANISMFORM_H
