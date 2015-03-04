#include "mainwindow.h"

/** Constructor. Allocates all necessary compentents of the MainWindow and adds them to the MainWindow*/
MainWindow::MainWindow(){
    
    qlv = new QListWidget();
    gw = new GraphicWindow(qlv);
    setCentralWidget(gw);
    QMenuBar *mb = menuBar();
    QMenu *fileMenu = new QMenu("File", this);
    QAction *exitAction = new QAction( "Exit", this);
    fileMenu->addAction( exitAction );
    mb->addMenu(fileMenu);
    setMenuBar(mb);
    
    rbm = new RadioButton("Manhattan Heuristic");
    rbo = new RadioButton("Out of Place Heuristic");
    QDockWidget *qdwm = new QDockWidget();
    qdwm->setWidget(rbm);
    addDockWidget(Qt::LeftDockWidgetArea, qdwm);
    qdwm->setFeatures(QDockWidget::NoDockWidgetFeatures);
    QDockWidget *qdwo = new QDockWidget();
    qdwo->setWidget(rbo);
    addDockWidget(Qt::LeftDockWidgetArea, qdwo);
    qdwo->setFeatures(QDockWidget::NoDockWidgetFeatures);
   
    fl = new FormLayout();
    QDockWidget *qdw = new QDockWidget();
    qdw->setWidget(fl);
    addDockWidget(Qt::LeftDockWidgetArea, qdw);
    qdw->setFeatures(QDockWidget::NoDockWidgetFeatures);
    tb = new ToolBar(gw, fl, rbm, rbo);
    addToolBar(tb);
    
    /*QToolBar *errorbar = new QToolBar();
    this->addToolBar(Qt::BottomToolBarArea, errorbar);
    
    QLabel *errorlabel = new QLabel();
    errorbar->addWidget(errorlabel);
    errorlabel->setText("Cheat");*/
    QDockWidget *qdwl = new QDockWidget();
    qdwl->setWidget(qlv);
    addDockWidget(Qt::BottomDockWidgetArea, qdwl);
    qdwl->setFeatures(QDockWidget::NoDockWidgetFeatures);
    setFixedSize( WINDOW_MAX_X*5, WINDOW_MAX_Y*3 );
    
    
}

