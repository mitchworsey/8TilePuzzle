#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QDockWidget>
#include "graphicwindow.h"
#include "toolbar.h"
#include "radiobutton.h"
#include "formlayout.h"
#include <QListWidget>

class MainWindow : public QMainWindow{
 //Q_OBJECT
 
 private:
  GraphicWindow *gw;
  RadioButton *rbm;
  RadioButton *rbo;
  QListWidget *qlv;
  QGraphicsScene *scene;
  ToolBar *tb;
  FormLayout *fl;
 public:
  explicit MainWindow();
  //void show();
};
#endif //MAINWINDOW_H
