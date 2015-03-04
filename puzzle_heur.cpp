#include "puzzle_heur.h"

/** computes Manhattan Heuristic value
  * @param tiles Pointer to the array of tiles
  * @param size Size of the array
  */
int ManhattanHeuristic::compute(int *tiles, int size){
 int count = 0;
 for(int x = 0; x < size; x++){
  if(tiles[x]!=0 && tiles[x]!=x){
   int col1 = x % int((sqrt(size)));
   int row1 = x / int((sqrt(size)));
   int col2 = tiles[x] % int((sqrt(size)));
   int row2 = tiles[x] / int((sqrt(size)));
   count+= (std::abs(col2-col1) + std::abs(row2-row1));
  }
 }
 return count;
}
/** computes Out of Place Heuristic value
  * @param tiles Pointer to the array of tiles
  * @param size Size of the array
  */
int OutOfPlaceHeuristic::compute(int *tiles, int size){
 int count = 0;
 for(int x = 0; x < size; x++){
  if(tiles[x]!=0 && x != tiles[x])
   count++;
 }
 return count;
}
