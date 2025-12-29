#include "labelimage.h"

LabelImage::LabelImage(const QString& aTitle, const std::vector<QString>& imgPath, QWidget* parent)
    : QWidget{parent}
{
    QVBoxLayout* layout{new QVBoxLayout};
    QHBoxLayout* imgLayout{new QHBoxLayout};

    title = new QLabel{aTitle};
    title->setMinimumHeight(40);
    title->setAlignment(Qt::AlignCenter);
    title->setAttribute(Qt::WA_TranslucentBackground);
    title->setObjectName("titleImageCard");
    layout->addWidget(title);

    for (int i{0}; i < imgPath.size(); i++) {
        images.push_back(new QLabel);

        QImage photo{imgPath[i]};
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

        images[i]->setPixmap(QPixmap::fromImage(out));
        images[i]->setObjectName("imageCard");
        images[i]->setScaledContents(true);

        imgLayout->addWidget(images[i]);
    }
    layout->addLayout(imgLayout);
    setLayout(layout);
}

void LabelImage::paintEvent(QPaintEvent* e)
{
    QStyleOption option;
    option.initFrom(this);
    QPainter painter{this};
    style()->drawPrimitive(QStyle::PE_Widget, &option, &painter, this);
}
