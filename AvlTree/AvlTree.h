#pragma once
#include <string>

class avl_tree
{
public:
	avl_tree();
	~avl_tree();
	void insert(int key);
	void remove(int key);
	bool search(int key);
	void print();
private:
	struct Node
	{
		int key;
		Node* left;
		Node* right;
		int height;
	};
	Node* root;
	Node* insert(Node* node, int key);
	Node* remove(Node* node, int key);
	Node* search(Node* node, int key);
	std::string print(Node* node);
	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);
	Node* rotateRightLeft(Node* node);
	Node* rotateLeftRight(Node* node);
	int height(Node* node);
	Node* balance(Node* node);
	int balanceFactor(Node* node);
	void fixHeight(Node* node);
	Node* findMin(Node* node);
	Node* removeMin(Node* node);
	void deleteTree(Node* node);
};