/*#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;
int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }
  int size, initMoves, seed;
  double test;

  size = atoi(argv[1]);
  test = sqrt(size);
  if(test/int(test)!=1.0){
   cout << "Bad Board Size. Try again.\n\n";
   return 1;
  }
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);
  Board b(size,initMoves,seed);
 
  int t;
  while(!b.solved()){
   do{
    cout << "\nCurrent Board:" << endl << b;
    cout << "Enter the tile you want to move (-1 for a cheat / -100 to Quit): ";
    cin >> t;
    if(cin.fail()){
     cin.clear();
     cin.ignore(10000000,'\n');
     cout << "Bad input. Try again\n";
     continue;
    }
    break;
   }while(true);
   if(t==-1){
    PuzzleSolver *ps = new PuzzleSolver(b);
    ManhattanHeuristic *mh = new ManhattanHeuristic();
    int a = ps->run(mh);
    if(a==-1)
     cout<<"\nNo possible solution :(\n\n";
    else{
     cout << "\nTry this sequence: ";
     for(int x = ps->getSolutionList().size()-1; x >=0; x--)
      cout << ps->getSolutionList().at(x) << " ";
     cout << "\nExpansions = " << ps->getNumExpansions() << endl << endl;
    }
    delete ps;
    delete mh;
   }
   else if(t==-100)
    break;
   else
    b.move(t);
  }
  cout << "\nFinal Board:\n" << b << endl;
  if(t>-1)
   cout << "SOLVED!\n\n";
  else
   cout << "Unsolved\n\n";


  return 0;
}*/
