#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;


int main (int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide an valid file." << endl;
    return 1;
  }
  cout<<argv[1]<<endl;
  ifstream ifile (argv[1]);
  if(ifile.fail()){
  	return 1;
  }
  stringstream ss;
  string line1;
  int num;
  getline(ifile,line1);
  ss<<line1;
  ss>>num;
  string line2;
  getline(ifile,line2);
  cout<<num<<endl;
  cout<<line2<<endl;
  string *line3 = new string[num];
  for (int i=0;i<num;i++){
  		*line3+=line2[num-1-i];
  	}
   cout<<*line3<<endl;
   delete [] line3;
   return 0;
 
}










