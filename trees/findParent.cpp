#include <iostream>
using namespace std;
struct Node {
	char data;
	struct Node *left, *right;
	Node(char val)
	{
		data = val;
		left = right = NULL;
	}
};

void findParent(struct Node* node, char val, char parent)
{
	if (node == NULL)
		return;

	if (node->data == val)
		cout << parent;

	else {
		findParent(node->left, val, node->data);
		findParent(node->right, val, node->data);
	}
}

int main()
{
	struct Node* root = new Node('a');
	root->left = new Node('b');
	root->right = new Node('c');
	root->left->left = new Node('d');
	root->left->right = new Node('e');

    // if the root is the parent then cout<</
	findParent(root, 'd', '/');
	return 0;
}
