#include "LLDeque.h"

//Helper to check when the direction is opposite
bool helper(char a,char b){
	if(a=='S' and b=='N'){
		return true;
	}
	if(a=='N' and b=='S'){
		return true;
	}
	if(a=='E' and b=='W'){
		return true;
	}
	if(a=='W' and b=='E'){
		return true;
	}
	return false;
}

//helper to check if the direction is the same
bool helper1(char a,char b){
	if(a=='N' and b=='N'){
		return true;
	}
	if(a=='S' and b=='S'){
		return true;
	}
	if(a=='E' and b=='E'){
		return true;
	}
	if(a=='W' and b=='W'){
		return true;
	}
	return false;
}




int main(int argc, char *argv[]){
 

  if(argc < 2){
   cerr << "Please provide an valid file." << endl;
   return 1;
  }
  ifstream ifile (argv[1]);
  int count1=0, count2=0;
  LLDeque ll;
  string line;
  while(ifile>>line){




//walking of 1
  if(line[0]=='1'){
  	if(count1==0){
  		if(count2!=0){
		  	if(helper1(ll.getback(),line[1])){
		  		ll.popback();
		  		count2-=1;
		  		}
  			
  			else{

		  	ll.pushback(line[1]);
		  	count1+=1;
		  	}
		  }

  		else{

		  	ll.pushback(line[1]);
		  	count1+=1;
		  	}
		  
   	}
   	else{
   		if(helper(ll.getback(),line[1])){
   			ll.popback();
   			count1-=1;
   		}
   		else{
   			ll.pushback(line[1]);
  			count1+=1;
   		}
   	}
  }



//walking of 2
   if(line[0]=='2'){
  	if(count2==0){
  		if(count1!=0){
		  	if(helper1(ll.getfront(),line[1])){
		  		ll.popfront();
		  		count1-=1;
		  		}
  			
  			else{

		  	ll.pushfront(line[1]);
		  	count2+=1;

		  	}
		  }
		 else{

		  	ll.pushfront(line[1]);
		  	count2+=1;
		  	}

		}
   	else{
   		if(helper(ll.getfront(),line[1])){
   			ll.popfront();
   			count2-=1;
   		}
   		else{
   		ll.pushfront(line[1]);
  		count2+=1;
  		}
   	}
  }



}

cout<<(count1+count2)<<endl;
}