#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


// This file is for classes that have to do with arithmetic expressions

class ArithmeticExpression {
  // abstract class for an arithmetic expression


 public:
  virtual void print (std::ostream & o) const = 0;
  virtual ~ArithmeticExpression(){};
  virtual int get() =0 ;
  virtual string getname() =0 ;
  // pure virtual print function. Don't implement!
};

/* if you prefer to have an abstract "BinaryArithmeticExpresion"
   class or something like that, feel free to insert it and
   have Addition inherit from that instead. */

class Addition : public ArithmeticExpression {
 public:
  Addition (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Addition ();
  int get();
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  string getname();
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};

// add below other classes that are needed
class Subtraction : public ArithmeticExpression {
 public:
  Subtraction(ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Subtraction ();
  int get();
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  string getname();
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};
//
class  Multiple: public ArithmeticExpression {
 public:
  Multiple (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Multiple ();
  int get();
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    string getname();
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};
//
class Devide : public ArithmeticExpression {
 public:
  Devide (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Devide ();
  int get();
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    string getname();
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};


class Variable : public ArithmeticExpression {
 public:
  Variable (string s1,map<string,int> *m1);
  ~Variable ();
  int get();
  string getname();
  virtual void print (std::ostream & o) const;
private:
  std::string variable;
  map<string,int> *m3;
  bool exist=true;
};

class Constant : public ArithmeticExpression {
 public:
  Constant (string s1);
  ~Constant ();
  int get();
    string getname();
  virtual void print (std::ostream & o) const;
private:
  int constant;
};


class Brray :public ArithmeticExpression {
 public:
  Brray(string s1, ArithmeticExpression *ae2,map<string,int> *m1);
  ~Brray ();
  int get();
  // because the class is not abstract, we must implement print
    string getname();
  virtual void print (std::ostream & o) const;
 private:  
  ArithmeticExpression *_ae2;
  string _s1; 
  map<string,int> *m2;
  bool exist=true;
};



