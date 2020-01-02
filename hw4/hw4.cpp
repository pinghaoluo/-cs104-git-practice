#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Command.h"
#include <stack>

using namespace std;

//helper function to get AtithemeticExpression

ArithmeticExpression* help(string str);

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide an input file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);
  string curr; // the current line
  /*struct for the stack
  struct Item{ 
  	ArithmeticExpression *arithme;
    string value;
  };
  */
  //loop to read all lines of the program
  while(getline(input, curr)) {
    stringstream ss;
    ss << curr;
    string command; // the command
    unsigned int number;  // the line number
    ss >> number;
    ss >> command;


    if (command == "PRINT") {
    	string line,line1;
      	while(ss>>line1){
    		line+=line1;
    	}
    	  Command* commandprint = new Print(help(line),number);
    	  commandprint->print(cout);
    	  delete commandprint;
    }
    else if (command == "LET") {
    	string var;
    	ss>>var;
    	bool isvar =true;
		for(int i=0;i<int(var.length());i++){
			if(!isalpha(var[i])){
			isvar= false;
			break;
			}
		}
		if(isvar){
			
			string line,line1;
      		while(ss>>line1){
    		line+=line1;
    		}
    		if(line[0]=='['){
    			string subvar1,subvar2;
    			int j;
    			int count=0;
    			for(int i=0;i<int(line.length());i++){
    				if(line[i]=='['){
    					count+=1;
    				}
					if(line[i]==']'){
						count-=1;
						if(count==0){
						j=i;
						break;
						}
					}
				}
				subvar1 = line.substr(1,j-1);
				subvar2 = line.substr(j+1,line.length());

    			ArithmeticExpression* var1= new Variable(var);
    	  		Command* commandprint = new Let(var1,help(subvar1),help(subvar2),number);
    	  		commandprint->print(cout);
    	  		   delete commandprint;
    		}
    		else{
    			ArithmeticExpression* var1= new Variable(var);
    	  		Command* commandprint = new Let(var1,help(line),number);
    	  		commandprint->print(cout);
    	  		    	  delete commandprint;
    	  	} 
		}
    	else{

    		string line=var,line1;
      		while(ss>>line1){
    		line+=line1;
    		}
    			string subvar1,subvar2;
    			int j;
    			int count=0;
    			for(int i=0;i<int(line.length());i++){
    				if(line[i]=='['){
    					count+=1;
    				}
					if(line[i]==']'){
						count-=1;
						if(count==0){
						j=i;
						break;
						}
					}
				}
				subvar1 = line.substr(0,j+1);
				subvar2 = line.substr(j+1,line.length());
    	  		Command* commandprint = new Let(help(subvar1),help(subvar2),number);
    	  		commandprint->print(cout);
    	  		delete commandprint;
    	}
    }
    else if (command == "GOTO") {
    	int linenum;
    	ss>>linenum;
    	  Command* commandprint = new Goto(number,linenum);
    	  commandprint->print(cout);
    	  delete commandprint;
    }
    else if (command == "IF") {

    		string line,line1;
      		while(ss>>line1){
    		line+=line1;
    		}
    		int a=line.find("=");
    		int b=line.find("<");
    		int c=line.find(">");
    		int d=line.find("THEN");
    		//if equal
    		if(a!=-1){
    			string substring1=line.substr(0,a);
    			string substring2=line.substr(a+1,d-a-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);
      			BooleanExpression *pribool = new Equal(help(substring1),help(substring2));
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
    	  delete commandprint;

    		}
    		//if larger
    		if(b!=-1){
    			string substring1=line.substr(0,b);
    			string substring2=line.substr(b+1,d-b-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);

      			BooleanExpression *pribool = new Smaller(help(substring1),help(substring2));
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
    	  		    	  delete commandprint;

    		}
    		if(c!=-1){
    			string substring1=line.substr(0,c);
    			string substring2=line.substr(c+1,d-c-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);


      			BooleanExpression *pribool = new Larger(help(substring1),help(substring2));
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
    	  		    	  delete commandprint;
    		}

    }

    else if (command == "GOSUB") {
    	int linenum;
    	ss>>linenum;
    	  Command* commandprint = new Gosub(number,linenum);
    	  commandprint->print(cout);
    	  delete commandprint;
    }
    else if (command == "RETURN") {
    	  Command* commandprint = new Return(number);
    	  commandprint->print(cout);
    	  delete commandprint;
    }
    else if (command == "END") {
    	  Command* commandprint = new END(number);
    	  commandprint->print(cout);
    	  delete commandprint;
    }
    else {
      // This should never happen - print an error?
    	cout<<"error";
    }
  }
  return 0;
}



//Function to get Arithemeticexpression

ArithmeticExpression* help(string line){
	  struct Item{ 
  	ArithmeticExpression *arithme;
    string value;
  };
      	stack<Item> mystack;
		    for(int i=0;i<int(line.length());i++){
	    	Item item;
  			//cout<<i<<endl;
    		if (line[i]=='('){
    			item.value=line;
    			item.arithme=NULL;
    			mystack.push(item);
    		}
    		
    		else if(isalpha(line[i])){
    			string tempvar;
    			int j=i;
    			for(;j<int(line.length());j++){
    				if(!isalpha(line[j])){
    					j-=1;
    					break;
    				}
    				tempvar+=line[j];
    			}

    			item.value=tempvar;
    			item.arithme = new Variable(tempvar);
    			mystack.push(item);
    			i=j;
    		}

    		else if(line[i]=='['){
    			item.value=line;
    			item.arithme=NULL;
    			mystack.push(item);
    		}

    		else if(isdigit(line[i])){
    			string tempvar;
    			int j=i;
    			for(;j<int(line.length());j++){
    				if(!isdigit(line[j])) {
    					j-=1;
    					break;
    				}
    					tempvar+=line[j];
    			}
    			//cout<<tempvar<<endl;
    			//cout<<j<<endl;
    			item.value=tempvar;
    			item.arithme = new Constant(tempvar);
    			mystack.push(item);
    			i=j;			
    		}

    		else if(line[i]=='+'){
    			item.value=line[i];
    			item.arithme= NULL;

    			mystack.push(item);
    		}
    		else if(line[i]=='-'){
    			if(!mystack.empty()){
    			Item a= mystack.top();
    			if(a.arithme==NULL){

	   				string tempvar;
	   				tempvar+=line[i];
	   				i+=1;
	    			int j=i;
	    			for(;j<int(line.length());j++){
	    				if(!isdigit(line[j])) {
	    					j-=1;
	    					break;
	    				}
	    					tempvar+=line[j];
	    			}
	 
	    			item.value=tempvar;
	    			item.arithme = new Constant(tempvar);
	    			mystack.push(item);
	    			i=j;	
    			}
    			else{
	    			item.value=line[i];
	    			item.arithme= NULL;
	    			mystack.push(item);
	    			}
    			}
    			else{
    				string tempvar;
	   				tempvar+=line[i];
	   				i+=1;
	    			int j=i;
	    			for(;j<int(line.length());j++){
	    				if(!isdigit(line[j])) {
	    					j-=1;
	    					break;
	    				}
	    					tempvar+=line[j];
	    			}
	 
	    			item.value=tempvar;
	    			item.arithme = new Constant(tempvar);
	    			mystack.push(item);
	    			i=j;

    			}
    		}
    		else if(line[i]=='*'){
    			item.value=line[i];
    			item.arithme= NULL;
    			mystack.push(item);
    		}
    		else if(line[i]=='/'){
    			item.value=line[i];
    			item.arithme= NULL;
    			mystack.push(item);
    		}
    		

    		
    		else if(line[i]==')'){
    				Item a= mystack.top(); 
    				mystack.pop();
    				Item j= mystack.top(); 
    				mystack.pop();
    				Item k= mystack.top(); 
    				mystack.pop();
    				mystack.pop();
    				Item l;
    				l.value= k.value+j.value+a.value;
    				
    				if(j.value =="+"){
    					l.arithme = new Addition(k.arithme, a.arithme);
    				}
    				
    				else if(j.value=="-"){
    					l.arithme = new Subtraction(k.arithme, a.arithme);
    				}
    				else if(j.value=="*"){
    					l.arithme = new Multiple(k.arithme, a.arithme);
    				}
    				else if(j.value=="/"){
    					l.arithme = new Devide(k.arithme, a.arithme);
    				}			
					mystack.push(l);


    		}

    		else if(line[i]==']'){
   				Item a= mystack.top(); 
    				mystack.pop();
    				Item j= mystack.top(); 
    				mystack.pop();
    				Item k= mystack.top(); 
    				mystack.pop();
    				Item l;
    				l.value= k.value+j.value+a.value;
    				l.arithme = new Brray(k.arithme, a.arithme);		
					mystack.push(l);

    		}
    	};
    	Item final = mystack.top();
    	mystack.pop();
    	return final.arithme;
}

