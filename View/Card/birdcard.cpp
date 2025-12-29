#include "birdcard.h"


BirdCard::BirdCard(const Bird& aValue, QWidget* parent)
    : value{aValue}, QWidget{parent}
{
    QGridLayout* layout{new QGridLayout};
    QHBoxLayout* icons{new QHBoxLayout};

    name = new QLabel{QString::fromStdString(Utility::displayfy(value.getName()))};
    name->setMargin(2);
    name->setObjectName("nameBirdCard");


    type = new QLabel;
    QImage typeImage{":/Img/Images/Icons/feather.png"};
    type->setPixmap(QPixmap::fromImage(typeImage));
    type->setObjectName("typeCard");
    type->setMaximumSize(34, 34);
    type->setScaledContents(true);

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
    score->setMaximumSize(34, 34);
    score->setScaledContents(true);

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
    size->setMaximumSize(34, 34);
    size->setScaledContents(true);

    taxonomy = new QLabel{
        tr("Taxonomy: \n\nOrder:       ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[3])) + '\n' +
        tr("Family:     ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[2])) + '\n' +
        tr("Genus:     ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[1])) + '\n' +
        tr("Species:   ") + QString::fromStdString(Utility::displayfy(value.getTaxonomy()[0])) + '\n'
    };
    taxonomy->setMargin(2);
    taxonomy->setObjectName("taxonomyCard");

    dimension = new QLabel {
        tr("Physical attributes: \n\nLength:      ") + QString::number(value.getLength(), 'f', 3) + "m\n" +
        tr("Weight:      ") + QString::number(value.getWeight(), 'f', 3) + "kg\n" +
        tr("Wingspan:    ") + QString::number(value.getWingspan(), 'f', 3) + "m\n"
    };
    dimension->setMargin(2);
    dimension->setObjectName("dimensionCard");

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
    habitat->setMaximumSize(70, 70);
    habitat->setScaledContents(true);

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
    cs->setScaledContents(true);

    description = new QLabel{QString::fromStdString(aValue.getDescription())};
    description->setWordWrap(true);
    description->setMargin(2);
    description->setObjectName("descriptionCard");
    description->setAlignment(Qt::AlignTop);


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

    noiseButton = new QPushButton;
    noiseButton->setObjectName("buttonCard");
    noiseButton->setMinimumSize(180, 180);

    noise = new QSoundEffect;
    noise->setSource(QUrl::fromLocalFile(QString::fromStdString(value.getNoisePath())));
    noise->setVolume(50);

    icons->addWidget(type);
    icons->addWidget(score);
    icons->addWidget(size);

    layout->addWidget(name, 0, 0, 1, 4);
    layout->addLayout(icons, 0, 4, 1, 2);
    layout->addWidget(taxonomy, 1, 0, 2, 6);
    layout->addWidget(dimension, 3, 0, 1, 6);
    layout->addWidget(habitat, 4, 0, 1, 1);
    layout->addWidget(cs, 4, 1, 1, 5);
    layout->addWidget(description, 5, 0, 5, 6);

    layout->addWidget(image, 0, 6, 6, 9);
    layout->addWidget(noiseButton, 6, 6, 4, 9, Qt::AlignCenter);

    setLayout(layout);

    connect(noiseButton, &QPushButton::clicked, noise, &QSoundEffect::play);
}

void BirdCard::paintEvent(QPaintEvent* e)
{
    QStyleOption option;
    option.initFrom(this);
    QPainter painter{this};
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}


