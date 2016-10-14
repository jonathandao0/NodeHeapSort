#include "stdafx.h"
#include <iostream>
#include <string>
#include <bitset>
#include "Heap.h"
#include "Node.h"

using namespace std;

Heap::Heap(){
	root = NULL;
}

Heap::Heap(Node *r){
	root = r;
}

bool Heap::empty(){
	if (root == NULL)
		return true;
	else
		return false;
}

void Heap::insert(Node *root, Node *n, unsigned int i){
	unsigned int index = i;															// i = node # to be placed
	if (empty()){	// if tree is empty
		root->data = n->data;
	}
	if (i >= 4){																	// Only do this for heaps with 4 or more nodes, else, just place values
		bitset<8> t = i;															// Convert i to a binary string
		string bitString = t.to_string();

		while (*bitString.begin() == '0')											// Remove all leading 0's
			bitString = bitString.erase(0, 1);	
		bitString = bitString.erase(0, 1);											// Remove most significant 1
		bitString = bitString.erase(bitString.size() - 1, bitString.size());		// Remove least significant bit

		int length = bitString.size();

		for (int i = 0; i < length; i++){											// Traverse tree based on binary value of the node # to be placed
			if (*bitString.begin() == '0'){
				root = root->Left;
				bitString = bitString.erase(0, 1);
			}
			else if (*bitString.begin() == '1'){
				root = root->Right;
				bitString = bitString.erase(0, 1);
			}
		}
	}
	
	if (root->Left == NULL){
		root->Left = n;
		n->Parent = root;
		swapUp(n);
	}
	else if (root->Right == NULL){
		root->Right = n;
		n->Parent = root;
		swapUp(n);
	}
}

void Heap::swapUp(Node *n){
	if (n->Parent != NULL){
		if (n->Parent->data < n->data){
			int tmp = n->Parent->data;
			n->Parent->data = n->data;
			n->data = tmp;
			swapUp(n->Parent);
		}
	}
}

void Heap::swapDown(Node *n){
	if (n->Right != NULL){
		if (n->Left->data > n->data && n->Left->data > n->Right->data){
				int tmp = n->data;
				n->data = n->Left->data;
				n->Left->data = tmp;
				swapDown(n->Left);
		}
		else if (n->Right->data < n->data){
			// Do nothing, this is needed or the code will break with duplicates once you reach the last few nodes
		}
		else {
			int tmp = n->data;
			n->data = n->Right->data;
			n->Right->data = tmp;
			swapDown(n->Right);
		}
	}
	else if (n->Left != NULL){
		if (n->Left->data > n->data){
			int tmp = n->data;
			n->data= n->Left->data;
			n->Left->data = tmp;
			swapDown(n->Left);
		}
	}
}

/*
bool Heap::search(Node *root, int key){
	if (root == NULL)
		return false;
	else{
		if (root->data == key)
			return true;
		else{
			if (root->data > key)
				search(root->Left, key);
			else // if(root->data < key)
				search(root->Right, key);
		}
	}
}
*/

int Heap::retrieveLargest(Node *root){
	if (empty())
		cout << "Heap is empty" << endl;
	else{
		return root->data;
	}
}

void Heap::removeLargest(Node *root, unsigned int i){
	if (empty() || i <= 0)
		cout << "Heap is empty" << endl;
	else{
		Node *last = root;												// Only do this for heaps with 4 or more nodes, else, just place values
		bitset<8> t = i;															// Convert i to a binary string
		string bitString = t.to_string();

		while (*bitString.begin() == '0')											// Remove all leading 0's
			bitString = bitString.erase(0, 1);
		bitString = bitString.erase(0, 1);											// Remove most significant 1

		int length = bitString.size();

		for (int i = 0; i < length; i++){											// Traverse tree beased on binary value of the node # to be placed
			if (*bitString.begin() == '0'){
				last = last->Left;
				bitString = bitString.erase(0, 1);
			}
			else if (*bitString.begin() == '1'){
				last = last->Right;
				bitString = bitString.erase(0, 1);
			}
		}

		root->data = last->data;
		if (last->Parent != NULL){
			if (last->Parent->Left == last)
				last->Parent->Left = NULL;
			else if(last->Parent->Right == last)
				last->Parent->Right = NULL;
			last = NULL;
		}
		swapDown(root);
	}
}

void Heap::heapSort(Node *root, unsigned int i){
	while (i >= 1){
		if (retrieveLargest(root) < 10)
			cout << "  " << retrieveLargest(root) << endl;
		else if (retrieveLargest(root) < 100)
			cout << " " << retrieveLargest(root) << endl;
		else
			cout << retrieveLargest(root) << endl;
		removeLargest(root, i);
		i--;
	}
}

/*
void Heap::remove(Node *n){
	Node *xpred;
	//Node *xsucc;
	if ((n->Left == NULL) && (n->Right == NULL)){
		if (n->Parent != NULL){							//leaf
			if (n->data > n->Parent->data)
				n->Parent->Right = NULL;
			else
				n->Parent->Left = NULL;
		}
		else{											//root, no children
			root = NULL;
			cout << "\n The tree is empty now \n";
		}
	}
	//one right child, no left child
	if ((n->Right != NULL) && (n->Left == NULL)){
		if (n->data > n->Parent->data){
			n->Parent->Right = n->Right;
			n->Right->Parent = n->Parent;
		}
		else{
			n->Parent->Left = n->Right;
			n->Right->Parent = n->Parent;
		}
	}
	//one left child, no right child
	if ((n->Right == NULL) && (n->Left != NULL)){
		if (n->data > n->Parent->data){
			n->Parent->Right = n->Left;
			n->Left->Parent = n->Parent;
		}
		else{
			n->Parent->Left = n->Left;
			n->Left->Parent = n->Parent;
		}
	}
	//two childern, find the successor, replace, and remove
	/*
	if ((n->Right != NULL) && (n->Left != NULL)){		
		xsucc = n->Right;
		while (xsucc->Left != NULL)
			xsucc = xsucc->Left;
		n->data = xsucc->data;
		if (xsucc->Right != NULL)
			xsucc->Parent->Left = xsucc->Right;
		else
			xsucc->Parent->Left = '\0';
	}
	//
	//DIY for the predecessor version
	if ((n->Right != NULL) && (n->Left != NULL)){
		xpred = n->Left;
		while (xpred->Right != NULL)
			xpred = xpred->Right;
		n->data = xpred->data;
		if (xpred->Left != NULL){
			xpred->Parent->Right = xpred->Left;
			xpred->Left->Parent = xpred->Parent;
		}
		else
			xpred->Parent->Right = '\0';
	}
}
*/


// Beaks past 72 Nodes?
void Heap::inorder(Node *root){
	if (root != NULL){
		inorder(root->Left);
		if (root->data < 10)
			cout << "  " << root->data << endl;
		else if (root->data < 100)
			cout << " " << root->data << endl;
		else
			cout << root->data << endl;
		inorder(root->Right);
	}
}

void Heap::preorder(Node *root){
	if (root != NULL){
		if (root->data < 10)
			cout << " " << root->data << endl;
		else
 			cout << root->data << endl;
		preorder(root->Left);
		preorder(root->Right);
	}
}

void Heap::postorder(Node *root){
	if (root != NULL){
		postorder(root->Left);
		postorder(root->Right);
		if (root->data < 10)
			cout << " " << root->data << endl;
		else
			cout << root->data << endl;
	}
}