#include "searchwidget.h"

SearchWidget::SearchWidget(QWidget* parent)
    : QWidget{parent}
{
    QHBoxLayout* layout{new QHBoxLayout{this}};
    name = new QLineEdit;
    //name->setFixedSize(380, 29);
    name->setAlignment(Qt::AlignLeft);
    name->setObjectName("searchName");
    name->setMinimumSize(100, 40);

    nameLabel = new QLabel{tr("Name: ")};
    nameLabel->setFixedWidth(50);


    type = new QComboBox;
    type->addItem(tr("All"));
    type->addItem(tr("Amphibian"));
    type->addItem(tr("Bird"));
    type->addItem(tr("Mammal"));
    type->addItem(tr("Reptile"));
    type->addItem(tr("Herb"));
    type->addItem(tr("Tree"));
    type->setMinimumSize(100, 40);
    type->setObjectName("typeCombo");

    typeLabel = new QLabel{tr("Type: ")};
    typeLabel->setFixedWidth(50);

    habitat = new QComboBox;
    habitat->insertItem(7, tr("All"));
    habitat->insertItem(0, tr("Forest"));
    habitat->insertItem(1, tr("Scrubland"));
    habitat->insertItem(2, tr("Grassland"));
    habitat->insertItem(3, tr("Wetland"));
    habitat->insertItem(4, tr("Mountain"));
    habitat->insertItem(5, tr("Aquatic"));
    habitat->insertItem(6, tr("Urban"));
    habitat->setMinimumSize(100, 40);
    habitat->setObjectName("habitatCombo");

    habitatLabel = new QLabel{"Habitat: "};
    habitatLabel->setFixedWidth(70);

    cs = new QComboBox;
    cs->insertItem(9, tr("All"));
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
    cs->setObjectName("csCombo");

    csLabel = new QLabel{"Conservation status: "};
    csLabel->setFixedWidth(150);

    start = new QPushButton;
    start->setMinimumSize(100, 40);
    start->setObjectName("searchButton");

    layout->addWidget(nameLabel);
    layout->addWidget(name);
    layout->addSpacing(40);

    layout->addWidget(typeLabel);
    layout->addWidget(type);
    layout->addSpacing(40);

    layout->addWidget(habitatLabel);
    layout->addWidget(habitat);
    layout->addSpacing(40);

    layout->addWidget(csLabel);
    layout->addWidget(cs);
    layout->addStretch();

    layout->addStretch();

    layout->addWidget(start);
    layout->setAlignment(Qt::AlignLeft);
    setLayout(layout);

    connect(type, &QComboBox::currentIndexChanged, this, &SearchWidget::typeChanger);
    connect(start, &QPushButton::clicked, this, &SearchWidget::search);
}

std::string SearchWidget::getName() const
{
    return name->text().toStdString();
}

std::string SearchWidget::getType() const
{
    return type->currentText().toStdString();
}

int SearchWidget::getHabitat() const
{
    return habitat->currentIndex();
}

int SearchWidget::getCs() const
{
    return cs->currentIndex();
}

void SearchWidget::typeChanger(int index)
{
    emit typeChanged(index);
}

void SearchWidget::search()
{
    emit startSearch(name->text().toStdString(), type->currentText().toStdString(), habitat->currentIndex(), cs->currentIndex());
}

void SearchWidget::paintEvent(QPaintEvent* e)
{
    QStyleOption option;
    option.initFrom(this);
    QPainter painter{this};
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
