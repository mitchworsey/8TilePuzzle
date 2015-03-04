#ifndef PUZZLEMOVE_H
#define PUZZLEMOVE_H
#include <functional>
#include "board.h"
#include "puzzle_heur.h"

class PuzzleMove
{
 public:
  /** Constructor for starting Board of an A* search*/
  PuzzleMove(Board &b);

  /** Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )*/
  PuzzleMove(int tile, Board *b, PuzzleMove *parent);

  /** Destructor*/
  ~PuzzleMove();

  /** Compare to PuzzleMoves based on f distance */
  bool operator<(const PuzzleMove& p) const;
  bool operator>(const PuzzleMove& p) const;
  bool operator==(const PuzzleMove& p) const;

  //**** Add any other member functions you think appropriate


  // Data members can be public
 public:
  /** tile moved to reach the Board b*/
  int tileMove_;  
  /** Pointer to a board representing the updated state*/
  Board *b_;      
  /** distance from the start board*/
  int g_;         
  /** heuristic distance to the goal*/
  int h_;         
  /** Pointer to parent PuzzleMove*/
  PuzzleMove *prev_;  
};


// Leave this alone and don't touch it!
struct PuzzleMoveGreater : 
  public std::binary_function<const PuzzleMove*, const PuzzleMove*,bool>
{
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    return *m1 > *m2;
  }
};

#endif
