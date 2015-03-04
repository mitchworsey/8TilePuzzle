#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;
  /** Constructor (makes a copy of the Board and stores it in _b)
  * @param b The Board being copied
  */
PuzzleSolver::PuzzleSolver(Board &b){
 b_ = b;
 expansions_ = 0;
}

/** Destructor*/
PuzzleSolver::~PuzzleSolver(){
}

/** Run the A* search returning -1 if no solution exists or
    the number of moves in the solution
    * @param ph Pointer to the PuzzleHueristic being used
    * @return The number of expansions
    */
int PuzzleSolver::run(PuzzleHeuristic *ph){
 if(sol.size()!=0)
  sol.clear();
 expansions_ = 1;
 PuzzleMove *pmove = new PuzzleMove(b_);
 PuzzleMove *s;
 openList.push(pmove);
 closedList.insert(&b_);
 while(openList.empty()==false){
  pmove = openList.top();
  openList.pop();
  garbage.push_back(pmove);
  if(pmove->b_->solved()){
   //std::cout << "solved" << std::endl;
   PuzzleMove *temp = pmove;
   while(temp->prev_ != NULL){
    sol.push_back(temp->tileMove_);
    temp = temp->prev_;
   }
   break;
  }
  potentialMoves = pmove->b_->potentialMoves();
  map<int, Board*>::iterator it;
  for(it = potentialMoves.begin(); it!=potentialMoves.end(); ++it){
   s = new PuzzleMove(it->first, it->second, pmove);
   if(closedList.find(s->b_) != closedList.end()){
    continue;
   }
   s->h_ = ph->compute(s->b_->getTiles(), s->b_->getSize());
   s->g_ = pmove->g_ + 1;
   closedList.insert(s->b_);
   openList.push(s);
   expansions_++;
  }
 }

 while(openList.empty()!=true){
  openList.pop();
  //delete openList.top();
 }
 
 //BoardSet::iterator it;
// for(it = closedList.begin(); it != closedList.end(); ++it)
 // delete *it;
 closedList.clear();
 
 //delete pmove;
 //delete s;
 
// map<int, Board*>::iterator itt;
// for(itt = potentialMoves.begin(); itt != potentialMoves.end(); ++itt)
//  delete itt->second;
 potentialMoves.clear();

 
// vector<PuzzleMove*>::iterator ittt;
// for(ittt = garbage.begin(); ittt != garbage.end(); ++ittt){
 // delete (*ittt)->b_;
  //delete (*ittt)->prev_;
 //}
 garbage.clear();
 
 if(sol.size()==0)
  return -1;
 else
  return expansions_;
}
  /** Return the solution List
  * @return sol The solution list
  */
MyList<int>& PuzzleSolver::getSolutionList(){
 return sol;
}

  /** Return how many expansions were performed in the search
  * @return expansions_ The number of expansions
  */
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
