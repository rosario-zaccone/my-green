#ifndef REMOVEDIALOG_H
#define REMOVEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>
#include <QLabel>

class RemoveDialog : public QDialog
{
    Q_OBJECT
public:
    RemoveDialog(QWidget* parent = nullptr);
public:
    std::string getName() const;
private:
    QLabel* label;
    QLineEdit* name;
    QPushButton* ok;
    QPushButton* cancel;
};

#endif // REMOVEDIALOG_H
