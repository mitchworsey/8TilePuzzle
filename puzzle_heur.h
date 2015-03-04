#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H
#include <cmath>

class PuzzleHeuristic
{
 public:
  /** virtual function used to compute Heuristic values*/
  virtual int compute(int *tiles, int size) = 0;
};

class ManhattanHeuristic: public PuzzleHeuristic{
 public:
  /** computes Manhattan Heuristic value
  */
  int compute(int *tiles, int size);
};

class OutOfPlaceHeuristic: public PuzzleHeuristic{
 public:
  /** computes Out of Place Heuristic value
  */
  int compute(int *tiles, int size);
};

#endif
