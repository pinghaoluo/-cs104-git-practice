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
  
void Print::print (std::ostream & o) const
{
	o<<linenum;
  o << " PRINT ";
  _ae1->print (o);
  o<<endl;
}


Let::Let(ArithmeticExpression *ae1,ArithmeticExpression *ae2,int linenumber)
{
  _ae1 = ae1;
  _ae2= ae2;
  linenum= linenumber;
}
Let::Let(ArithmeticExpression *ae1,ArithmeticExpression *ae2,ArithmeticExpression *ae3,int linenumber)
{
  _ae1 = ae1;
  _ae2= ae2;
  _ae3 = ae3;
  linenum= linenumber;
}

Let::~Let ()
{
  delete _ae1;
    delete _ae2;
    delete _ae3;
}
  
void Let::print (std::ostream & o) const
{
	if(_ae3 == NULL){
	o<<linenum;
  o << " LET ";
  _ae1->print (o);
  o<<" ";
    _ae2->print (o);
  o<<endl;
}
    else{
    		o<<linenum;
  o << " LET ";
  _ae1->print (o);
  o<<"[";
    _ae2->print (o);
    o<<"] ";
    _ae3->print(o);
  o<<endl;
    }
}

If::If(BooleanExpression* be1,int linenumber,int linej)
{
  _be1 = be1;
  linenum= linenumber;
  _linej=linej;
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

Gosub ::Gosub (int linenumber1,int linenumber2)
{
  linenum1= linenumber1;
  linenum2 =linenumber2;
}

Gosub ::~Gosub ()
{
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
  
void END::print  (std::ostream & o) const
{	o<<linenum;
	  o << " END";
	    o<<endl;
}

