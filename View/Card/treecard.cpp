#include "treecard.h"

TreeCard::TreeCard(const Tree& aValue, QWidget* parent)
    : value{aValue}, QWidget{parent}
{
    QHBoxLayout* layout{new QHBoxLayout};
    QVBoxLayout* leftSide{new QVBoxLayout};
    QVBoxLayout* rightSide{new QVBoxLayout};
    QHBoxLayout* header{new QHBoxLayout};
    QHBoxLayout* hcs{new QHBoxLayout};

    name = new QLabel{QString::fromStdString(Utility::displayfy(value.getName()))};
    name->setMargin(4);
    name->setObjectName("nameTreeCard");
    name->setMaximumHeight(80);


    type = new QLabel;
    QImage typeImage{":/Img/Images/Icons/tree.png"};
    type->setPixmap(QPixmap::fromImage(typeImage));
    type->setObjectName("typeCard");
    type->setFixedSize(40, 40);
    type->setScaledContents(true);

    //score
    QString scoreIcon;
    if (value.score() == 1)
        scoreIcon = ":/Img/Images/Icons/bronze.png" ;
    else if (value.score() == 2)
        scoreIcon = ":/Img/Images/Icons/silver.png";
    else
        scoreIcon = ":/Img/Images/Icons/gold.png";

    score = new QLabel;
    QImage scoreImage{scoreIcon};
    score->setPixmap(QPixmap::fromImage(scoreImage));
    score->setObjectName("scoreCard");
    score->setFixedSize(40, 40);
    score->setScaledContents(true);

    //size
    Size organismSize{value.size()};
    QString sizeIcon;
    if (organismSize == Size::LARGE)
        sizeIcon = ":/Img/Images/Icons/extra-large.png" ;
    else if (organismSize == Size::MEDIUM)
        sizeIcon = ":/Img/Images/Icons/medium.png";
    else
        sizeIcon = ":/Img/Images/Icons/small.png";

    QImage sizeImage{sizeIcon};
    size = new QLabel;
    size->setPixmap(QPixmap::fromImage(sizeImage));
    size->setObjectName("sizeCard");
    size->setFixedSize(40, 40);
    size->setScaledContents(true);

    header->addWidget(name);
    header->addWidget(type);
    header->addWidget(score);
    header->addWidget(size);

    //taxonomy
    taxonomy = new QLabel{
        tr("Taxonomy: \n\nOrder:       ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[3])) + '\n' +
        tr("Family:     ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[2])) + '\n' +
        tr("Genus:     ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[1])) + '\n' +
        tr("Species:   ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[0])) + '\n'
    };
    taxonomy->setMargin(8);
    taxonomy->setObjectName("taxonomyCard");


    //dimension
    dimension = new QLabel {
        tr("Physical attributes: \n\nLength:      ") + QString::number(value.getLength(), 'f', 3) + "m\n" +
        tr("Diameter: ") + QString::number(value.getDiameter(), 'f', 3)
    };
    dimension->setMargin(8);
    dimension->setObjectName("dimensionCard");

    //habitat
    QString habitatIcon;
    switch (static_cast<int>(value.getHabitat())) {
    case 0:
        habitatIcon = ":/Img/Images/Icons/forest.png";
        break;
    case 1:
        habitatIcon = ":/Img/Images/Icons/scrubland.png";
        break;
    case 2:
        habitatIcon = ":/Img/Images/Icons/grassland.png";
        break;
    case 3:
        habitatIcon = ":/Img/Images/Icons/wetland.png";
        break;
    case 4:
        habitatIcon = ":/Img/Images/Icons/mountain.png";
        break;
    case 5:
        habitatIcon = ":/Img/Images/Icons/aquatic.png";
        break;
    case 6:
        habitatIcon = ":/Img/Images/Icons/urban.png";
        break;
    }

    QImage habitatImage{habitatIcon};
    habitat = new QLabel;
    habitat->setPixmap(QPixmap::fromImage(habitatImage));
    habitat->setObjectName("habitatCard");
    habitat->setFixedSize(70, 70);
    habitat->setAlignment(Qt::AlignCenter);
    habitat->setScaledContents(true);

    //cs
    QString csIcon;
    switch (static_cast<int>(value.getCs())) {
    case 0:
        csIcon = ":/Img/Images/Icons/ne.png";
        break;
    case 1:
        csIcon = ":/Img/Images/Icons/dd.png";
        break;
    case 2:
        csIcon = ":/Img/Images/Icons/lc.png";
        break;
    case 3:
        csIcon = ":/Img/Images/Icons/nt.png";
        break;
    case 4:
        csIcon = ":/Img/Images/Icons/vu.png";
        break;
    case 5:
        csIcon = ":/Img/Images/Icons/en.png";
        break;
    case 6:
        csIcon = ":/Img/Images/Icons/cr.png";
        break;
    case 7:
        csIcon = ":/Img/Images/Icons/ew.png";
        break;
    case 8:
        csIcon = ":/Img/Images/Icons/ex.png";
        break;
    }

    QImage csImage{csIcon};
    cs = new QLabel;
    cs->setPixmap(QPixmap::fromImage(csImage));
    cs->setObjectName("csCard");
    cs->setFixedSize(200, 70);
    cs->setAlignment(Qt::AlignCenter);
    cs->setScaledContents(true);

    description = new QLabel{QString::fromStdString(aValue.getDescription())};
    description->setMinimumHeight(500);
    description->setWordWrap(true);
    description->setMargin(10);
    description->setObjectName("descriptionCard");
    description->setAlignment(Qt::AlignTop);


    hcs->addWidget(habitat);
    hcs->addWidget(cs);

    leftSide->addLayout(header);
    leftSide->addWidget(taxonomy);
    leftSide->addWidget(dimension);
    leftSide->addLayout(hcs);
    leftSide->addWidget(description);

    //right side
    image = new QLabel;
    QImage photo{QString::fromStdString(value.getImgPath())};
    QImage out(photo.width(), photo.height(), QImage::Format_ARGB32);
    out.fill(Qt::transparent);

    QBrush brush(photo);

    QPen pen;
    pen.setColor(Qt::white);
    pen.setJoinStyle(Qt::RoundJoin);

    QPainter painter(&out);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRoundedRect(0, 0, photo.width(), photo.height(), 40, 40);

    image->setPixmap(QPixmap::fromImage(out));
    image->setObjectName("imageCard");
    image->setScaledContents(true);

    std::vector<QString> v{QString::fromStdString(value.getLffImgPath()[0]),
                           QString::fromStdString(value.getLffImgPath()[1]),
                           QString::fromStdString(value.getLffImgPath()[2])};
    lff = new LabelImage{tr("Leaf - Flower - Fruit"), v};
    lff->setMaximumSize(500, 220);

    rightSide->addWidget(image);
    rightSide->addWidget(lff, 0, Qt::AlignCenter);
    rightSide->setAlignment(Qt::AlignTop);

    layout->addLayout(leftSide);
    layout->addSpacing(20);
    layout->addLayout(rightSide);

    setLayout(layout);
}

void TreeCard::paintEvent(QPaintEvent* e)
{
    QStyleOption option;
    option.initFrom(this);
    QPainter painter{this};
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
