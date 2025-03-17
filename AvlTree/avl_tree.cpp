#include "AvlTree.h"
#include <iostream>
#include <string>	


void avl_tree::deleteTree(Node* node)
{
	if (node == nullptr)
		return;
	deleteTree(node->left);
	deleteTree(node->right);
	delete node;
}

avl_tree::avl_tree()
{
	root = nullptr;
}

avl_tree::~avl_tree()
{
	deleteTree(root);
}

void avl_tree::insert(int key)
{
	root = insert(root, key);
}

/// <summary>
/// Method returns always root of the tree
/// </summary>
/// <param name="node"></param>
/// <param name="key"></param>
/// <returns></returns>
avl_tree::Node* avl_tree::insert(Node* node, int key)
{
	if (node == nullptr)
	{
		node = new Node;
		node->key = key;
		node->left = nullptr;
		node->right = nullptr;
		node->height = 1;
		return node;
	}
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return balance(node);
}

avl_tree::Node* avl_tree::balance(Node* node)
{
    fixHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->right) < 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->left) > 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

    int avl_tree::balanceFactor(Node* node)
    {
        return height(node->right) - height(node->left);
    }

    int avl_tree::height(Node* node)
    {
        return node ? node->height : 0;
    }

    void avl_tree::fixHeight(Node* node)
    {
        int hl = height(node->left);
        int hr = height(node->right);
        node->height = (hl > hr ? hl : hr) + 1;
    }

	avl_tree::Node* avl_tree::rotateRight(Node* node)
	{
		Node* temp = node->left;
		node->left = temp->right;
		temp->right = node;
		fixHeight(node);
		fixHeight(temp);
		return temp;
	}

	avl_tree::Node* avl_tree::rotateLeft(Node* node)
	{
		Node* temp = node->right;
		node->right = temp->left;
		temp->left = node;
		fixHeight(node);
		fixHeight(temp);
		return temp;
	}

	void avl_tree::print()
	{
		std::cout << print(root);
	}

    std::string avl_tree::print(Node* node)
    {
    if (node == nullptr)
    return "";

    std::string result = "";

    std::string lstr = print(node->left);
    if (node->left != nullptr)
		result += lstr + " <- ";

    result += "(" + std::to_string(node->key) + ")";

    if (node->right != nullptr)
		result += " -> " + print(node->right);

    return result;
    }

	void avl_tree::remove(int key)
	{
		root = remove(root, key);
	}

	avl_tree::Node* avl_tree::remove(Node* node, int key)
	{
		if (node == nullptr)
			return nullptr;
		if (key < node->key)
			node->left = remove(node->left, key);
		else if (key > node->key)
			node->right = remove(node->right, key);
		else
		{
			Node* left = node->left;
			Node* right = node->right;
			delete node;
			if (right == nullptr)
				return left;
			Node* min = findMin(right);
			min->right = removeMin(right);
			min->left = left;
			return balance(min);
		}
		return balance(node);
	}

	avl_tree::Node* avl_tree::findMin(Node* node)
	{
		return node->left ? findMin(node->left) : node;
	}

	avl_tree::Node* avl_tree::removeMin(Node* node)
	{
		if (node->left == nullptr)
			return node->right;
		node->left = removeMin(node->left);
		return balance(node);
	}

	bool avl_tree::search(int key)
	{
		Node* node = search(root, key);
		return node != nullptr;
	}

	avl_tree::Node* avl_tree::search(Node* node, int key)
	{
		if (node == nullptr)
			return nullptr;
		if (key < node->key)
			return search(node->left, key);
		else if (key > node->key)
			return search(node->right, key);
		else
			return node;
	}

