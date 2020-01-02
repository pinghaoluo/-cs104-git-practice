#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string> 
using namespace std;
  int number;
  double maxn;
  bool help(int n,double *d1,double* d2);
  double total=0;
  double workload=0;
  double knowledge=0;
int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please provide an input file." << endl;
    return 1;
  }
  ifstream input(argv[1]);
  string curr; // the current line
  stringstream ss;
  getline(input, curr);
  ss<<curr;
  ss>>number;
  ss>>maxn;
  string s1;
  double *s2 = new double[number];
  double *s3 = new double[number];

int i=0;
  while(getline(input, curr)) {
      stringstream ss1;
    string lecture;
    double work;
    double learn;
    ss1 << curr;
        ss1 >> lecture;
        ss1 >> work;
        ss1>>learn;
    s1=lecture;
    s2[i]=work;
    s3[i]=learn;
    i++;
    }

    help(0,s2,s3);
    cout << "Maximum learning: " << total << std::endl;
    delete []s2;
    delete []s3;
  }

  bool help(int n,double * d1,double *d2){
  for (int i = n; i < number; i++)
      {

    if ((workload+ d1[i]) <= maxn){
      workload += d1[i];
      knowledge += d2[i];

      if (knowledge > total) {
        total = knowledge;
      }
      if (help(i+1,d1,d2)) {
        return true;
      }
      else{
      workload -= d1[i];
      knowledge -= d2[i];
      }
      }
      }
  return false;
}
