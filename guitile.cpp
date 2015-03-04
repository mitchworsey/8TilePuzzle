#include "guitile.h"
#include "graphicwindow.h"

/** Constructor that uses many parameters
* @param graphicwindow GraphicWindow pointer to the graphic window
* @param ntile Int of the tiles value
* @param nx Double x location of the tile
* @param ny Double y location of the tile
* @param w Double width of the tile
* @param h Double height of the tile
*/
GUITile::GUITile(GraphicWindow *graphicwindow, int ntile, double nx, double ny, double w, double h) :
 QGraphicsRectItem(nx, ny, w, h){
 gw = graphicwindow;
 qgsti = new QGraphicsSimpleTextItem();
 tile = ntile;
 x = nx;
 y = ny;
 vx = 0;
 vy = 0;
 width = w;
 height = h;
 
}

/** Accessor to the text on the tile*/
QGraphicsSimpleTextItem * GUITile::getText(){
 return qgsti;
}

/** Sets the tile's x value*/
void GUITile::setX(int nx){
 x = nx;
}

/** Sets the tile's y value*/
void GUITile::setY(int ny){
 y= ny;
}

/** Sets the tile's x velocity*/
void GUITile::setVX(int nvx){
 vx = nvx;
}

/** Sets the tile's y velocity*/
void GUITile::setVY(int nvy){
 vy= nvy;
}

/** Accessor to the x value*/
int GUITile::getX(){
return x;
}

/**Accessor to the y value*/
int GUITile::getY(){
return y;
}

/** Accessor to the number on the tile*/
int GUITile::getTileNum(){
 return tile;
}

/** Calls moveTile on the tile that was clicked on*/
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *e){
 gw->moveTile(this);
}

/** Moves the tile to the location given by the parameters (without velocity)*/
void GUITile::move(int nx, int ny){
    x = nx;
    y = ny;
    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );
}

/** Moves the tile to the location given the tile's velocity*/
void GUITile::moveV(){
    x += vx;
    y += vy;
    //std::cout << x << " " << y << std::endl << std::endl;
    qgsti->setPos(x +30, y+30);

    //Everything is good. Update the QRectF that is actually displayed.
    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );
}

/** Sets the Text of the Tile*/
void GUITile::setText(QString s){
 qgsti->setText(s);
 //qgsti->show();
}
