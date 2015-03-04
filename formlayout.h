#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H
#include <QFormLayout>
#include <QLineEdit>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QTextEdit>

class FormLayout : public QWidget{
 private:
  QLineEdit *size;
  QLineEdit *numScrambles;
  QLineEdit *error;
  QLineEdit *seed;
  QFormLayout *layout;
 public:
  FormLayout();
  int getSize();
  int getNumScrambles();
  int getSeed();
  void setError(std::string);
};
#endif
