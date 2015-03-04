#include "puzzle_move.h"
/** PuzzleMove constructor, but it sets b_ to the Board specified
* @param b Board to set PuzzleMove's b_ to
*/
PuzzleMove::PuzzleMove(Board &b){
 b_ = &b;
 prev_ = NULL;
 g_ = 0;
 h_ = 0;
 tileMove_ = 0;
}

/** PuzzleMove destructor that deallocates memory*/
PuzzleMove::~PuzzleMove(){
 delete prev_;
 delete b_;
}

/** PuzzleMove constructor, but it sets tileMove_, b_, and prev_ to the specified parameters
* @param tile int to set to tileMove_
* @param b Board to set b_ to
* @param parent PuzzleMove to set prev_ to
*/
PuzzleMove::PuzzleMove(int tile, Board *b, PuzzleMove *parent){
 prev_ = parent;
 b_ = b;
 //std::cout << *b;
 g_ = parent->g_;
 h_ =0;
 tileMove_ = tile;
}


/** Compares to PuzzleMoves based on f distance (needed for priority queue)
*/
bool PuzzleMove::operator<(const PuzzleMove& p) const
{
  if((g_ + h_) < (p.g_ + p.h_)){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ > p.g_)){
    return true;
  }
  else {
    return false;
  }
}

/** Compares to PuzzleMoves based on f distance (needed for priority queue)
*/
bool PuzzleMove::operator>(const PuzzleMove& p) const
{
  if( (g_ + h_) > (p.g_ + p.h_) ){
    return true;
  }
  else if((g_ + h_ == p.g_ + p.h_) && (g_ < p.g_) ){
    return true;
  }
  else {
     return false;
  }
  
}

