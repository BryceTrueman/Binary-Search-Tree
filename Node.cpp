/*
 * Node.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: bryce14
 */

#include "Node.h"

Node::Node(int newData) {
	// TODO Auto-generated constructor stub
	left = NULL;
	right = NULL;
	data = newData;
}

Node::~Node() {
	// TODO Auto-generated destructor stub
}

int Node::getData() {
	return data;
}

NodeInterface * Node::getLeftChild() {
	return left;
}


NodeInterface * Node::getRightChild() {
	return right;
}
