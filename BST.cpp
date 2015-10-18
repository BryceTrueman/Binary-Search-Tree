/*
 * BST.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: bryce14
 */

#include "BST.h"

BST::BST() {
	// TODO Auto-generated constructor stub
	root == NULL;
}

BST::~BST() {
	// TODO Auto-generated destructor stub
	clear();
}


NodeInterface * BST::getRootNode() {
	return root;
}


bool BST::add(int data) {
	return recADD(root, data);
}

bool BST::recADD(Node*& T, int data) {
	if (findNode(data, T) == true) {
		return false;
	}
	if (T == NULL) {
		T = new Node(data);
		return true;
	}
	else {
		if (data < T->data){
			recADD(T->left, data);
		}
		else {
			recADD(T->right, data);
		}
	}
	return false;
}


bool BST::remove(int data) {
	return recREMOVE(root, data);
}

bool BST::recREMOVE(Node*& T, int data) {
	if (T == NULL) {
		return false;
	}
	if (T->data == data) {
		if (T->left == NULL && T->right != NULL) {//replace with right child
			Node* temp = T->right;
			delete T;
			T = temp;
			return true;
		}
		else if (T->right == NULL && T->left != NULL) {//replace with left child
			Node* temp = T->left;
			delete T;
			T = temp;
			return true;
		}
		else if (T->right == NULL && T->left == NULL) {//delete it and set it to NULL
			delete T;
			T = NULL;
			return true;
		}
		else {//replace with inorder predecessor
			Node* temp;
			Node* templeft;
			Node* tempright;
			Node* temp_root;
			temp_root = T;
			temp = findIOP(T);
			T = temp_root;
			tempright = T->right;
			templeft = T->left;
			delete T;
			T = temp;
			T->left = templeft;
			T->right = tempright;
		}
	}
	else {
		if (data < T->data){
			recREMOVE(T->left, data);
		}
		else {
			recREMOVE(T->right, data);
		}
	}
	return false;
}

Node*& BST::findIOP(Node*& T) {
	T = T->left;
	while (T->right != NULL) {
		T = T->right;
	}
	Node* temporary;
	temporary = T;
	T = T->left;
	return temporary;
}



void BST::clear() {
	if (root != NULL) {
		recCLEAR(root);
		root = NULL;
	}
}

void BST::recCLEAR(Node*& X) {
	if (X->left != NULL) {
		recCLEAR(X->left);
	}
	if (X->right != NULL) {
		recCLEAR(X->right);
	}
	if (X->right == NULL && X->left == NULL) {
		delete X;
		X = NULL;
	}
}

bool BST::findNode(int data, Node* curr) {
	if (curr == NULL) {
		return false;
	}
	if (data == curr->data) {
		return true;
	}
	else {
		if (data < curr->data){
			findNode(data, curr->left);
		}
		else {
			findNode(data, curr->right);
		}
	}
	return false;
}
