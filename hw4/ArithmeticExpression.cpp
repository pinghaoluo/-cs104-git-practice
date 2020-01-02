#include <string>
#include "ArithmeticExpression.h"


Addition::Addition (ArithmeticExpression *ae1, ArithmeticExpression *ae2)
{
  _ae1 = ae1;
  _ae2 = ae2;
}

Addition::~Addition ()
{
  delete _ae1;
  delete _ae2;
}
  
void Addition::print (std::ostream & o) const
{
  o << "(";
  _ae1->print (o);
  o << " + ";
  _ae2->print (o);
  o << ")";
}

//Sub
Subtraction::Subtraction (ArithmeticExpression *ae1, ArithmeticExpression *ae2)
{
  _ae1 = ae1;
  _ae2 = ae2;
}

Subtraction::~Subtraction ()
{
  delete _ae1;
  delete _ae2;
}
  
void Subtraction::print (std::ostream & o) const
{
  o << "(";
  _ae1->print (o);
  o << " - ";
  _ae2->print (o);
  o << ")";
}

//Multiple
Multiple::Multiple (ArithmeticExpression *ae1, ArithmeticExpression *ae2)
{
  _ae1 = ae1;
  _ae2 = ae2;
}

Multiple::~Multiple ()
{
  delete _ae1;
  delete _ae2;
}
  
void Multiple::print (std::ostream & o) const
{
  o << "(";
  _ae1->print (o);
  o << " * ";
  _ae2->print (o);
  o << ")";
}

//Devide
Devide::Devide (ArithmeticExpression *ae1, ArithmeticExpression *ae2)
{
  _ae1 = ae1;
  _ae2 = ae2;
}

Devide::~Devide ()
{
  delete _ae1;
  delete _ae2;
}
  
void Devide::print (std::ostream & o) const
{
  o << "(";
  _ae1->print (o);
  o << " / ";
  _ae2->print (o);
  o << ")";
}

  Variable::Variable (string s1) {
  	variable = s1;
  }
  Variable::~Variable(){
  }

  void Variable::print(std::ostream & o) const
  {
  	o<<variable;
  }


  Constant::Constant (string s1) {
  	constant = s1;
  }

  Constant::~Constant(){
  }

  void Constant::print(std::ostream & o) const
  {
  	o<<constant;
  }



  Brray::Brray (ArithmeticExpression *ae1, ArithmeticExpression *ae2)
{
  _ae1 = ae1;
  _ae2 = ae2;
}


Brray::~Brray ()
{
  delete _ae1;
  delete _ae2;
}
  


  void Brray:: print (std::ostream & o) const
  {
   _ae1->print (o);
  o << "[";
  _ae2->print (o);
  o << "]";

  }



