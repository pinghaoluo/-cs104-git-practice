#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "bst.h"
/**
* A special kind of node for an AVL tree, which adds the height as a data member, plus 
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template<typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
	// Constructor/destructor.
	AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
	virtual ~AVLNode();

	// Getter/setter for the node's height.
	int getHeight() const;
	void setHeight(int height);

	// Getters for parent, left, and right. These need to be redefined since they 
	// return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
	// for more information.
	virtual AVLNode<Key, Value>* getParent() const override;
	virtual AVLNode<Key, Value>* getLeft() const override;
	virtual AVLNode<Key, Value>* getRight() const override;

protected:
	int mHeight;
};

/*
--------------------------------------------
Begin implementations for the AVLNode class.
--------------------------------------------
*/

/**
* Constructor for an AVLNode. Nodes are initialized with a height of 0.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent)
	: Node<Key, Value>(key, value, parent)
	, mHeight(0)
{

}

/**
* Destructor.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* Getter function for the height. 
*/
template<typename Key, typename Value>
int AVLNode<Key, Value>::getHeight() const
{
	return mHeight;
}

/**
* Setter function for the height. 
*/
template<typename Key, typename Value>
void AVLNode<Key, Value>::setHeight(int height)
{
	mHeight = height;
}

/**
* Getter function for the parent. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getParent() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mParent);
}

/**
* Getter function for the left child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getLeft() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mLeft);
}

/**
* Getter function for the right child. Used since the node inherits from a base node.
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLNode<Key, Value>::getRight() const
{
	return static_cast<AVLNode<Key,Value>*>(this->mRight);
}

/*
------------------------------------------
End implementations for the AVLNode class.
------------------------------------------
*/

/**
* A templated balanced binary search tree implemented as an AVL tree.
*/
template<class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
	// Methods for inserting/removing elements from the tree. You must implement
	// both of these methods. 
	virtual void insert(const std::pair<Key, Value>& keyValuePair) override;
	void remove(const Key& key);

private:
	/* Helper functions are strongly encouraged to help separate the problem
	   into smaller pieces. You should not need additional data members. */
	void newHeight(AVLNode <Key, Value>* node);
	void insertintree( std::pair<Key, Value>& keyValuePair);
	AVLNode<Key,Value>* helper(AVLNode<Key,Value> *parent,AVLNode<Key,Value> *node,std::pair<Key, Value>& keyValuePair);
	AVLNode<Key, Value>* leftrotate(AVLNode<Key,Value> *node);
	AVLNode<Key, Value>* rightrotate(AVLNode<Key,Value> *node);
	int banlancehelper();

};
/*
--------------------------------------------
Begin implementations for the AVLTree class.
--------------------------------------------
*/

/**
* Insert function for a key value pair. Finds location to insert the node and then balances the tree. 
*/
template<typename Key, typename Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::rightrotate(AVLNode<Key,Value> *node){
	AVLNode<Key, Value>* b = static_cast<AVLNode<Key,Value>*>(node->getLeft());
	b->setParent(node->getParent());
	node->setLeft(b->getRight());

	if(node->getLeft() !=NULL){
		node->getLeft()->setParent(node);
	}

	b->setRight(node);
	node->setParent(b);
	balance(node);
	balance(b);
	return b;
}


template<typename Key, typename Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::leftrotate(AVLNode<Key,Value> *node){
	AVLNode<Key, Value>* b = static_cast<AVLNode<Key,Value>*>(node->getRigh());
	b->setParent(node->getParent());
	node->setRight(b->getLeft());

	if(node->getRight() !=NULL){
		node->getRight()->setParent(node);
	}

	b->setLeft(node);
	node->setParent(b);
	balance(node);
	balance(b);
	return b;
}

 

template<typename Key, typename Value>
void AVLTree<Key, Value>::insertintree(std::pair<Key, Value>& keyValuePair)
{
	// TODO
	mRoot = helper(NULL,static_cast<AVLNode<Key,Value>*>(BinarySearchTree<Key, Value>::mRoot),keyValuePair);
}


template<typename Key, typename Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::helper(AVLNode<Key,Value> *parent,AVLNode<Key,Value> *node,std::pair<Key, Value>& keyValuePair){
if(node == NULL){
	AVLNode <Key,Value> * item = new AVLNode <Key,Value> (keyValuePair.first,keyValuePair.second,parent);
	node=item;
	node->setHeight(parent->getHeight()+1);
}
if(keyValuePair.first==node->getKey()){
	 node->setValue(keyValuePair.second);
	 }
else if(keyValuePair.first>=node->getKey()){
	parent = node;
	 node->setRight(helper(parent,node->getRight(),keyValuePair));
}
else if(keyValuePair.first < node->getKey()){
	parent = node;
	 node->setLeft(helper(parent,node->getLeft(),keyValuePair));
}
// Feel free to modify any return values or parameters.
return node;
}




template<typename Key, typename Value>
void AVLTree<Key, Value>::newHeight(AVLNode<Key, Value>* node){
	 if (node->getLeft() == NULL && node->getRight() == NULL){
        return -1;
    }
    else if(node->getLeft()==NULL){
    	node->setHeight(node->getRight()->getHeight()+1);
    }
    else if(node->getRight()==NULL){
    	node->setHeight(node->getLeft()->getHeight()+1);
    }
    else{
	int a=node->getLeft()->getHeight();
	int b=node->getRight()->getHeight();	
	node->setHeight((a>b?a:b)+1);
	}
	}


template<typename Key, typename Value>
void AVLTree<Key, Value>::newHeight(AVLNode<Key, Value>* node){
	 if (node->getLeft() == NULL && node->getRight() == NULL){
        return -1;
    }
    else if(node->getLeft()==NULL){
    	node->setHeight(node->getRight()->getHeight()+1);
    }
    else if(node->getRight()==NULL){
    	node->setHeight(node->getLeft()->getHeight()+1);
    }
    else{
	int a=node->getLeft()->getHeight();
	int b=node->getRight()->getHeight();	
	node->setHeight((a>b?a:b)+1);
	}
	}


template<typename Key, typename Value>
void AVLTree<Key, Value>::rebalance(AVLNode<Key, Value>* node){
	newHeight(node);
	if((node->getRight()->getHeight()-node->getLeft()->getHeight())==-2){
		if()
	}

}



    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

	int AVLTree<Key, Value>::banlancehelper(){
		return (node->getRight()->getHeight()-node->getLeft()->getHeight());
	}



void AVLtree<T>::rebalance(AVLnode<T> *n) {
    setBalance(n);
 
    if (n->balance == -2) {
        if (height(n->left->left) >= height(n->left->right))
            n = rotateRight(n);
        else
            n = rotateLeftThenRight(n);
    }
    else if (n->balance == 2) {
        if (height(n->right->right) >= height(n->right->left))
            n = rotateLeft(n);
        else
            n = rotateRightThenLeft(n);
    }
 
    if (n->parent != NULL) {
        rebalance(n->parent);
    }
    else {
        root = n;
    }
}










template<typename Key, typename Value>
void AVLTree<Key, Value>::insert(const std::pair<Key, Value>& keyValuePair)
{
	// TODO

}

/**
* Remove function for a given key. Finds the node, reattaches pointers, and then balances when finished. 
*/
template<typename Key, typename Value>
void AVLTree<Key, Value>::remove(const Key& key)
{
	// TODO

}

/*
------------------------------------------
End implementations for the AVLTree class.
------------------------------------------
*/

#endif