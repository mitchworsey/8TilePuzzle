#include "formlayout.h"
#include <iostream>
#include <QString>

/** Constructor that allocates all QLineEdit's*/
FormLayout::FormLayout(){
 layout = new QFormLayout();
 setLayout(layout);
 
 size = new QLineEdit();
 numScrambles = new QLineEdit();
 seed = new QLineEdit();
 error = new QLineEdit();
 error->setReadOnly(true);
 //error->resize(error->document()->size().width(), error->document()->size().height()-1000);
// error->setMaxLength(80000);
 
 layout->addRow("Board Size", size);
 layout->addRow("Number of Scrambles", numScrambles);
 layout->addRow("Seed", seed);
 layout->addRow("ERRORS", error);
 
 
}

/** Accessor to the size input by the user*/
int FormLayout::getSize(){
 bool good;
 int res = size->text().toInt(&good);
 if(!good){
  error->setText("BAD SIZE INPUT\n");
  size->setText("");
 }
 if(res !=9 && res !=16){
  error->setText("BAD SIZE INPUT\n");
  size->setText("");
 }
 return res;
}


/** Accessor to the number of scrambles input by the user*/
int FormLayout::getNumScrambles(){
 bool good;
 int res = numScrambles->text().toInt(&good);
 if(!good || res < 1){
  error->setText("BAD NumScrambles INPUT\n");
  numScrambles->setText("");
 }
 return res;
}

/** Accessor to the seed number input by the user*/
int FormLayout::getSeed(){
 bool good;
 int res = seed->text().toInt(&good);
 if(!good || res < 1){
  error->setText("BAD SEED INPUT\n");
  seed->setText("");
 }
 return res;
}

/** Sets the error QLineEdit to the string given by the parameter*/
void FormLayout::setError(std::string s){
 const char * ch = s.c_str();
 QString *qs = new QString(ch);
 error->setText(*qs);
}
