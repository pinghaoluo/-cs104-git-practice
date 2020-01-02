#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>
#include <string>
#include <vector>
using namespace std;




struct TrieNode {
  bool inSet;   // we're not storing a value.
  TrieNode *parent;
  TrieNode *children[30];
};


class TrieSet {
 public:

  TrieSet (); // a constructor for an empty trie
  ~TrieSet (); // destructor

  void insert (std::string input);
   /* Add this string to the set.
      Do nothing if the string is already in the set. */

  void remove (std::string input);
   /* Remove this string from the set.
      Do nothing if the string is not in the set. */

  bool contains (std::string input); // returns whether this string is in the set.
  TrieNode* helper1();
  int helper(char& input);



private:
	TrieNode *root;
};