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
  string Addition::getname(){
    return "a";
  }
int Addition::get(){
  return (_ae1->get()+_ae2->get());
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

int Subtraction::get(){
  return (_ae1->get()-_ae2->get());
}
  
    string Subtraction::getname(){
    return "a";
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

int Multiple::get(){
    return (_ae1->get()*_ae2->get());
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
  string Multiple::getname(){
    return "a";
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

int Devide::get(){
  return (_ae1->get()/_ae2->get());
}

  Variable::Variable (string s1,map<string,int> *m1) {
  	variable = s1;
    m3= m1;

  }
  string Devide::getname(){
    return "a";
  }
  Variable::~Variable(){
    //delete m3;
  }

  void Variable::print(std::ostream & o) const
  {
  	o<<variable;
  }


  int Variable::get(){ 
    if(((*m3)[variable])==0){
      exist=false;
    }

    if(exist){
      return (*m3)[variable]; 
    }
    else{
      return 0;
    }
  }

  string Variable::getname(){
    return variable;
  }
  

  Constant::Constant (string s1) {
  	constant = stoi(s1);
  }

  Constant::~Constant(){
  }

  string Constant::getname(){
    return "a";
  }
  void Constant::print(std::ostream & o) const
  {
  	o<<constant;
  }

  int Constant::get(){
    return constant;
  }





  Brray::Brray (string s1, ArithmeticExpression *ae2,map<string,int> *m1)
{
  _s1 = s1;
  _ae2 = ae2;
  m2=m1;

}
Brray::~Brray ()
{
  delete _ae2;
  //delete m2;
}

  string Brray::getname(){
    return (_s1+to_string(_ae2->get()));
  }

  void Brray:: print (std::ostream & o) const
  {
   o<<_s1;
  o << "[";
  _ae2->print (o);
  o << "]";

  }

  int Brray::get(){
    if((*m2)[_s1+to_string(_ae2->get())]==0){ 
      exist=false;
  }
      if(exist){
        return (*m2)[_s1+to_string(_ae2->get())];
      }
      else{
        return 0;
      }
  }



