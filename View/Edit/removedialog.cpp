#include "removedialog.h"

RemoveDialog::RemoveDialog(QWidget* parent)
    : QDialog{parent}
{
    QHBoxLayout* inputLayout{new QHBoxLayout};
    QHBoxLayout* buttonLayout{new QHBoxLayout};
    QVBoxLayout* layout{new QVBoxLayout};

    label = new QLabel{"Name: "};

    name = new QLineEdit;
    name->setMinimumSize(100, 40);
    name->setObjectName("removeName");

    ok = new QPushButton{"Remove"};
    ok->setMinimumSize(100, 40);
    ok->setObjectName("removeButton");

    cancel = new QPushButton{"Exit"};
    cancel->setMinimumSize(100, 40);
    cancel->setObjectName("removeButton");

    inputLayout->addWidget(label);
    inputLayout->addWidget(name);
    buttonLayout->addWidget(ok);
    buttonLayout->addWidget(cancel);

    layout->addLayout(inputLayout);
    layout->addSpacing(60);
    layout->addLayout(buttonLayout);

    setLayout(layout);
    setModal(true);
    connect(ok, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancel, &QPushButton::clicked, this, &QDialog::reject);

    setFixedSize(290, 120);
    setWindowTitle(tr("Remove an organism"));
}

std::string RemoveDialog::getName() const
{
    return name->text().toStdString();
}
