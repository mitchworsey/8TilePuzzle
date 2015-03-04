#ifndef TOOLBAR_H
#define TOOLBAR_H
#include <QToolBar>
#include <QAction>
#include "graphicwindow.h"
#include "formlayout.h"
#include "radiobutton.h"

class ToolBar: public QToolBar{
 Q_OBJECT
 private:
  GraphicWindow *gw;
  FormLayout *fl;
  QAction *start;
  QAction *quit;
  QAction *aStar;
  RadioButton *rbm;
  RadioButton *rbo;
 public:
  ToolBar(GraphicWindow *graphwind, FormLayout *formlay, RadioButton *nrbm, RadioButton *nrbo);
 public slots:
  void startGame();
  void quitGame();
  void runAStar();
};
#endif
