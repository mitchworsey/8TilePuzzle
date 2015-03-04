#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include "board.h"
using namespace std;


/** Init a board of given size and scramble it with numInitMoves 
 * by moving the space tile with a randomly chosen direction N, W, S, E
 * some of which may be invalid, in which case we skip that move 
 * 
 *  @param size Number of tiles for the game.  \
 *      Should be a perfect square (4, 16, 25)
 *  @param numInitMoves Number of tile moves to attempt to scramble the board
 *  @param seed Use to seed the random number generator (srand) 
 */
Board::Board(int size, int numInitMoves, int seed )
{
  size_ = size;
  tiles_ = new int[size_];
  int dim = static_cast<int>(sqrt(size_));
  srand(seed);
  for(int i=0; i < size_; i++){
    tiles_[i] = i;
  }
  int blankLoc = 0;
  for(int i=0; i < numInitMoves; i++){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < size_){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      tiles_[blankLoc] = tiles_[randNeighbor];
      tiles_[randNeighbor] = 0;
      blankLoc = randNeighbor;
    }
  }
}


/** Copy constructor. Makes a copy of the Board specified in the parameter.
* @param b is the Board that will be copied
*/
Board::Board(const Board &b){
 this->size_ = b.size_;
 this->tiles_ = new int[size_];
 for(int x = 0; x < size_; x++)
  this->tiles_[x] = b.tiles_[x];
}

/** Different kind of copy constructor. Instead of being given a Board, you are
* given the size and a pointer to the tiles to create a copy from.
* @param tiles Points to the set of tiles
* @param size Gives the size of the board
*/
Board::Board(int *tiles, int size){
 this->size_ = size;
 this->tiles_ = new int[size_];
 for(int x = 0; x < size_; x++)
  this->tiles_[x] = tiles[x];
}


/** Default constructor. Creates a new Board with a size of 0 and a 
* dynamically allocated array of tiles.
*/
Board::Board()
{
  size_ = 0;
  tiles_ = new int[size_];
  /*
   * IMPLEMENT ME
  */
}

/** Default destructor. Deallocates the array of tiles */
Board::~Board()
{
  delete[] tiles_;
}

/** @return a pointer to the set of tiles*/
int * Board::getTiles(){
 return tiles_;
}

/** @return the size of the board*/
int Board::getSize(){
 return size_;
}

/** Parses the board and stores all potential moves and the corresponding Board
* in a map.
* @return The map of potential moves and the corresponding Board
*/
std::map<int, Board*> Board::potentialMoves(){
 map<int, Board*> blist;
 Board* tTiles;
 int dim = sqrt(size_);
 for(int x = 0; x < size_; x++){
  if(tiles_[x] == 0){
   if((x-dim) >= 0){//north
    tTiles = new Board(*this);
    int temp = tTiles->tiles_[x];
    tTiles->tiles_[x] = tTiles->tiles_[x-dim];
    tTiles->tiles_[x-dim] = temp;
    blist[tTiles->tiles_[x]] = tTiles;
   }
   if((x%dim) != 0){//west
    tTiles = new Board(*this);
    int temp = tTiles->tiles_[x];
    tTiles->tiles_[x] = tTiles->tiles_[x-1];
    tTiles->tiles_[x-1] = temp;
    blist[tTiles->tiles_[x]] = tTiles;
   }
   if((x+dim) < size_){//south
    tTiles = new Board(*this);
    int temp = tTiles->tiles_[x];
    tTiles->tiles_[x] = tTiles->tiles_[x+dim];
    tTiles->tiles_[x+dim] = temp;
    blist[tTiles->tiles_[x]] = tTiles;
    
   }
   if((x%dim) != dim-1){//east
    tTiles = new Board(*this);
    int temp = tTiles->tiles_[x];
    tTiles->tiles_[x] = tTiles->tiles_[x+1];
    tTiles->tiles_[x+1] = temp;
    blist[tTiles->tiles_[x]] = tTiles;
   }
   break;
  }
 }

 return blist;
}

/** Prints the Board in neat columns
* @param os The ostream needed for operator overloading
* @param b The Board being printed out
* @return The ostream needed for operator overloading
*/
std::ostream& operator<<(std::ostream &os, const Board &b){
 int z = 0, temp = b.size_;
 while(temp>0){
  z++;
  temp /= 10;
 }
 for(int x = 0; x < sqrt(b.size_); x++){
  for(int y = x*sqrt(b.size_); y < x*sqrt(b.size_)+sqrt(b.size_); y++){
   os << setw(z+2) << b.tiles_[y];
  } 
  os << endl;
 }
 return os;
}

/** Verifies if the specified tile is a valid move, the moves the tile
* @param tile The tile to be moved
*/
void Board::move(int tile){
 if(validMove(tile)){
  int tileIndex = 0;
  int blank= 0;
  for(int x = 0; x < size_; x++){
   if(tiles_[x] == 0){
    blank = x;
   }
   if(tiles_[x] == tile)
    tileIndex = x;
  }
  tiles_[blank] = tile;
  tiles_[tileIndex] = 0;
 }
}

/** Checks if the tile is a valid move by seeing if it is in the map of potential moves.
* @param tile The tile to be moved
*/
bool Board::validMove(int tile){
 map<int, Board*> blist = potentialMoves();
 bool flag = false;
 map<int, Board*>::iterator it;
 for(it = blist.begin(); it!=blist.end(); ++it){
  if(tile == it->first){
   flag = true;
   break;
  }
 }
 if(flag==false)
  cout << "Not an acceptable move. Try again.\n";
 return flag;
}

/** Checks to see if the Board if solved.
*/
bool Board::solved(){
 for(int x = 0; x < size_; x++){
  if(tiles_[x] != x){
   return false;
  }
 }
 return true;
}

/** Sees if one board is less than another Board.
* @param rhs The Board that will be compared the another board using
* operator overloading.
*/
bool Board::operator<(const Board& rhs) const
{
  if(size_ < rhs.size_){
    return true;
  }
  bool val = false;
  for(int i=0; i < size_; i++){
    if(tiles_[i] < rhs.tiles_[i]){
       //val = true;
       //break;
       return true;
     }
     else if(tiles_[i] > rhs.tiles_[i]){
       //break;
       return false;
     }
  }
  return val;
}

/** Sets the size of the board
* @param s The size that will be set to the Board's size
*/
void Board::setSize(int s){
 size_ = s;
}

std::string Board::getVal(int loc){
 int x = tiles_[loc];
 ostringstream convert;
 convert << x;
 return convert.str();
}

/** Operator overload to set Boards equal each other*/
Board& Board::operator=(const Board &rhs){
 this->size_ = rhs.size_;
 this->tiles_ = new int[size_];
 for(int x = 0; x < size_; x++)
  this->tiles_[x] = rhs.tiles_[x];
 return *this;
}

