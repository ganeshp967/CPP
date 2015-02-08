// Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <fstream>
#include <iostream>

using namespace std;


typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} btnode;	

typedef struct queue{
	btnode * head;
	btnode * tail;
	btnode * next;
} btqueue;



/*
Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
btnode * NewNode(int data) {
	node* node = new(btnode);// "new" is like "malloc" 
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	cout << "Node Created: Data = " << data << endl;
	return(node);
}


/*
Give a binary search tree and a number, inserts a new node
with the given number in the correct place in the tree.
Returns the new root pointer which the caller should
then use (the standard trick to avoid using reference
parameters).
*/
btnode * insert(struct node* node, int data) {
	// 1. If the tree is empty, return a new, single node 
	if (node == NULL) {
		return(NewNode(data));
	}
	else {
		// 2. Otherwise, recur down the tree 
		if (data <= node->data) node->left = insert(node->left, data);
		else node->right = insert(node->right, data);

		return(node); // return the (unchanged) node pointer 
	}
}

btnode * CreateTree(int numNodes){
	btnode * root;
	root = NewNode(rand());
	while (--numNodes){
		insert(root, rand());
	}
	return root;
}

/*
Given a binary search tree, print out
its data elements in increasing
sorted order.
*/
void printTree(btnode* node) {
	if (node == NULL) return;
	printTree(node->left);
	printf("%d ", node->data);
	printTree(node->right);
}

int _tmain(int argc, _TCHAR * argv[])
{
	
	
	int numNodes;
	btnode *root;

	cout << "Please enter  number of noded in the tree: ";
	cin >> numNodes;
	cin.ignore();
	cout << "You entered: " << numNodes << "\n";
	root = CreateTree(numNodes);
	printTree(root);
	cin.get();
	

	
}

