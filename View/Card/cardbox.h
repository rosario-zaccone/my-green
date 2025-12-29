#ifndef CARDBOX_H
#define CARDBOX_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class CardBox : public QWidget
{
    Q_OBJECT
public:
    CardBox(QWidget* parent = nullptr);

    void setCard(QWidget* aCard);
private:
    QWidget* card;
    QVBoxLayout* layout;
};

#endif // CARDBOX_H
