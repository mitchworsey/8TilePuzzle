#ifndef MY_LIST_H
#define MY_LIST_H
#include <iostream>
using namespace std;
template<typename T> class MyList{
 private:
  /** pointer to dynamically allocated unbounded array*/
  T* data;
  /** number of spots used in the array*/
  int numSpotsFilled;
  /** capacity of the array*/
  int capacity;
 public:
  /** Constructor*/
  MyList();
  /** Destructor*/
  ~MyList();
  /** adds item to the list*/
  void push_back(T);
  /** returns the size of the list*/
  int size();
  /** gives the item at the specified index*/
  T& at(int);
  /** removes the specified item*/
  bool remove(T);
  /** clears the list*/
  void clear();
};
/** Default constructor*/
template<typename T> MyList<T>::MyList(){
 capacity = 1;
 numSpotsFilled = 0;
 data = new T[capacity];
}

/** Destructor*/
template<typename T> MyList<T>::~MyList(){
 delete[] data;
}

/** Returns the size of the array
* @return numSpotsFilled The Size of the list
*/
template<typename T> int MyList<T>::size(){
 return numSpotsFilled;
}

/** Adds specified item to the list
* @param item The specified item being added
*/
template<typename T> void MyList<T>::push_back(T item){
 if(numSpotsFilled < capacity){
  data[numSpotsFilled] = item;
  numSpotsFilled++;
 }
 else if(numSpotsFilled == capacity){
  capacity*=2;
  T* temp;
  temp = new T[capacity];
  for(int x = 0; x < numSpotsFilled; x++){
   temp[x] = data[x];
  }
  data = new T[capacity];
  for(int x = 0; x < capacity; x++){
   data[x] = temp[x];
  }
  data[numSpotsFilled] = item;
  numSpotsFilled++;
  }
}



/** Returns the item at the specified index
* @param spot The index
* @return T The item at the specified index
*/
template<typename T> T& MyList<T>::at(int spot){
  return data[spot];
}

/** Removes a specified item
* @param item The item to be removed
*/
template<typename T> bool MyList<T>::remove(T item){
 for(int x = 0; x < numSpotsFilled; x ++){
  if(data[x] == item){
   for(int y = x; y < numSpotsFilled-1; y ++){
    data[y] = data[y+1];
   }
  numSpotsFilled--;
  return true;
  }
 }
 return false;
}

/** Clears the list
*/
template<typename T> void MyList<T>::clear(){
 while(numSpotsFilled>0){
  T item = data[0];
  remove(item);
 }
}


#endif
