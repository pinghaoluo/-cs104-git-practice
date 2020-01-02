#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);
  if(input.fail()){
  	output <<"Please provide an valid input"<<endl;
  }

  int experiments;
  int *numsubjects;
  string **history;
  string line;
  string curr;
  int allsubjects;
  int count0=0;
  //for each experiment, you will need to keep track of the number of subjects; and for each subject, of their history

  //loop to read The Rani's logbook.
  while(getline(input, curr)) {
  	line = curr;
	  stringstream ss;
	  ss << curr;
	  ss >> curr;




	 if(count0==0 && curr!= "START"){
	  	 output <<"Error - no subjects yet"<<endl;
	  	 continue;
	  	}

	 if (curr == "START") {

	 
	    // Hint: This does not cover all errors yet.
		ss >>allsubjects;

		if (ss.fail()) {
			output << "Error - incorrect command: " << line << endl;
		  	output << "Parameter should be an integer" << endl;
		}
		int count3=0;
	    string test2;
	    stringstream ss3;
	    ss3<<line;
	    cout<<line<<endl;
	    while(ss3>>test2){
	    	count3++;
	    }

	    if(count3<2){
	  	 output <<"Error - Too few parameters"<<line<<endl;
	  	 continue;
	  		}



		stringstream  ss5;
		ss5<<line;
		string test5;
	  	bool decimal= false;
		bool allzero = true;
		  
	  	while(ss5>>test5){
	  		if(ss5.fail()){
	  			continue;
	  			}

  		for(int i=0;i<test5.length();i++){
  			if (test5[i] == '.'){
  				decimal=true;
  				if(decimal==true and test5[i]!='0'){
  					allzero=false;
  					}
  				}
  			}
		}

		if(allzero==false){
			output << "Error - incorrect command: " << line << endl;
			output << "Parameter should be an integer" << endl;
			continue;
		}
		if (allsubjects < 0) {
			output << "Error - incorrect command: " << line << endl;
			output << "Number out of range" << endl;
		}

		else {
		  	experiments=1;
		  	history=new string*[experiments];
		  	numsubjects= new int[experiments];
		  	numsubjects[0]=allsubjects;
		  	for(int i=0;i<experiments;i++){
		  		history[i] =  new string[allsubjects];
		  	}
			}
		}
		  
	  
	 else if (curr == "ADD") {
		  	int temp_ex=experiments;
		  	int *temp_numsub =numsubjects;
		  	string **temp_history= history;

		  	experiments +=1;
		  	numsubjects=new int[experiments];

		  	for(int i=0;i<temp_ex;i++){
		  		numsubjects[i] = temp_numsub[i];
		  			}
		  	numsubjects[temp_ex]=0;

			history=new string*[experiments];
			
			for(int i=0;i<(experiments);i++){
				  history[i]=new string[allsubjects];
				}
			for(int i=0;i<temp_ex;i++){
			  	for(int j=0;j< temp_numsub[i]-1;j++){
			  		history[i][j] =temp_history[i][j];
		  			}
		 		}


		 
		  	delete []temp_numsub;
			for(int p=0;p<temp_ex;p++){
		  		delete [] temp_history[p];
		  		}

		  	delete []temp_history;  
	  }

	 else if (curr == "MOVE") {
		  	int x,y,n,m;
		  	string x1,y1,n1,m1;
		  	stringstream ss1;
		  	ss>>x>>y>>n>>m;

			if (ss.fail()) {
			    output << "Error - incorrect command: " << line << endl;
	  		    output << "Parameter should be an integer" << endl;
			}
		  	ss1<<y;
		  	ss1>>y1;
		    string temp;


		int count3=0;
	    string test2;
	    stringstream ss3;
	    ss3<<line;
	    cout<<line<<endl;
	    while(ss3>>test2){
	    	count3++;
	    }

	    if(count3<5){
	  	 output <<"Error - Too few parameters"<<line<<endl;
	  	 continue;
	  		}



		stringstream  ss5;
		ss5<<line;
		string test5;
	  	bool decimal= false;
		bool allzero = true;
		  
	  	while(ss5>>test5){
	  		if(ss5.fail()){
	  			continue;
	  			}

  		for(int i=0;i<test5.length();i++){
  			if (test5[i] == '.'){
  				decimal=true;
  				if(decimal==true and test5[i]!='0'){
  					allzero=false;
  					}
  				}
  			}
		}


		if(allzero==false){
			output << "Error - incorrect command: " << line << endl;
			output << "Parameter should be an integer" << endl;
			continue;
		}
		    if(count3<5){
			  	 output <<"Error - Too few parameters"<<line<<endl;
			  	 continue;
		  		}

		  	if(x<0 or y<0 or n<0 or m<0){
			    output << "Error - incorrect command: " << line << endl;
			    output << "Number out of range" << endl;
			    continue;
		  		}


		  	if(x>=experiments or y >= experiments or
		  	 n>=numsubjects [x]or m>=numsubjects[x] or n>m){
			    output << "Error - incorrect command: " << line << endl;
			    output << "Number out of range" << endl;
			    continue;
				}




		  	for(int i=0;i<m-n+1;i++){

		  		temp = history[x][n+i];
		  		history[y][numsubjects[y]+i] =temp;
		  		if(temp==""){
		  		history[y][numsubjects[y]+i] +=y1;
		  		}
		  		else if(temp!=""){
		  		history[y][numsubjects[y]+i] +=" "+y1;	  			
		  		}
		  	}

		    numsubjects[y]+=m-n+1;
		    if(x!=0){
		  	for(int i=n;i<numsubjects[x]-m-1;i++){
		  		history[x][i] = history[x][i+m-n+1];
		  		history[x][m-n+1+i]= "";
		  	}	  	
		  	numsubjects[x]-=m-n+1;
		  }

	 }
	  else if (curr == "QUERY") {
		    int a,b;
		  	ss>>a>>b;



		int count3=0;
	    string test2;
	    stringstream ss3;
	    ss3<<line;
	    cout<<line<<endl;
	    while(ss3>>test2){
	    	count3++;
	    }

	    if(count3<3){
	  	 output <<"Error - Too few parameters"<<line<<endl;
	  	 continue;
	  		}



		stringstream  ss5;
		ss5<<line;
		string test5;
	  	bool decimal= false;
		bool allzero = true;
		  
	  	while(ss5>>test5){
	  		if(ss5.fail()){
	  			continue;
	  			}

  		for(int i=0;i<test5.length();i++){
  			if (test5[i] == '.'){
  				decimal=true;
  				if(decimal==true and test5[i]!='0'){
  					allzero=false;
  					}
  				}
  			}
		}



		if(allzero==false){
			output << "Error - incorrect command: " << line << endl;
			output << "Parameter should be an integer" << endl;
			continue;
		}


		  if(a<0 or b<0 or a>=experiments or b>= experiments){
		    output << "Error- incorrect command: " << line << endl;
		    output << "Number out of range" << endl;
		    continue;
		}


		  	output<<history[a][b]<<endl;
	  	}

	  
	  else {
		  output<<"Command does not exist:"<<line<<endl;
	  }
	  count0++;
  }
  		 
  delete []numsubjects;
  for(int l=0;l<experiments;l++){
		delete [] history[l];
	}

	delete []history;  
  return 0;
}

