#ifndef FUNCTOR_H
#define FUNCTOR_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <string> 
using namespace std;

struct AlphaStrComp {
	bool operator() (const std::string& lhs, const std::string& rhs);
	// Uses string's built in operator< 
	// to do lexicographic (alphabetical) comparison
};

struct LengthStrComp {
	bool operator()(const std::string& lhs, const std::string& rhs);
	// Compares strings by size;
	// Breaks ties by lexicographic comparison
};




struct NumStrComp {
	bool operator()(const std::string& lhs, const std::string& rhs);
	// Compares strings by size;
	// Breaks ties by lexicographic comparison
};
  
#endif
