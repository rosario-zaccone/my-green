QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/JSONParser/jsonreader.cpp \
    Model/Core/amphibian.cpp \
    Model/Core/animal.cpp \
    Model/Core/bird.cpp \
    Model/Core/herb.cpp \
    Model/JSONParser/jsonwriter.cpp \
    Model/JSONParser/jsonwritevisitor.cpp \
    Model/Utilities/utility.cpp \
    Model/model.cpp \
    Model/proxy.cpp \
    Model/typevisitor.cpp \
    View/Card/amphibiancard.cpp \
    View/Card/birdcard.cpp \
    View/Card/cardbox.cpp \
    View/Card/cardvisitor.cpp \
    View/Card/herbcard.cpp \
    View/Card/labelimage.cpp \
    View/Card/mammalcard.cpp \
    View/Card/reptilecard.cpp \
    View/Card/treecard.cpp \
    View/Edit/amphibianform.cpp \
    View/Edit/animalform.cpp \
    View/Edit/birdform.cpp \
    View/Edit/herbform.cpp \
    View/Edit/mammalform.cpp \
    View/Edit/plantform.cpp \
    View/Edit/removedialog.cpp \
    View/Edit/organismform.cpp \
    View/Edit/reptileform.cpp \
    View/Edit/treeform.cpp \
    View/searchwidget.cpp \
    View/mainwindow.cpp \
    Model/Core/mammal.cpp \
    Model/Core/organism.cpp \
    Model/Core/plant.cpp \
    Model/Core/reptile.cpp \
    Model/Core/tree.cpp \
    main.cpp

HEADERS += \
    Model/JSONParser/jsonreader.h \
    Model/Core/amphibian.h \
    Model/Core/animal.h \
    Model/Core/bird.h \
    Model/Core/herb.h \
    Model/Core/iconstvisitor.h \
    Model/Core/ivisitor.h \
    Model/JSONParser/jsonwriter.h \
    Model/JSONParser/jsonwritevisitor.h \
    Model/Utilities/utility.h \
    Model/model.h \
    Model/proxy.h \
    Model/typevisitor.h \
    View/Card/amphibiancard.h \
    View/Card/birdcard.h \
    View/Card/cardbox.h \
    View/Card/cardvisitor.h \
    View/Card/herbcard.h \
    View/Card/labelimage.h \
    View/Card/mammalcard.h \
    View/Card/reptilecard.h \
    View/Card/treecard.h \
    View/Edit/amphibianform.h \
    View/Edit/animalform.h \
    View/Edit/birdform.h \
    View/Edit/herbform.h \
    View/Edit/mammalform.h \
    View/Edit/plantform.h \
    View/Edit/removedialog.h \
    View/Edit/reptileform.h \
    View/Edit/treeform.h \
    View/mainwindow.h \
    Model/Core/mammal.h \
    Model/Core/organism.h \
    Model/Core/plant.h \
    Model/Core/reptile.h \
    Model/Core/tree.h \
    View/Edit/organismform.h \
    View/searchwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
