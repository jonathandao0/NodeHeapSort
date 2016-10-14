#pragma once
#include "Node.h"

class Heap{
	public:
		Node* root;
		Heap();
		Heap(Node*);
		bool empty();
		//bool search(Node *root, int key);
		void search(Node *root, int key);
		void insert(Node *root, Node * n, unsigned int i);
		int retrieveLargest(Node *root);
		void removeLargest(Node *root, unsigned int i);
		void heapSort(Node *root, unsigned int i);
		void swapUp(Node *n);
		void swapDown(Node *n);
		//void remove(Node *n);
		void inorder(Node *r);
		void preorder(Node *r);
		void postorder(Node *r);
};