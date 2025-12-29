#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QObject>
#include <QtWidgets>
#include <vector>

class LabelImage : public QWidget
{
    Q_OBJECT
public:
    LabelImage(const QString& aTitle, const std::vector<QString>& imgPath, QWidget* parent = nullptr);
private:
    QLabel* title;
    std::vector<QLabel*> images;
protected:
    void paintEvent(QPaintEvent* e);
};

#endif // LABELIMAGE_H
