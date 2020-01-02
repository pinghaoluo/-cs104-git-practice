#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Command.h"
#include <stack>

using namespace std;

//helper function to get AtithemeticExpression
ArithmeticExpression* help(string str);
//Command* help1(stringstream s1,int int1);
  std::map <string,int> *svar = new map<string,int>; 
  std::map <int,Command*> scmd; 
  map<string,int> ::iterator it1;
  map<int,Command*> ::iterator it2;
  stack<int> storeline;

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide an input file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  string curr; // the current line
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
          scmd[number]= commandprint;
    	  commandprint->print(cout);

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
                ArithmeticExpression *ae1 = help(subvar1);
                ArithmeticExpression *ae2 = help(subvar2);
                ArithmeticExpression* array1= new Brray(var,ae1,svar);
                //cout<<array1->get()<<endl;
                Command* commandprint = new Let(array1,ae2,number,svar);
                commandprint->print(cout);
                scmd[number]=commandprint;
            }
            else{
                ArithmeticExpression *ae1 = help(line);
                ArithmeticExpression* var1= new Variable(var,svar);
                Command* commandprint = new Let(var1,ae1,number,svar);
                //cout<<(var1->get())<<endl;
                commandprint->print(cout);
                scmd[number]=commandprint;
            } 
        }
        else{
            string line=var,line1;
            while(ss>>line1){
            line+=line1;
            }
                string subvar1,subvar2,subvar3;
                int j;
                int count=0;
                int k=line.find('[');
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
                subvar1 = line.substr(0,k);
                subvar2 = line.substr(j+1,line.length());
                subvar3 = line.substr(k+1,j-k-1);
                ArithmeticExpression *ae1 = help(subvar2);               
                ArithmeticExpression *ae2 = help(subvar3);
                ArithmeticExpression* array2= new Brray(subvar1,ae2,svar);
                //cout<<array2->get()<<endl;                
                Command* commandprint = new Let(array2,ae1,number,svar);
                commandprint->print(cout);
                scmd[number]=commandprint;
        }

    }   
    else if (command == "GOTO") {
    	int linenum;
    	ss>>linenum;
    	Command* commandprint = new Goto(number,linenum);
    	commandprint->print(cout);
        scmd[number]=commandprint;
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

            if(!isdigit(line[d+4])){
                string substring4=line.substr(d+4);
                int e=substring4.find("THEN");
                d+=(e+4);
            }
    		//if equal
    		if(a!=-1){
    			string substring1=line.substr(0,a);
    			string substring2=line.substr(a+1,d-a-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);
      			BooleanExpression *pribool = new Equal(help(substring1),help(substring2));
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
                scmd[number]=commandprint;
    		}
    		//if larger
    		if(b!=-1){
    			string substring1=line.substr(0,b);
    			string substring2=line.substr(b+1,d-b-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);
      			BooleanExpression *pribool = new Smaller(help(substring1),help(substring2));
                cout<<pribool->check();
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
                scmd[number]=commandprint;
    		}
    		if(c!=-1){
    			string substring1=line.substr(0,c);
    			string substring2=line.substr(c+1,d-c-1);
    			string substring3=line.substr(d+4);
      			int linenum =stoi(substring3);
      			BooleanExpression *pribool = new Larger(help(substring1),help(substring2));
    	  		Command* commandprint = new If(pribool,number,linenum);
    	  		commandprint->print(cout);
                scmd[number]=commandprint;
    		}
    }
    else if (command == "GOSUB") {
    	int linenum;
    	ss>>linenum;
    	  Command* commandprint = new Gosub(number,linenum);
    	  commandprint->print(cout);
          scmd[number]=commandprint;
          storeline.push(linenum);
    }
    else if (command == "RETURN") {
    	  Command* commandprint = new Return(number);
    	  commandprint->print(cout);
          scmd[number]=commandprint;
    }
    else if (command == "END") {
    	  Command* commandprint = new END(number);
    	  commandprint->print(cout);
          scmd[number]=commandprint;
    }
    else {
      // This should never happen - print an error?
    	cout<<"error";}
  } 
  int count=0;
  for(it2=scmd.begin();it2!=scmd.end();++it2){
    int templine=it2->second->run(storeline);
    if(templine==-1){
        break;
    }
    map<int,Command*> ::iterator it3 = scmd.find(templine);

    if(it2==it3){ }
    else{
       it2=it3; 
    }
    count++;
    }


  for(it2=scmd.begin();it2!=scmd.end();++it2){
    delete it2->second;

    }


  delete svar;
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
    		

    		else if(line[i]=='['){
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

                if(line[j+1]!='['){
                    item.arithme = new Variable(tempvar,svar);
                    mystack.push(item);
                    //cout<<item.value<<endl;
                }
                else{
                    item.arithme=NULL;
                    mystack.push(item);
                }
                
                i=j;
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
                    //cout<<j.value<<"array"<<endl;
    				l.value= k.value+j.value+a.value;
    				l.arithme = new Brray(k.value, a.arithme,svar);		
					mystack.push(l);
    		}
    	};
    	Item final = mystack.top();
    	mystack.pop();
    	return final.arithme;
}

