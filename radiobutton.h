#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QWidget>
#include <QRadioButton>
#include <QString>

class RadioButton : public QWidget{
 //Q_OBJECT
 private:
  QRadioButton *qrb;
  std::string s;
 public:
  RadioButton(std::string);
  bool isChecked();
  std::string getName();
};
#endif
