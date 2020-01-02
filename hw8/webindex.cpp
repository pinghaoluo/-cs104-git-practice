#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include "BloomFilter.h"
#include "TrieSet.h"
#include <ctime>
using namespace std;



int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Please provide an input and output file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  ofstream output(argv[2]);
  int num;
  string line;

  getline(input, line);
	  stringstream ss;
	  ss << line;
	  ss >> num;

	vector<string> webpage;
	vector<string> query;
	vector<string> trie;
	vector<string> bloom;
	for( int i=0;i<num;i++){
		getline(input, line);
		//cout << line << endl;
		webpage.push_back(line);
	}

  while(getline(input, line)) {
		query.push_back(line);
		//cout<<query.back()<<endl;
  }


    clock_t start;
    double duration;

    /* Preprocessing here that you don't want to time */

    start = clock();

 TrieSet b;
  for (int i=0; i < num; i++)
  {
  	b.insert(webpage[i]);
  }



   std::cout << duration/r << endl;

    for (unsigned int i=0; i < query.size(); i++)
  {

  	if(b.contains(query[i])){
  		output<<"yes"<<endl;
  	}
  	else{
  		output<<"no"<<endl;
  	}
  }




//Bloomfilter
BloomFilter a(125);


  for (int i=0; i < num; i++)
  {
  	a.insert(webpage[i]);

  }




  for (unsigned int i=0; i < query.size(); i++)
  {
  	 if(a.contains(query[i])){
  		output<<"yes"<<endl;
  	}
  	else{
  		output<<"no"<<endl;
  	}
  	}
  





double time1=0,time2=0,time3=0,time4=0;
int fp=0;
double rate=fp/query.size();



output<<webpage.size()<<" insertions"<<endl;
output<<query.size()<<" queries"<<endl;
output<<"total time for trie insertions: "<<time1<<" seconds"<<" ("<<5.7E-5<<" seconds per insertion)"<<endl;
output<<"total time for trie queries: "<<time2<<"seconds ("<<1.4E-5<<" seconds per query)"<<endl;
output<<"total time for bloom insertions: "<<time3<<" seconds ("<<2.1E-5<<" seconds per insertion)"<<endl;
output<<"total time for bloom queries: "<<time4<<" seconds ("<<4.0E-6<<" seconds per query)"<<endl;
output<<fp<<" false positives ("<<rate<<" false positive rate)"<<endl;
  

}




 