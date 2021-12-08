#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
  ~Node()
  {
    delete left;
    delete right;
  }
};
Node *buildTree()
{
  int rootData;
  cout << "Enter root data" << endl;
  cin >> rootData;
  Node *root = new Node(rootData);

  queue<Node *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty())
  {
    Node *front = pendingNodes.front();
    pendingNodes.pop();
    int leftChildData;
    cout << "Enter left child of " << front->data << endl;
    cin >> leftChildData;
    if (leftChildData != -1)
    {
      Node *leftChild = new Node(leftChildData);
      front->left = leftChild;
      pendingNodes.push(leftChild);
    }
    int rightChildData;
    cout << "Enter right child of " << front->data << endl;
    cin >> rightChildData;
    if (rightChildData != -1)
    {
      Node *rightChild = new Node(rightChildData);
      front->right = rightChild;
      pendingNodes.push(rightChild);
    }
  }
  return root;
}
void printTree(Node *root)
{
  if (root == nullptr)
    return;

  queue<Node *> pendingNodes;
  pendingNodes.push(root);
  while (!pendingNodes.empty())
  {
    Node *front = pendingNodes.front();
    pendingNodes.pop();
    cout << front->data << " :";
    if (front->left)
    {
      cout << " L ";
      cout << front->left->data;
      pendingNodes.push(front->left);
    }
    if (front->right)
    {
      cout << " R ";
      cout << front->right->data;
      pendingNodes.push(front->right);
    }
    cout << endl;
  }
  return;
}
void printTreeRecursively(Node *root)
{
  if (!root)
    return;

  cout << root->data << " : ";
  if (root->left)
  {
    cout << " L " << root->left->data;
  }
  if (root->right)
  {
    cout << " R " << root->right->data;
  }
  cout << endl;
  printTreeRecursively(root->left);
  printTreeRecursively(root->right);
  return;
}
int main()
{

  Node *root = buildTree();
  printTreeRecursively(root);
  return 0;
}