#pragma once
#include "stdafx.h"

using namespace std;

class Node{
	public:
		int data;			// score
		Node *Parent;
		Node *Left;
		Node *Right;
		Node();
		Node(int d);
};