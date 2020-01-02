#include <string>
#include "Command.h"



Print::Print(ArithmeticExpression *ae1,int linenumber)
{
  _ae1 = ae1;
  linenum= linenumber;
}

Print::~Print ()
{
  delete _ae1;
}
  
  int Print::run(stack <int> &storeline){
    cout<<_ae1->get()<<endl;
    return linenum;
  }
void Print::print (std::ostream & o) const
{
	o<<linenum;
  o << " PRINT ";
  _ae1->print (o);
  o<<endl;
}


Let::Let(ArithmeticExpression *ae1,ArithmeticExpression *ae2,int linenumber,map<string,int> *m1)
{
  _ae1 = ae1;
  _ae2 = ae2;
  linenum= linenumber;
  m2=m1;
}

  int Let::run(stack <int> &storeline){
    (*m2)[_ae1->getname()]=_ae2->get();
    return linenum;
  }
Let::~Let ()
{
  //cout<<_ae2->get()<<"abd"<<endl;
  delete _ae1;
  delete _ae2;
}
  
void Let::print (std::ostream & o) const
{
	o<<linenum;
  o << " LET ";
  _ae1->print (o);
  o<<" ";
    _ae2->print (o);
  o<<endl;
}

If::If(BooleanExpression* be1,int linenumber,int linej)
{
  _be1 = be1;
  linenum= linenumber;
  _linej=linej;
}
  int If::run(stack <int> &storeline){
    if(_be1->check()){
      return _linej-1;
    }
    else{
      return linenum;
    }
    
  }

If::~If ()
{
  delete _be1;
}
  
void If::print (std::ostream & o) const
{

   o<<linenum;
  o << " IF ";
  _be1->print(o);
  o<<" THEN <";
  o<<_linej;
  o<<">"<<endl;
    
}


Goto ::Goto (int linenumber1,int linenumber2)
{
  linenum1= linenumber1;
  linenum2 =linenumber2;

}

Goto::~Goto ()
{
}
  
void Goto ::print  (std::ostream & o) const
{
	o<<linenum1;
	o<<" GOTO";
	  o << " <";
	o<<linenum2;
   o<<">";
    o<<endl;
}

  int Goto::run(stack <int> &storeline){
    return linenum2-1;
  }

Gosub ::Gosub (int linenumber1,int linenumber2)
{
  linenum1= linenumber1;
  linenum2 =linenumber2;
}

Gosub ::~Gosub ()
{
}
  
    int Gosub::run(stack <int> &storeline){
      storeline.push(linenum1);
      return linenum2-1;
  }

void Gosub ::print  (std::ostream & o) const
{
	o<<linenum1;
	o<<" GOSUB";
	  o << " <";
	o<<linenum2;
   o<<">";
    o<<endl;
}

Return ::Return (int linenumber)
{
  linenum= linenumber;
}

Return ::~Return ()
{
}
  int Return::run(stack <int> &storeline){
    int i=storeline.top();
     storeline.pop();
    return (i);
  }
  
void Return ::print  (std::ostream & o) const
{		o<<linenum;
	  o << " RETURN";
	  o<<endl;
}

END ::END (int linenumber)
{
  linenum= linenumber;
}

END ::~END ()
{
}

  int END::run(stack <int> &storeline){
    return -1;
  }
  
void END::print  (std::ostream & o) const
{	o<<linenum;
	  o << " END";
	    o<<endl;
}

