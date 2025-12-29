#include "mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    model{nullptr}
{
    model = new Model(this);
    proxy = new Proxy(this);


    QWidget* widget{new QWidget{this}};
    setCentralWidget(widget);

    QVBoxLayout* vlayout{new QVBoxLayout};
    QHBoxLayout* hlayout{new QHBoxLayout};
    vlayout->setContentsMargins(10, 10, 10, 10);

    view = new QListView;
    view->setFixedWidth(440);
    proxy->setSourceModel(model);

    view->setModel(proxy);
    view->show();

    cardBox = new CardBox;

    searchBar = new SearchWidget;


    hlayout->addWidget(view);
    hlayout->addSpacing(4);
    hlayout->addWidget(cardBox);
    vlayout->addWidget(searchBar);
    vlayout->addSpacing(4);
    vlayout->addLayout(hlayout);
    widget->setLayout(vlayout);

    connect(searchBar, &SearchWidget::startSearch, this, &MainWindow::updateProxy);
    connect(view, &QListView::clicked, this, &MainWindow::selectionChanged);

    createActions();
    createMenus();
    setWindowTitle(tr("myGreen"));
    setMinimumSize(1280, 900);
    resize(1280, 900);
}

void MainWindow::newFile()
{
    QString qPath{QFileDialog::getSaveFileName(this, tr("Create a new file"), "/", "Json (*.json)")};
    if (qPath.isEmpty())
        return;

    if (model != nullptr)
        delete model;

    model = new Model{qPath.toStdString(), this};
    proxy->setSourceModel(model);
    view->setModel(proxy);
    view->show();

    addMenu->setEnabled(true);
    editMenu->setEnabled(true);
}

void MainWindow::open()
{
    QString qPath{QFileDialog::getOpenFileName(this, tr("Open a file"), "/", "Json (*.json)")};
    if (qPath.isEmpty())
        return;

    if (model != nullptr)
        delete model;

    model = new Model{qPath.toStdString(), this};
    proxy->setSourceModel(model);

    view->setModel(proxy);
    view->show();

    addMenu->setEnabled(true);
    editMenu->setEnabled(true);
}

void MainWindow::save()
{
    model->store();
}


void MainWindow::removeData()
{
    RemoveDialog dialog;

    if(dialog.exec()) {
        try {
            model->remove(Utility::keyfy(dialog.getName()));
            QMessageBox okBox;
            okBox.setText(tr("Organism removed"));
            okBox.exec();
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr("The organism entered is not in the data"));
            errorBox.exec();
        }
    }
    emit searchBar->startSearch(searchBar->getName(), searchBar->getType(), searchBar->getHabitat(), searchBar->getCs());
}

void MainWindow::addAmphibian()
{
    AmphibianForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            Organism* v{new Amphibian{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                 form.getDescription(), form.getRarity(), form.getNoisePath(), form.getWeight(), form.getLsPath()}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}

void MainWindow::addBird()
{
    BirdForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            Organism* v{new Bird{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                 form.getDescription(), form.getRarity(), form.getNoisePath(), form.getWeight(), form.getWingspan()}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}

void MainWindow::addMammal()
{
    MammalForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            Organism* v{new Mammal{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                 form.getDescription(), form.getRarity(), form.getNoisePath(), form.getWeight(), form.getFootprintPath()}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}

void MainWindow::addReptile()
{
    ReptileForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            Organism* v{new Reptile{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                    form.getDescription(), form.getRarity(), form.getNoisePath(), form.getWeight(), static_cast<Scale>(form.getScaleType())}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}

void MainWindow::addHerb()
{
    HerbForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            std::array<std::string, 3> lff{form.getLeafPath(), form.getFlowerPath(), form.getFruitPath()};
            std::array<bool, 3> uses{form.isCulinary(), form.isCosmetic(), form.isMedicinal()};
            Organism* v{new Herb{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                 form.getDescription(), form.getRarity(), lff, uses}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}

void MainWindow::addTree()
{
    TreeForm form;
    if (form.exec()) {
        try {
            std::array<std::string, 4> taxonomy{form.getSpecies(), form.getGenus(), form.getFamily(), form.getOrder()};
            std::array<std::string, 3> lff{form.getLeafPath(), form.getFlowerPath(), form.getFruitPath()};
            Organism* v{new Tree{form.getName(), taxonomy, static_cast<Habitat>(form.getHabitat()), static_cast<Conservation>(form.getCs()), form.getLength(), form.getImgPath(),
                                 form.getDescription(), form.getRarity(), lff, form.getDiameter()}};
            model->insert(v);
        }
        catch (const std::invalid_argument& ex) {
            QMessageBox errorBox;
            errorBox.setText(tr(ex.what()));
            errorBox.exec();
        }
    }
}
void MainWindow::createActions()
{
    newAct = new QAction{tr("&New"), this};
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction{tr("&Open"), this};
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open a new file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction{tr("&Save"), this};
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the open file"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    removeAct = new QAction{tr("Remove"), this};
    removeAct->setStatusTip(tr("Remove an organism"));
    connect(removeAct, &QAction::triggered, this, &MainWindow::removeData);

    addAmphibianAct = new QAction{tr("Add Amphibian"), this};
    addAmphibianAct->setStatusTip(tr("Add an amphibian"));
    connect(addAmphibianAct, &QAction::triggered, this, &MainWindow::addAmphibian);

    addBirdAct = new QAction{tr("Add Bird"), this};
    addBirdAct->setStatusTip(tr("Add a bird"));
    connect(addBirdAct, &QAction::triggered, this, &MainWindow::addBird);

    addMammalAct = new QAction{tr("Add Mammal"), this};
    addMammalAct->setStatusTip(tr("Add a mammal"));
    connect(addMammalAct, &QAction::triggered, this, &MainWindow::addMammal);

    addReptileAct = new QAction{tr("Add Reptile"), this};
    addReptileAct->setStatusTip(tr("Add a reptile"));
    connect(addReptileAct, &QAction::triggered, this, &MainWindow::addReptile);

    addHerbAct = new QAction{tr("Add Herb"), this};
    addHerbAct->setStatusTip(tr("Add an herb"));
    connect(addHerbAct, &QAction::triggered, this, &MainWindow::addHerb);

    addTreeAct = new QAction{tr("Add Tree"), this};
    addTreeAct->setStatusTip(tr("Add a tree"));
    connect(addTreeAct, &QAction::triggered, this, &MainWindow::addTree);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);

    addMenu = menuBar()->addMenu(tr("Add"));
    addMenu->addAction(addAmphibianAct);
    addMenu->addAction(addBirdAct);
    addMenu->addAction(addMammalAct);
    addMenu->addAction(addReptileAct);
    addMenu->addAction(addHerbAct);
    addMenu->addAction(addTreeAct);
    addMenu->setEnabled(false);

    editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(removeAct);
    editMenu->setEnabled(false);
}

void MainWindow::updateProxy(const std::string& aName, const std::string& aType, int aHabitat, int aCs)
{
    proxy->setName(aName);
    proxy->setType(aType);
    proxy->setHabitat(aHabitat);
    proxy->setCs(aCs);
}

void MainWindow::selectionChanged(const QModelIndex& index)
{
    std::string key{Utility::keyfy(index.data().toString().toStdString())};
    Organism* value{model->getMemory()[key]};

    CardVisitor visitor;
    value->accept(visitor);

    cardBox->setCard(visitor.getWidget());
}

