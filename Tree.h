#pragma once
#include <iostream>
#include "Bankomat.h"
class node {
	Bankomat* bankTemp = new Bankomat(nullptr, 0);
public:
	node* right;
	node* left;
	Bankomat*& bank = bankTemp;
	node();
	node(Bankomat*& bank, node* right = nullptr, node* left = nullptr);
};
class BinTree :
	public node
{
public:
	BinTree();
	~BinTree();
	BinTree(node* t);
	void addBank(Bankomat*& bank);
	void showTree();
	node* removeBank(Bankomat*& bank);
	node* findBank(Bankomat*& bank);
	node* getRoot();
private:
	void insert(node*& t, Bankomat*& bank);
	node* findNode(node*& t, Bankomat*& bank);
	node* deleteNode(node*& t, Bankomat*& bank);
	node* minValueNode(node* root);
	node* root;
	void showNode(node*& t);
};
