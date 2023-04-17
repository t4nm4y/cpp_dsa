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

int findDepth(Node* root, char x)
{
	if (root == NULL)
		return -1;

	int dist = -1;

	if ((root->data == x)||(dist = findDepth(root->left, x))>=0 || (dist = findDepth(root->right, x)) >= 0)
	return dist + 1;

	return dist;
}

int findHeightUtil(Node* root, char x,int& height)
{
	if (root == NULL) {
		return -1;
	}

	int leftHeight = findHeightUtil(
		root->left, x, height);

	int rightHeight= findHeightUtil(root->right, x, height);
	int ans = max(leftHeight, rightHeight) + 1;

	if (root->data == x)
		height = ans;

	return ans;
}
int findHeight(Node* root, char x)
{
	int h = -1;
	int maxHeight = findHeightUtil(root, x, h);
	return h;
}

int main()
{
	Node* root=new Node('A');
	root->left=new Node('B');
		root->left->left=new Node('D');
			root->left->left->left=new Node('H');
			root->left->left->right=new Node('I');
		root->left->right=new Node('E');
	root->right=new Node('C');
		root->right->left=new Node('F');
		root->right->right=new Node('G');

cout<<endl;
	for (int i = 0; i < 9; i++)
	{
		char c='A'+i;
		cout<<c<<endl;
		cout<<"Depth: "<< findDepth(root, c)<<endl;
		cout<<"Height: "<< findHeight(root, c)<<endl<<endl;
	}
	return 0;
}
