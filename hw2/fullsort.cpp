#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;




struct Node {
    int value;
    Node *next;
};



    Node* helper(Node* in){
        if(in->next==NULL){
            return in;
        }
        if(in->value>(in->next)->value){
            return in;
        }
        else{
            helper(in->next);
        }
    }



    Node* helper1(Node* in){
        if(in->next==NULL){
            return in;
        }
        else{
            helper1(in->next);
        }
    }

    Node* fullsort (Node* in){
    if(helper(in)==helper1(in)){
        return in;
        }
    else{
        helper1(in)->next=in;
        Node* newhead=helper(in)->next;
        helper(in)->next=NULL;
        return newhead;
        }
    }



