/*
 * BST.h
 *
 *  Created on: Mar 16, 2015
 *      Author: bryce14
 */

#ifndef BST_H_
#define BST_H_

#include "BSTInterface.h"
#include "NodeInterface.h"
#include "Node.h"

class BST: public BSTInterface {
public:
	BST();
	virtual ~BST();
	NodeInterface * getRootNode();
	Node*& findIOP(Node*& T);
	bool add(int data);
	bool recADD(Node*& T, int data);
	bool remove(int data);
	bool recREMOVE(Node*& T, int data);
	void clear();
	void recCLEAR(Node*& X);
	bool findNode(int data, Node* T);
private:
	Node* root = NULL;
};

#endif /* BST_H_ */

