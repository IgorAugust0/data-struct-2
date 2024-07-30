// c++ program to check whether a given BT is full or not
#include <bits/stdc++.h>
using namespace std;

// Tree node structure
struct Node {
	int val;
	Node *left, *right;
};

// fun that creates and returns a new node
Node* newNode(int data)
{
	Node* node = new Node();
	node->val = data;
	node->left = node->right = NULL;
	return node;
}

// helper fun to check leafnode
bool isleafnode(Node* root)
{
	return !root->left && !root->right;
}

// fun checks whether the given BT is a full BT or not
bool isFullTree(Node* root)
{
	// if tree is empty
	if (!root)
		return true;

	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {

		root = q.front();
		q.pop();

		// null indicates - not a full BT
		if (root == NULL)
			return false;

		// if its not a leafnode then the current node
		// should contain both left and right pointers.
		if (!isleafnode(root)) {
			q.push(root->left);
			q.push(root->right);
		}
	}

	return true;
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	if (isFullTree(root))
		cout << "The Binary Tree is full\n";
	else
		cout << "The Binary Tree is not full\n";

	return 0;
}
// This code is contributed by Modem Upendra.
