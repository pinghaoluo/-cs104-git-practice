#include "TrieSet.h"
  TrieSet::TrieSet (){
    root = helper1();
    root->parent=NULL;
    root->inSet=true;
  }

  TrieSet::~TrieSet (){
      for(int i=0;i<30;i++){
          
      }
  } // destructor
  void TrieSet::insert (std::string input){
    TrieNode *temp = root;

    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (temp->children[helper(input[i])] == NULL){
            temp->children[helper(input[i])] = helper1();
            temp->children[helper(input[i])]->parent = temp;       

         }
            temp = temp->children[helper(input[i])];
    }
       temp->inSet=true; 
 
    // mark last node as leaf
  }

  void TrieSet::remove (std::string input){
    if(!contains(input)){
        return;
      }

    int count = 0;
    TrieNode *temp = root;
 
    for (unsigned int  i = 0; i < input.length(); i++)
    {
        temp = temp->children[helper(input[i])];
    }

    for (unsigned int  i = 0; i < 30; ++i) {
        if (temp->children[i] != NULL) {
            ++count;
        }
    }

    if(count!=0){
      temp->inSet=false;
      return;
    }

    TrieNode * parentnode;

 while (temp->parent != NULL && count == 0) {

        parentnode = temp->parent;

        for (int i = 0; i < 30; ++i) {
          if (parentnode->children[i] != NULL) {
            if (temp== parentnode->children[i]) {

                  parentnode->children[i] = NULL;
                  free(temp);
               temp = parentnode;
              } 
            
          }
        }
    }
  }


  bool TrieSet::contains (std::string input){
    TrieNode *temp = root;
 
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (temp->children[helper(input[i])] == NULL){
            return false;
          }
 
        temp = temp->children[helper(input[i])];
    }
    return (temp != NULL && temp->inSet);
}


  TrieNode* TrieSet::helper1(){


    TrieNode *newnode =  new TrieNode;
 
    newnode->inSet= false;
 
    for (int i = 0; i < 30; i++){
        newnode->children[i] = NULL;
      }
 
    return newnode;
  }

    int TrieSet::helper(char& input) {
    if(isalpha(input)){
      return input-92;
    }
     if(input=='.'){
      return 1;
     }
     if(input=='/'){
      return 2;
     }
     if(input==':'){
      return 3;
     }
     if(input=='_'){
      return 4;
     }
     return 0;
  }
