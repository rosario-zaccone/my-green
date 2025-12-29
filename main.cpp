#include "View/mainwindow.h"

#include <QApplication>
#include <iostream>
#include <vector>
#include "Model/JSONParser/jsonreader.h"
#include "Model/JSONParser/jsonwriter.h"
#include "Model/Core/bird.h"
#include "Model/Utilities/utility.h"
#include "Model/model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QFile file("/home/rosario/QTProjects/myGreen/style.css");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    file.close();
    a.setStyleSheet(styleSheet);
    return a.exec();

}
