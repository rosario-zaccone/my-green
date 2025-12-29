#include "organismform.h"

OrganismForm::OrganismForm(QWidget* parent)
    : QDialog{parent}
{
    form = new QFormLayout;
    QHBoxLayout* buttons{new QHBoxLayout};
    QVBoxLayout* layout{new QVBoxLayout};
    QHBoxLayout* imgLayout{new QHBoxLayout};

    name = new QLineEdit;
    name->setMinimumSize(100, 40);
    name->setMaxLength(30);
    name->setObjectName("addString");

    species = new QLineEdit;
    species->setMinimumSize(100, 40);
    species->setMaxLength(30);
    species->setObjectName("addString");

    genus = new QLineEdit;
    genus->setMinimumSize(100, 40);
    genus->setMaxLength(30);
    genus->setObjectName("addString");

    family = new QLineEdit;
    family->setMinimumSize(100, 40);
    family->setMaxLength(30);
    family->setObjectName("addString");

    order = new QLineEdit;
    order->setMinimumSize(100, 40);
    order->setMaxLength(30);
    order->setObjectName("addString");

    habitat = new QComboBox;
    habitat->insertItem(0, tr("Forest"));
    habitat->insertItem(1, tr("Scrubland"));
    habitat->insertItem(2, tr("Grassland"));
    habitat->insertItem(3, tr("Wetland"));
    habitat->insertItem(4, tr("Mountain"));
    habitat->insertItem(5, tr("Aquatic"));
    habitat->insertItem(6, tr("Urban"));
    habitat->setMinimumSize(100, 40);
    habitat->setObjectName("addCombo");

    cs = new QComboBox;
    cs->insertItem(0, tr("NE"));
    cs->insertItem(1, tr("DD"));
    cs->insertItem(2, tr("LC"));
    cs->insertItem(3, tr("NT"));
    cs->insertItem(4, tr("VU"));
    cs->insertItem(5, tr("EN"));
    cs->insertItem(6, tr("CR"));
    cs->insertItem(7, tr("EW"));
    cs->insertItem(8, tr("EX"));
    cs->setMinimumSize(100, 40);
    cs->setObjectName("addCombo");

    length = new QDoubleSpinBox;
    length->setMaximum(200.0);
    length->setMinimumSize(100, 40);
    length->setObjectName("addSpin");
    length->setDecimals(3);

    imgButton = new QPushButton{tr("Load")};
    imgButton->setMinimumSize(100, 40);
    imgButton->setObjectName("addButton");

    imgStatus = new QLabel;
    imgStatus->setMinimumSize(100, 40);
    imgStatus->setObjectName("addString");

    description = new QTextEdit;
    description->setMinimumSize(600, 100);
    description->setObjectName("addText");

    rarity = new QCheckBox;

    add = new QPushButton{tr("Add")};
    add->setMinimumSize(100, 40);
    add->setObjectName("addButton");

    exit = new QPushButton{tr("Exit")};
    exit->setMinimumSize(100, 40);
    exit->setObjectName("addButton");

    imgLayout->addWidget(imgButton);
    imgLayout->addWidget(imgStatus);


    form->addRow(tr("Name: "), name);
    form->addRow(tr("Species: "), species);
    form->addRow(tr("Genus: "), genus);
    form->addRow(tr("Family: "), family);
    form->addRow(tr("Order: "), order);
    form->addRow(tr("Habitat: "), habitat);
    form->addRow(tr("Conservation status: "), cs);
    form->addRow(tr("Length (m): "), length);
    form->addRow(tr("Image: "), imgLayout);
    form->addRow(tr("Description: "), description);
    form->addRow(tr("Rarity: "), rarity);

    buttons->addWidget(add);
    buttons->addWidget(exit);

    layout->addLayout(form);
    layout->addSpacing(60);
    layout->addLayout(buttons);

    connect(imgButton, &QPushButton::clicked, this, &OrganismForm::loadImg);
    connect(add, &QPushButton::clicked, this, &OrganismForm::accept);
    connect(exit, &QPushButton::clicked, this, &OrganismForm::reject);
    connect(this, &OrganismForm::loadedImg, this, &OrganismForm::updateImgStatus);

    setLayout(layout);

    setFixedSize(600, 880);
}

void OrganismForm::loadImg()
{

    QString absImgPath = QFileDialog::getOpenFileName(this, tr("Load an image"), "../myGreen/Media/Images", "Images (*.png, *.jpg)");
    QDir dir{QDir::currentPath()};
    imgPath = dir.relativeFilePath(absImgPath);
    emit loadedImg();
}

void OrganismForm::updateImgStatus()
{
    imgStatus->setText("Image loaded");
}

std::string OrganismForm::getName() const
{
    return Utility::codify(name->text().toStdString());
}

std::string OrganismForm::getSpecies() const
{
    return Utility::codify(species->text().toStdString());
}

std::string OrganismForm::getGenus() const
{
    return Utility::codify(genus->text().toStdString());
}

std::string OrganismForm::getFamily() const
{
    return Utility::codify(family->text().toStdString());
}

std::string OrganismForm::getOrder() const
{
    return Utility::codify(order->text().toStdString());
}

int OrganismForm::getHabitat() const
{
    return habitat->currentIndex();
}

int OrganismForm::getCs() const
{
    return cs->currentIndex();
}

double OrganismForm::getLength() const
{
    return length->value();
}

std::string OrganismForm::getImgPath() const
{
    return imgPath.toStdString();
}

std::string OrganismForm::getDescription() const
{
    return description->toPlainText().toStdString();
}

bool OrganismForm::getRarity() const
{
    return rarity->isChecked();
}
