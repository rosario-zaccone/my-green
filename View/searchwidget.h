#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QObject>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>
#include <set>
#include "./Model/Core/organism.h"

class SearchWidget : public QWidget
{
    Q_OBJECT

public:
    SearchWidget(QWidget* parent = nullptr);

    std::string getName() const;
    std::string getType() const;
    int getHabitat() const;
    int getCs() const;
public slots:
    void typeChanger(int index);
    void search();
signals:
    void typeChanged(int index);
    void startSearch(const std::string& aName, const std::string& aType, int aHabitat, int aCs);
private:

    QLineEdit* name;
    QComboBox* type;
    QComboBox* cs;
    QComboBox* habitat;
    QPushButton* start;

    QLabel* nameLabel;
    QLabel* typeLabel;
    QLabel* csLabel;
    QLabel* habitatLabel;
protected:
    void paintEvent(QPaintEvent* e);
};

#endif // SEARCHWIDGET_H
