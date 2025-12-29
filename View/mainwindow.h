#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QMenu>
#include <QAction>
#include <QtWidgets>
#include "Model/model.h"
#include "Model/proxy.h"
#include "searchwidget.h"
#include "./Edit/removedialog.h"
#include "./Edit/amphibianform.h"
#include "./Edit/birdform.h"
#include "./Edit/mammalform.h"
#include "./Edit/reptileform.h"
#include "./Edit/herbform.h"
#include "./Edit/treeform.h"

#include "./Card/amphibiancard.h"
#include "./Card/birdcard.h"
#include "./Card/mammalcard.h"
#include "./Card/reptilecard.h"
#include "./Card/herbcard.h"
#include "./Card/treecard.h"
#include "./Card/cardvisitor.h"
#include "./Card/cardbox.h"

#include <QInputDialog>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);

public slots:
    void newFile();
    void open();
    void save();
    //void saveAs();
    //void exit();

    void removeData();

    void addAmphibian();
    void addBird();
    void addMammal();
    void addReptile();
    void addHerb();
    void addTree();

    void updateProxy(const std::string& aName, const std::string& aType, int aHabitat, int aCs);
    void selectionChanged(const QModelIndex& index);
private:
    Model* model;
    Proxy* proxy;
    QListView* view;

    QMenu* fileMenu;
    QMenu* addMenu;
    QMenu* editMenu;

    QAction* newAct;
    QAction* openAct;
    QAction* saveAct;
    QAction* removeAct;

    QAction* addAmphibianAct;
    QAction* addBirdAct;
    QAction* addMammalAct;
    QAction* addReptileAct;
    QAction* addHerbAct;
    QAction* addTreeAct;

    SearchWidget* searchBar;


    CardBox* cardBox;
    void createActions();
    void createMenus();

};
#endif // MAINWINDOW_H
