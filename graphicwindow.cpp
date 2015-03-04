#include "graphicwindow.h"
#include <sstream>
#include <cmath>
/** Constructor that takes in a QListWidget pointer
 *@param nqlv QListWidget pointer to print out solution
 */
GraphicWindow::GraphicWindow(QListWidget *nqlv)  {
    scene = new QGraphicsScene();
    
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    startedGame = false;
    
    qlv = nqlv;
    setScene(scene);
    
    setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
}

/** Slides the tiles*/
void GraphicWindow::handleTimer(){
 counter++;
 for(unsigned int x = 0; x < gtiles.size(); x++)
  gtiles[x]->moveV();
 if(counter==60){
  timer->stop();
  if(b->solved()){
    if(b->getSize()==9){
    GUITile *solved = new GUITile(this, 0, 0, 180, 180,60);
    std::string ss = "SOLVED!";
    const char * ch = ss.c_str();
    QString *qs = new QString(ch);
    solved->setText(*qs);
    scene->addItem(solved);
    solved->getText()->setPos(60, 195);
    scene->addItem(solved->getText());
    }
    else{
    GUITile *solved = new GUITile(this, 0, 0, 240, 240,60);
    std::string ss = "SOLVED!";
    const char * ch = ss.c_str();
    QString *qs = new QString(ch);
    solved->setText(*qs);
    scene->addItem(solved);
    solved->getText()->setPos(80, 255);
    scene->addItem(solved->getText());
    }
   }
 }
}

/** Runs the A* algorithm with the GUI
* @param name String name of the Heuristic being used
*/
void GraphicWindow::runAStar(std::string name){
 qlv->clear();
 if(b->getSize()==0)
  return;
 if(name=="")
  return;
 PuzzleSolver *ps = new PuzzleSolver(*b);
 int a=-1;
 if(name=="Manhattan Heuristic"){
  ManhattanHeuristic *mh = new ManhattanHeuristic();
  a = ps->run(mh);
 }
 else if(name=="Out of Place Heuristic"){
  OutOfPlaceHeuristic *ooph = new OutOfPlaceHeuristic();
  a = ps->run(ooph);
 }
 QStringList *qsl = new QStringList();
 //std::cout << "here" << std::endl;
 if(a>-1){
  for(int x = 0; x < ps->getSolutionList().size(); x++){
      std::cout << ps->getSolutionList().at(x) << std::endl;
      stringstream ss;
      ss << ps->getSolutionList().at(x);
      std::string s = ss.str();
      const char * ch = s.c_str();
      QString *qs = new QString(ch);
      qsl->insert(0,*qs);
  }
  qlv->insertItems(0,*qsl);
 }
 
}

/** Moves the tile after is it clicked on
* @param guit GUITile that is clicked on
*/
void GraphicWindow::moveTile(GUITile *guit){
 if(b->solved())
  return;
 int *tiles = b->getTiles();
 int index=0;
 int inzero = 0;
 int d = sqrt(b->getSize());
 for(int x = 0; x < b->getSize(); x++){
  if(tiles[x] == guit->getTileNum()){
   index = x;
  }
  if(tiles[x]==0)
   inzero = x;
 }
 
 
 if(b->validMove(tiles[index])){
  b->move(tiles[index]);
  for(unsigned int x = 0; x < gtiles.size(); x++){
    gtiles[x]->setVX(0);
    gtiles[x]->setVY(0);
  }
  
   if(index-d == inzero){
    guit->setVY(-1);
   }
   else if(index-1 == inzero){
    guit->setVX(-1);
   }
   else if(index+1 == inzero){
    guit->setVX(1);
   }
   else if(index+d == inzero){
    guit->setVY(1);
   }
   counter = 0;
   timer->start();
   

   //std::cout << "to be moved " << tiles[index];
   /*
   if(index-d == inzero){
    guit->setY(guit->getY()-60);
    guit->getText()->setPos(guit->getX() +30, guit->getY()+30);
   }
   else if(index-1 == inzero){
    guit->setX(guit->getX()-60);
    guit->getText()->setPos(guit->getX() +30, guit->getY()+30);
   }
   else if(index+1 == inzero){
    guit->setX(guit->getX()+60);
    guit->getText()->setPos(guit->getX() +30, guit->getY()+30);
   }
   else if(index+d == inzero){
    guit->setY(guit->getY()+60);
    guit->getText()->setPos(guit->getX() +30, guit->getY()+30);
   }
   

   
   
   
   //GUITile *temp = gtiles[index];
   //gtiles[index] = gtiles[inzero];
   //gtiles[inzero] = temp;
   
   guit->move(guit->getX(), guit->getY());
   
   //std::cout << *b<<std::endl<<std::endl;
   
   if(b->solved()){
    if(b->getSize()==9){
    GUITile *solved = new GUITile(this, 0, 0, 180, 180,60);
    std::string ss = "SOLVED!";
    const char * ch = ss.c_str();
    QString *qs = new QString(ch);
    solved->setText(*qs);
    scene->addItem(solved);
    solved->getText()->setPos(60, 195);
    scene->addItem(solved->getText());
    }
    else{
    GUITile *solved = new GUITile(this, 0, 0, 240, 240,60);
    std::string ss = "SOLVED!";
    const char * ch = ss.c_str();
    QString *qs = new QString(ch);
    solved->setText(*qs);
    scene->addItem(solved);
    solved->getText()->setPos(80, 255);
    scene->addItem(solved->getText());
    }
   }*/
   //updateGame(b->getSize());
 }
 
}

/** Generates the starting board
* @param size Int size of the board
* @param numScrambles Int number of times the board is scrambled
* @param seed Int seed
*/
void GraphicWindow::createGame(int size, int numScrambles, int seed){
// if(size!=9 || size!=16);
  //error
 if((size==9 || size==16 )&& numScrambles >0 && seed > 0){
  b = new Board(size, numScrambles, seed);
  int *tiles = b->getTiles();
  int counter = 0;
  for(int y = 0; y < std::sqrt(size); y++){
   for(int x = 0; x < std::sqrt(size); x++){
    if(tiles[counter]!=0){
     gt = new GUITile(this, tiles[counter], x*60, y*60, 60, 60);
     std::string ss = b->getVal(counter);
     const char * ch = ss.c_str();
     QString *qs = new QString(ch);
     gt->setText(*qs);
     gtiles.push_back(gt);
     scene->addItem(gt);
     gt->getText()->setPos(x*60 +30, y*60 +30);
     scene->addItem(gt->getText());
    }
    counter++;
   }
  }
 }
 startedGame = true;
}

/** verifies if that game has been started or not*/
bool GraphicWindow::startGame(){
 //std::cout << "StartGame = " << startedGame << std::endl;
 return startedGame;
}
/** Destructor*/
GraphicWindow::~GraphicWindow()
{
    //timer->stop();
    delete scene;
    delete gt;
    
}

