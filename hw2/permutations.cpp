#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>


using namespace std;


vector<char> helper(vector<char> letters,int i){

		letters.erase(letters.begin()+i);
		return letters;
		
}

void allCombos(vector<char> letters, int n, string temp)
{
   if(n == temp.size()){
     cout << temp << endl;  
   	
   }
   else {

      for(int i=0; i < letters.size(); i++){

         allCombos(helper(letters,i), n, temp+letters[i]);  
      	
      }
   }
}





void permutations(std::string in){
	int len =in.length();
   vector<char> vs;
   
	for(int i=0;i<len;i++){
		vs.push_back(in[i]);
	}

   allCombos(vs, len,"");
}




