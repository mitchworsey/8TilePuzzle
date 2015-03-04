#ifndef GUITILE_H
#define GUITILE_H
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QRectF>
#include <QString>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
//#include "graphicwindow.h"

class GraphicWindow;

class GUITile : public QGraphicsRectItem{
 private:
  GraphicWindow *gw;
  QGraphicsSimpleTextItem *qgsti;
  int tile;
  int width;
  int height;
  int x;
  int y;
  int vx;
  int vy;
 public:
  GUITile(GraphicWindow *graphicwindow, int ntile, double nx, double ny, double w, double height);
  void mousePressEvent(QGraphicsSceneMouseEvent *e);
  void setText(QString s);
  QGraphicsSimpleTextItem* getText();
  int getTileNum();
  void setX(int);
  void setY(int);
  void setVX(int);
  void setVY(int);
  int getX();
  int getY();
  void move(int, int);
  void moveV();
};

#endif
