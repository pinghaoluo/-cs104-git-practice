#include <iostream>
#include "ArithmeticExpression.h"

// This file is for classes that have to do with Boolean expressions

class BooleanExpression {
  // abstract class for a Boolean expression

 public:
  virtual void print (std::ostream & o) const = 0;
  // pure virtual print function. Don't implement!
  virtual ~BooleanExpression(){};
  virtual bool check() =0 ;
};

// add below other classes that are needed
class Equal : public BooleanExpression {
 public:
  Equal (ArithmeticExpression *ae1,ArithmeticExpression *ae2);
  ~Equal ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  bool check();
 private:
  ArithmeticExpression*_ae1, *_ae2;
  bool result= false;

// the left and right term
};

//Larger
class Larger : public BooleanExpression {
 public:
  Larger(ArithmeticExpression *ae1,ArithmeticExpression *ae2);
  ~Larger ();
  bool check();
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2; 
  bool result= false;
};

//Smaller
class Smaller : public BooleanExpression {
 public:
  Smaller(ArithmeticExpression *ae1,ArithmeticExpression *ae2);
  ~Smaller ();
  bool check();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  
 private:
  ArithmeticExpression *_ae1, *_ae2;
  bool result= false; // the left and right term
};