// LCA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct node {
	int key_value;
	node *left;
	node *right;
};

class btree {
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
	void destroy_tree();
	int findlca(int n1, int n2);
	

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
	node *findlca(node *leaf, int n1, int n2);
	node *root;

};

btree::btree()
{
	root=NULL;
}

btree::~btree()
{
	destroy_tree();
}

int btree::findlca(int n1, int n2)
{
	node *ret = findlca(root, n1, n2);
	if (ret != NULL)
		return ret->key_value;
	else
		return -1;
}

void btree::destroy_tree(node *leaf)
{
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf)
{
	if (key < leaf->key_value) {
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}
	else if (key >= leaf->key_value) {
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else {
			leaf->right	= new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}

node *btree::search(int key, node *leaf)
{
	if (leaf != NULL) {
		if (key == leaf->key_value)
			return leaf;
		if (key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else
		return NULL;
}

void btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

node *btree::search(int key)
{
	return search(key, root);
}

node *btree::findlca(node* leaf, int n1, int n2)
{
	if (leaf == NULL)
		return NULL;

	if ((leaf->key_value == n1) || (leaf->key_value == n2))
		return leaf;

	node *left_lca = findlca(leaf->left, n1, n2);
	node *right_lca = findlca(leaf->right, n1, n2);

	if (left_lca && right_lca) return leaf;

	return(left_lca != NULL) ? left_lca : right_lca;
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void loadTree(btree *bt)
{
	bt->insert(30);
	bt->insert(8);
	bt->insert(52);
	bt->insert(3);
	bt->insert(20);
	bt->insert(10);
	bt->insert(29);
}


int main(int argc, char *argv[])
{
	ifstream stream(argv[1]);
	string line;
	string tmp, n;	
	int a, b;
	btree *BT = new btree();
	loadTree(BT);
	while (getline(stream, line)) {
		if (line == "")
			continue;
		istringstream s2(line);
		s2 >> a;
		s2 >> b;
		cout << BT->findlca(a, b) << endl;
	}
	cin >> tmp;

	return 0;
}