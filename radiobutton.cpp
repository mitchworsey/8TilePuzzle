#include "radiobutton.h"

/** Constructor that creates a RadioButton based on the string given
* @param ss String name of the RadioButton
*/
RadioButton::RadioButton(std::string ss){

 s = ss;
 const char * ch = ss.c_str();
 QString *qs = new QString(ch);
 qrb = new QRadioButton(*qs, this);
 
}

/** Checks if a button has been clicked*/
bool RadioButton::isChecked(){
 return qrb->isChecked();
}

/** Accessor to the name of the RadioButton*/
std::string RadioButton::getName(){
 return s;
}
