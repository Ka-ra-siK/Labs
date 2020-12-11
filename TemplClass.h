#pragma once
#include <iostream>

template <class T>
class BinaryTree
{
	struct node {
		T value;
		struct node* right;
		struct node* left;
	};

public:
	BinaryTree();
	~BinaryTree();
	void add(T val);
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	int size();
	bool lookup(T val);
	void deleteTree();
	void deleteNodeTree(T val);
	T getT();
private:
	struct node* root;
	int treeSize;
	void deleteTree(struct node* node);
	void add(struct node** node, T val);
	bool lookup(struct node* node, T val);
	void printPreOrder(struct node* node);
	void printInOrder(struct node* node);
	void printPostOrder(struct node* node);
	node* deleteNodeTree(struct node* nod, T val);
};

template <class T>
T BinaryTree<T>::getT() {
	return root->value;
}

template <class T>
BinaryTree<T>::BinaryTree() {
	this->root = NULL;
	this->treeSize = 0;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	deleteTree(this->root);
}

template <class T>
int BinaryTree<T>::size() {
	return this->treeSize;
}

template <class T>
void BinaryTree<T>::add(T val) {
	add(&(this->root), val);
}

template <class T>
void BinaryTree<T>::add(struct node** node, T val) {

	if (*node == NULL) {
		struct node* tmp = new struct node;
		tmp->value = val;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;

		this->treeSize++;
	}
	else {
		if (val > (*node)->value) {
			add(&(*node)->right, val);
		}
		else {
			add(&(*node)->left, val);
		}
	}
}

template <class T>
void BinaryTree<T>::printInOrder() {
	printInOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printInOrder(struct node* node) {
	if (node != NULL) {
		printInOrder(node->left);
		std::cout << node->value << ", ";
		printInOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPreOrder() {
	printPreOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printPreOrder(struct node* node) {
	if (node != NULL) {
		std::cout << node->value << ", ";
		printInOrder(node->left);
		printInOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPostOrder() {
	printPostOrder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::printPostOrder(struct node* node) {
	if (node != NULL) {
		printInOrder(node->left);
		printInOrder(node->right);
		std::cout << node->value << ", ";
	}
}

template <class T>
void BinaryTree<T>::deleteTree(struct node* node) {
	if (node != NULL && (int)(node->value) != 0xDDDDDDDD) {
		deleteTree(node->left);
		deleteTree(node->right);
		delete node;
	}
}

template <class T>
void BinaryTree<T>::deleteTree() {
	deleteTree(this->root);
}

template <class T>
typename BinaryTree<T>::node* BinaryTree<T>::deleteNodeTree(struct node* nod, T val) {
	if (nod == NULL)
		return nod;

	if (val == nod->value) {

		node* tmp;
		if (nod->right == NULL)
			tmp = nod->left;
		else {

			node* ptr = nod->right;
			if (ptr->left == NULL) {
				ptr->left = nod->left;
				tmp = ptr;
			}
			else {

				node* pmin = ptr->left;
				while (pmin->left != NULL) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = nod->left;
				pmin->right = nod->right;
				tmp = pmin;
			}
		}
		delete nod;
		return tmp;
	}
	else if (val < nod->value)
		nod->left = deleteNodeTree(nod->left, val);
	else
		nod->right = deleteNodeTree(nod->right, val);
	return nod;
}

template <class T>
void BinaryTree<T>::deleteNodeTree(T val) {
	deleteNodeTree(this->root, val);
}

template <class T>
bool BinaryTree<T>::lookup(T val) {
	return lookup(this->root, val);
}

template <class T>
bool BinaryTree<T>::lookup(struct node* node, T val) {
	if (node == NULL) {
		return false;
	}
	else {
		if (val == node->value) {
			return node;
		}

		if (val > node->value) {
			return lookup(node->right, val);
		}
		else {
			return lookup(node->left, val);
		}
	}
}