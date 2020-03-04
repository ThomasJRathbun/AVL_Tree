#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <algorithm>
using namespace std;

//NODE CLASS
class node {


public:
	node* l;
	node* r;
	node* p;
	int key;
	node(int, node*);
	void printNode();
	node* createNode(int, node*);
};

//NODE FUNCTIONS
//Constructor
node::node(int key, node* p) {
	l = NULL;
	r = NULL;
	p = p;
	key = key;
};

node* createNode(int key, node* p) {
	node* temp = new node(key, p);
	temp->l = NULL;
	temp->r = NULL;
	temp->p = p;
	temp->key = key;
	return temp;
};

void node::printNode() {
	cout << key << endl;
};


//AVL CLASS
class avl_tree {



	//Utility
	int height(node*);
	int balanceFactor(node*);
	void balance(node*);
	void ll_rotate(node*);
	void lr_rotate(node*);
	void rr_rotate(node*);
	void rl_rotate(node*);

	//Recursive Functions
	node* insertRec(int, node*);

public:
	node* root;
	avl_tree();
	void insertRec(int);
	int height();

};

avl_tree::avl_tree() {
	root = NULL;
};

//UTILITY
void avl_tree::rr_rotate(node* root) {
	cout << "RR_ROTATE" << endl;
	node* A = root;
	node* B = root->r;
	node* C = B->r;

	A->r = B->l;
	B->l = A;
	B->r = C;

	root = B;
};

void avl_tree::ll_rotate(node* root) {
	cout << "A key " << root->key <<endl;
	cout << "B key " << (root->l)->key <<endl;
	node* A = root;
	cout << "set A" <<endl;
	node* B = root->l;
	cout << "set B" <<endl;
	node* C = B->l;
	cout << "set C" <<endl;

	A->l = B->r;
	B->r = A;
	B->l = C;

	root = B;
};


void avl_tree::lr_rotate(node* root) {
	rr_rotate(root->l);
	ll_rotate(root);
};

void avl_tree::rl_rotate(node* root) {
	rr_rotate(root->r);
	ll_rotate(root);
};


int avl_tree::height() {
	if (root)
		return height(root);
	else
		return 0;
};

int avl_tree::height(node* root) {
	if (root == NULL) {
		return 0;
	}
	else
		return max(height(root->l), height(root->r)) + 1;
};

int avl_tree::balanceFactor(node* root) {
	return (height(root->l) - height(root->r));
};

void avl_tree::balance(node* root) {
	cout << "BALANCING" << endl;
	cout << root->key << endl;
	int bf = balanceFactor(root);
	cout << "BF: " << bf << endl;
	if (bf < -1) {
		cout << "R";
		if (balanceFactor(root->r) < 0) {
			cout << "R" << endl;
			rr_rotate(root);
		}
		else {
			cout << "L" << endl;
			rl_rotate(root);
		}

	}
	else if (bf > 1) {
		cout << "L";
		if (balanceFactor(root->l) > 0) {
			cout << "L" << endl;
			ll_rotate(root);
		}
		else {
			cout << "R" << endl;
			lr_rotate(root);
		}
	}
	else
		return;
};

//RECURSION
void avl_tree::insertRec(int key) {
	this->root = insertRec(key, root);
};

node* avl_tree::insertRec(int key, node* root) {
	cout << "INSERTING" << endl;
	cout << key << endl;
	if (!root) {
		//node* temp = new node(key,root);
		return createNode(key, root);
	}

	if (key < root->key) {
		if (root->l)
			root->l = insertRec(key, root->l);
		else
			root->l = createNode(key, root);
	}
	else {
		if (root->r)
			root->r = insertRec(key, root->r);
		else
			root->r = createNode(key, root);
	}
	cout << "ROOT KEY: " << root->key <<endl;
	balance(root);

	return root;

};





#endif


