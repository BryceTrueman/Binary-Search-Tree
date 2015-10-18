/*
 * Node.h
 *
 *  Created on: Mar 16, 2015
 *      Author: bryce14
 */

#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

class Node: public NodeInterface {
public:
	Node(int newData);
	virtual ~Node();
	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
	int data = -1;
	Node* left = NULL;
	Node* right = NULL;



};

#endif /* NODE_H_ */
