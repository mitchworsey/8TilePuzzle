#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H
#include <queue>
#include <vector>
#include <deque>
#include <set>
#include "board.h"
#include "puzzle_move.h"
#include "puzzle_heur.h"
#include "pmminlist.h"
#include "mylist.h"

class PuzzleSolver
{
 public:
  /** Typedef for the closed-list set.  Declare your closed list variable as
  *   BoardSet closedlist; 
  * when you write your code for the run() funciton*/
  typedef std::set<Board *, BoardLessThan> BoardSet;

  /** Constructor (makes a copy of the Board and stores it in _b)*/
  PuzzleSolver(Board &b);

  /** Destructor*/
  ~PuzzleSolver();

  /** Run the A* search returning -1 if no solution exists or
    the number of moves in the solution*/
  int run(PuzzleHeuristic *ph);

  /** Return the solution List*/
  MyList<int>& getSolutionList();

  /** Return how many expansions were performed in the search*/
  int getNumExpansions();

 private:
  /** open list of puzzle moves*/
  PMMinList openList;
  /** closed list of board pointers*/
  BoardSet closedList;
  /** garbage moves*/
  vector<PuzzleMove*> garbage;
  /** map of potential moves*/
  map<int, Board*> potentialMoves;
  /** the board being solved*/
  Board b_;
  /** the number of expansions*/
  int expansions_;
  /** the solution sequence*/
  MyList<int> sol;
};

#endif
