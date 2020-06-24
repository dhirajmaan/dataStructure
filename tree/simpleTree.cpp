#include <iostream>
#include <queue>
#include "treeClass.h"
using namespace std;

TreeNode<int> *takeInputLevelwise()
{
	int rootData;
	cout << "enter the root data";
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);

	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while (pendingNodes.size() != 0)
	{

		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cout << "enter the number of children of " << front->data << endl;
		cin >> numChild;
		for (int i = 0; i < numChild; i++)
		{
			int childData;
			cout << "enter " << i + 1 << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int> *child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

TreeNode<int> *takeInput()
{
	cout << "enter root data";
	int rootData;
	cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	cout << "enter no of children";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

void printTreeLevelwise(TreeNode<int> *root)
{

	queue<TreeNode<int> *> pendingNode;
	pendingNode.push(root);

	while (pendingNode.size() != 0)
	{
		TreeNode<int> *front = pendingNode.front();
		pendingNode.pop();
		cout << front->data << ":";
		for (int i = 0; i < front->children.size(); i++)
		{
			cout << front->children[i]->data << ",";
			pendingNode.push(front->children[i]);
		}
		cout << endl;
	}
}

void printTree(TreeNode<int> *root)
{

	if (root == NULL) //this is edge  case, there's no base case , if we get a null tree we simply return
	{
		return;
	}
	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++)
	{
		cout << root->children[i]->data << ", ";
	}
	cout << endl;

	for (int i = 0; i < root->children.size(); i++)
	{
		printTree(root->children[i]);
	}
}

int numNode(TreeNode<int> *root)
{
	int ans = 1;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans = ans + numNode(root->children[i]);
	}
	return ans;
}

int sumOfNodes(TreeNode<int> *root)
{
	int ans = root->data;
	for (int i = 0; i < root->children.size(); i++)
	{
		ans = ans + sumOfNodes(root->children[i]);
	}
	return ans;
}

int maxData(TreeNode<int> *root)
{
	int ans = root->data;
	for (int i = 0; i < root->children.size(); i++)
	{
		int b = maxData(root->children[i]);
		if (ans < b)
		{
			ans = b;
		}
	}
	return ans;
}
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
	TreeNode<int> *ans = root;

	for (int i = 0; i < root->children.size(); i++)
	{
		TreeNode<int> *b = maxDataNode(root->children[i]);
		if (ans->data < b->data)
		{
			ans = b;
		}
	}
	return ans;
}

int findHeight(TreeNode<int> *root)
{
	int ans = 0;

	for (int i = 0; i < root->children.size(); i++)
	{
		int childHeight = findHeight(root->children[i]);
		if (childHeight > ans)
		{
			ans = childHeight;
		}
	}

	return ans + 1;
}

int countLeafNode(TreeNode<int> *root)
{
	int ans = 0;
	if (root->children.size() == 0)
	{
		ans++;
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		ans = ans + countLeafNode(root->children[i]);
	}
	return ans;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
	{
		printAtLevelK(root->children[i], k - 1);
	}
}

void preOrder(TreeNode<int> *root)
{
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++)
	{
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int> *root){
	for (int i = 0; i <root->children.size() ; i++)
	{
		postOrder(root->children[i]);
	}
	cout<<root->data<<" ";
	
}

// 10 3 20 30 40 2 40 50 0 0 0 0
int main()
{
	/*TreeNode<int> *root = new TreeNode<int>(1);

	root->children.push_back(node1);
	root->children.push_back(node2);
    */
	TreeNode<int> *root = takeInputLevelwise();

	printTreeLevelwise(root);
	cout << "-----------------------------";
	cout << sumOfNodes(root) << endl;
	cout << "-----------------------------";
	cout << numNode(root) << endl;
	cout << "-----------------------------";
	cout << maxData(root) << endl;
	TreeNode<int> *ansNode = maxDataNode(root);
	cout << (ansNode->data) << endl;

	cout << "-----------height-------------" << endl;
	cout << (findHeight(root)) << endl;
	cout << "-----------leaf node-------------" << endl;
	cout << countLeafNode(root) << endl;

	cout << "-----------at level k-------------" << endl;
	printAtLevelK(root, 2);
	cout << "\n";

	preOrder(root);
	cout << "\n";
	postOrder(root);
	cout<<"\n";

	//TODO delete tree
}
