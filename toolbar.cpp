#include "toolbar.h"
/** Constructor of the ToolBar given many different necessary parameters
 * @param graphwind GraphicWindow pointer to the board
 * @param formlay Formlayout pointer to the QLineEdit's
 * @param nrbm RadioButton pointer to the Manhattan Heuristic RadioButton
 * @param nrbo RadioButton pointer to the Out of Place Heuristic RadioButton
 */
ToolBar::ToolBar(GraphicWindow *graphwind, FormLayout *formlay, RadioButton *nrbm, RadioButton *nrbo){
 gw = graphwind;
 fl = formlay;
 rbm = nrbm;
 rbo = nrbo;
 start = new QAction("Start Game", this);
 quit = new QAction("Quit Game", this);
 aStar = new QAction("Run A*", this);
 addAction(start);
 addAction(quit);
 addAction(aStar);
 connect(start, SIGNAL(triggered()), this, SLOT(startGame()));
 connect(quit, SIGNAL(triggered()), this, SLOT(quitGame()));
 connect(aStar, SIGNAL(triggered()), this, SLOT(runAStar()));
}

/** Calls GraphicWindow's 'createGame()' after the Start Game Button is pressed*/
void ToolBar::startGame(){
 int size = fl->getSize();
 int numScrambles = fl->getNumScrambles();
 int seed = fl->getSeed();
 gw->createGame(size, numScrambles, seed);
}

/** Closes the program when the Quit Game button is pressed*/
void ToolBar::quitGame(){
 exit(0);
}

/** Runs the A* algorithm given the RadioButton selected by the Run A* button is pressed*/
void ToolBar::runAStar(){
 fl->setError("");
 if(gw->startGame()==false){
  fl->setError("Start the game please\n");
 }
 else if(rbm->isChecked()&&rbo->isChecked()){
  gw->runAStar("");
  fl->setError("Only choose one button\n");
 }
 else if(rbm->isChecked()){
  gw->runAStar(rbm->getName());
 }
 else if(rbo->isChecked()){
  gw->runAStar(rbo->getName());
 }
 else if((rbm->isChecked() == false) && (rbo->isChecked() == false)){
  gw->runAStar("");
  fl->setError("Please choose one button\n");
 }
}
