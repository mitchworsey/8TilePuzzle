#include "puzzle_move.h"
#include "pmminlist.h"
#include "board.h"

/**
 * Default Constructor
 */
PMMinList::PMMinList() : slist_()
{
 
}

/**
 * Destructor
 */
PMMinList::~PMMinList()
{

}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::push(PuzzleMove* pm)
{
  if(slist_.size()==0)
   slist_.push_back(pm);
  else{
   std::list<PuzzleMove*>::iterator it;
   int f = pm->g_ + pm->h_;
   for(it = slist_.begin(); it!= slist_.end(); ++it){
    int a = (*it)->g_ + (*it)->h_;
    if(f < a){
     slist_.insert(it, pm);
     break;
    }
   }
  }
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return nothing
 */
void PMMinList::pop()
{
  slist_.pop_front();
}

/**
 * Adds the value val to the internal list in sorted
 * order from smallest to largest
 * @param val Value to add to the sorted PuzzleMove list
 * @return reference to the minimum-scored PuzzleMove*
 */
PuzzleMove* PMMinList::top()
{
  return slist_.front();
}

