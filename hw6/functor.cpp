#include "functor.h"

bool AlphaStrComp::operator() (const std::string& lhs, const std::string& rhs) 
{ return (lhs < rhs); }

bool LengthStrComp::operator()(const std::string& lhs, const std::string& rhs) 
{ 
	return ((lhs.size() < rhs.size())
		|| (lhs.size() == rhs.size() && lhs < rhs)); 
}



bool NumStrComp::operator()(const std::string& lhs, const std::string& rhs)
{
	int sum1=0;
	int sum2=0;
	for(int i=0;i<lhs.length();i++){
		if(isdigit(lhs[i])){
			sum1+= lhs[i]-48;
		}
		else if(isupper(lhs[i])){
			sum1+=lhs[i]-55;
		}
		else if(islower(lhs[i])){
			sum1+=lhs[i]-87;
		}
	}



		for(int i=0;i<rhs.length();i++){
		if(isdigit(rhs[i])){
			sum2+= rhs[i]-48;
		}
		else if(isupper(rhs[i])){
			sum2+=rhs[i]-55;
		}
		else if(islower(rhs[i])){
			sum2+=rhs[i]-87;
		}
	}
	if(sum1<sum2){
		return true;
	}
	else if(sum1>sum2){
		return false;
	}

	return (lhs<rhs);
}
/*
template <class Comparator>
void DoStringCompare(const std::string& s1, const std::string& s2, Comparator comp)
{
  cout << comp(s1, s2) << endl;  // calls comp.operator()(s1,s2);
}

int main(){
  string s1 = "B";
  string s2 = "R";
  AlphaStrComp comp1;
  NumStrComp comp2;
  // Uses alphabetic comparison
  DoStringCompare(s1,s2,comp1);
  // Use string length comparison
  DoStringCompare(s1,s2,comp2);

}
*/