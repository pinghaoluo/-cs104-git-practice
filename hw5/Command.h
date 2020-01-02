#include <iostream>
#include <map>
#include <stack>
#include "BooleanExpression.h"



class Command {
  // abstract class for a BASIC Command

 public:
  virtual void print (std::ostream & o) const = 0;
    virtual ~Command(){};
    virtual int run(stack <int> &storeline) =0;
  // pure virtual print function. Don't implement!
};

// add below other classes that are needed

class Print : public Command{
 public:
  Print (ArithmeticExpression *ae1,int linenumber);
  ~Print ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
  int run(stack <int> &storeline);
 private:
  ArithmeticExpression *_ae1;
  int linenum; // the left and right term
};

class If : public Command{
 public:
  If (BooleanExpression* be1,int linenumber,int linej);
  ~If ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
 	BooleanExpression* _be1;
  int linenum,_linej; // the left and right term
};

class Let : public Command{
 public:
  Let (ArithmeticExpression *ae1,ArithmeticExpression *ae2,int linenumber,map<string,int> *m1);
  ~Let ();
  
  virtual void print (std::ostream & o) const;

  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
  ArithmeticExpression *_ae1;
  ArithmeticExpression *_ae2;
  int linenum; // the left and right term
    map<string,int> *m2;
};

class Goto : public Command{
 public:
  Goto (int linenumber1,int linenumber2);
  ~Goto ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
  int linenum1;
  int linenum2; // the left and right term
};

class Gosub : public Command{
 public:
  Gosub (int linenumber1,int linenumber2);
  ~Gosub ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
  int linenum1;
  int linenum2; // the left and right term
};


class Return : public Command{
 public:
  Return (int linenumber);
  ~Return ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
  int linenum; // the left and right term
};

class END : public Command{
 public:
  END (int linenumber);
  ~END ();
  
  virtual void print (std::ostream & o) const;
  // because the class is not abstract, we must implement print
    int run(stack <int> &storeline);
 private:
  int linenum; // the left and right term
};



/*
<LINE> GOTO <LINEJ>: Jump to the line <LINEJ>
<LINE> IF <BEXPR> THEN <LINEJ>: if the Boolen expression <BEXPR> is true, then jump to the line <LINEJ>
<LINE> GOSUB <LINEJ>: Jump to the line <LINEJ>, and remember where you came from.
<LINE> RETURN: Go back to the line immediately after the line whence the most recent GOSUB jump started.
<LINE> END: Terminate the execution of the program.
*/