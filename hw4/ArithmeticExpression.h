#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;


// This file is for classes that have to do with arithmetic expressions

class ArithmeticExpression {
  // abstract class for an arithmetic expression


 public:
  virtual void print (std::ostream & o) const = 0;
  virtual ~ArithmeticExpression(){};
  // pure virtual print function. Don't implement!
};

/* if you prefer to have an abstract "BinaryArithmeticExpresion"
   class or something like that, feel free to insert it and
   have Addition inherit from that instead. */

class Addition : public ArithmeticExpression {
 public:
  Addition (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Addition ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};

// add below other classes that are needed
class Subtraction : public ArithmeticExpression {
 public:
  Subtraction(ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Subtraction ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};
//
class  Multiple: public ArithmeticExpression {
 public:
  Multiple (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Multiple ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};
//
class Devide : public ArithmeticExpression {
 public:
  Devide (ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Devide ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2; // the left and right term
};


class Variable : public ArithmeticExpression {
 public:
  Variable (string s1);
  ~Variable ();
  virtual void print (std::ostream & o) const;
private:
  std::string variable;
};

class Constant : public ArithmeticExpression {
 public:
  Constant (string s1);
  ~Constant ();
   virtual void print (std::ostream & o) const;
private:
  std::string constant;
};


class Brray :public ArithmeticExpression {
 public:
  Brray(ArithmeticExpression *ae1, ArithmeticExpression *ae2);
  ~Brray ();
  // because the class is not abstract, we must implement print
  virtual void print (std::ostream & o) const;
 private:  
  ArithmeticExpression *_ae1, *_ae2;
};



