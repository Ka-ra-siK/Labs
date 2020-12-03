#include "Tree.h"
#include <iostream>
#include <exception>
using std::cout;

node::node(){
	this->right = nullptr;
	this->left = nullptr;
}

node::node(Bankomat*& bank, node* right, node* left) {
	this->bank = bank;
	this->right = right;
	this->left = left;
}

BinTree::BinTree() {
	this->root = nullptr;
	bank = nullptr;
}

BinTree::~BinTree() {
	delete bank;
}

BinTree::BinTree(node* t) {
	this->root = t;
}

void BinTree::insert(node*& t, Bankomat*& bank) {
	if (t == nullptr) {
		t = new node(bank);
	}
	else {
		if (bank->getCurAmoun() < t->bank->getCurAmoun())
		{
			insert(t->left, bank);
		}
		else {
			insert(t->right, bank);
		}
	}
}

void BinTree::addBank(Bankomat*& bank) {
	insert(root, bank);
}

void BinTree::showNode(node*& t) {
	if (t != nullptr) {
		showNode(t->left);
		cout << t->bank->toString() << " " << std::endl;
		showNode(t->right);
	}
	else return;
}

void BinTree::showTree() {
	showNode(root);
}

node* BinTree::findNode(node*& t, Bankomat*& bank) {
	if (t == nullptr) {
		return nullptr;
	}
	if (t->bank->getCurAmoun() == bank->getCurAmoun()) {
		return t;
	}
	if (bank->getCurAmoun() <= t->bank->getCurAmoun()) {
		if (t->left != nullptr)
			return findNode(t->left, bank);
		else return nullptr;
	}
	else {
		if (t->right)
			return findNode(t->right, bank);
		else return nullptr;
	}
}

node* BinTree::findBank(Bankomat*& bank) {
	return findNode(root, bank);
}

node* BinTree::deleteNode(node*& root, Bankomat*& bank) {
	if (root == NULL) {
		return root;
	}
	if (bank->getCurAmoun() < root->bank->getCurAmoun())
		root->left = deleteNode(root->left, bank);
	else if (bank->getCurAmoun() > root->bank->getCurAmoun())
		root->right = deleteNode(root->right, bank);
	else {
		if (root->left == NULL) {
			node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			node* temp = root->left;
			free(root);
			return temp;
		}
		node* temp = minValueNode(root->right);
		root->bank = temp->bank;
		root->right = deleteNode(root->right, temp->bank);
	}
	return root;
}

node* BinTree::minValueNode(node* root){
	node* current = root;
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

node* BinTree::removeBank(Bankomat*& bank) {
	return deleteNode(this->root, bank);
}

node* BinTree::getRoot() {
	return root;
}