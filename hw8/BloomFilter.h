#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
#include <vector>
using namespace std;






class BloomFilter {
  public:

  BloomFilter (unsigned int size); // Constructor for the given size (see below).
  ~BloomFilter (); // destructor

  void insert (const std::string input);
   /* Add this string to the Bloom Filter.
      Do nothing if the string is already in the Bloom Filter. */

  bool contains (std::string input);
  /* returns whether this string is in the set.
     Being a Bloom Filter, may sometimes return "yes" when the true answer is "no". */ 
  int helper(char& input)const;


  int hash1 (std::string input) const;
  int hash2 (std::string input) const;
  int hash3 (std::string input) const;


  bool *arr;
  unsigned int size1;
};