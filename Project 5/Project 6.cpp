// Project 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "Heap.h"
#include "Node.h"

using namespace std;

const int N = 100;

int _tmain(int argc, _TCHAR* argv[]){
	srand(time(NULL));
	Node *n = new Node[N+1];
	
	for (int i = 1; i <= N; i++){
		n[i].data = rand() % 100 + 1;					//Give each node a number between 1 and 100
	}

	Heap *myHeap = new Heap(&n[1]);
	
	// Print Nodes
	for (int i = 1; i <= N; i++){
		if (i < 10)
			cout << "  "<< i << ". " << n[i].data << endl;
		else if (i < 100)
			cout << " " << i << ". " << n[i].data << endl;
		else
			cout << i << ". " << n[i].data << endl;
	}
	cout << endl;

	for (int i = 2; i <= N; i++){
		myHeap->insert(&n[1], &n[i], (unsigned int)i);
	}

	int z = N;

	myHeap->heapSort(&n[1], z);

	return 0;
}

