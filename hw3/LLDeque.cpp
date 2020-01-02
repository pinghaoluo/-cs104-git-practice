#include <string>
#include "LLDeque.h"


  LLDeque::LLDeque (){
    sizea = 0;
    head=NULL;
    tail=NULL;
  } // initializes an empty deque
  

  LLDeque::~LLDeque (){
      while(head!=NULL){
        Node * temp =head->next;
        delete head;
        head=temp;
      }

  }// deallocates all dynamically allocated memory

  void LLDeque::pushback (char x){

  Node* n =new Node(x);
    
      if(isempty())
      {
        head=n;
        tail=n;
      }
      else
      {
        n->prev = tail;
        tail->next =n;
        tail = n;
      }
      sizea++;
  } // append x at one end of the deque.

  void LLDeque::popback (){
      if(!isempty()&& sizea!=1)
      { 
        Node* n;
        n= tail->prev;
        n->next=NULL;
        Node* temp =tail;
        tail=tail->prev;
        delete temp;
        sizea--;
      }
      else if(!isempty()&&sizea==1) {
        delete tail;
        head=NULL;
        tail=NULL;
        sizea--;
      }

  } /* remove at the same end of the deque.
                     Does nothing if called on an empty deque. */
  char LLDeque::getback (){
    if(!isempty())
    {
    return tail->data;
    }
    return 0;
    } /* returns the element at the same end of the deque.
                      Returns '\0' if called on an empty deque. */

  void LLDeque::pushfront (char x){
      Node* n=new Node(x);
      if(isempty())
      {
        head=n;
        tail=n;
      }
      else
      {
        n->next = head;
        head->prev =n;
        head = n;
      }
      sizea++;
  } // "prepend" x at the other end of the queue.

  void LLDeque::popfront (){
  if(!isempty()&&sizea!=1)
  { 
      Node*n;
      n= head->next;
      n->prev = NULL;
      Node* temp = head;
      head=head->next;
      delete temp;
      sizea--;
  }
  else if(!isempty()&&sizea==1) {
      delete head;
      head=NULL;
      tail=NULL;
      sizea--;
  }


  }/* remove at the other end of the deque.
                       Does nothing if called on an empty deque. */

  char LLDeque::getfront(){

      if(!isempty())
      {
        return head->data;
      }
      return 0;
      }
    // returns back item or -1 if empty list

  /* returns the element at the other end of the deque.
                      Returns `\0` if called on an empty deque. */

  bool LLDeque::isempty(){
      return (head == NULL && tail == NULL);
  }// returns whether the deque is empty.



