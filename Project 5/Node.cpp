#pragma once
#include "stdafx.h"
#include "Node.h"

using namespace std;

Node::Node(){
	data = 0;
	Parent = '\0';
	Left = '\0';
	Right = '\0';
}

Node::Node(int d){
	data = d;
	Parent = '\0';
	Left = '\0';
	Right = '\0';
}
