#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include "BinarytreeNode.h"
using namespace std;

BinarytreeNode<int> *takeInput_levelWise()
{
    cout << "enter root data" << endl;
    int data;
    cin >> data;
    BinarytreeNode<int> *root = new BinarytreeNode<int>(data);
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter the left child of " << front->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            BinarytreeNode<int> *leftChild = new BinarytreeNode<int>(leftdata);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        int rightData;
        cout << "enter the right child of " << front->data << endl;
        cin >> rightData;
        if (rightData != -1)
        {
            BinarytreeNode<int> *rightChild = new BinarytreeNode<int>(rightData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
void printTree_levelwise(BinarytreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " :";
        if (front->left != nullptr)
        {
            cout << " L " << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right != nullptr)
        {
            cout << "R " << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
void getVerticesOrder(BinarytreeNode<int> *root, int hd, map<int, vector<int>> &m)
{
    if (root == nullptr)
        return;
    m[hd].push_back(root->data);
    getVerticesOrder(root->left, hd + 1, m);
    getVerticesOrder(root->right, hd - 1, m);
}
void verticalTraversal(BinarytreeNode<int> *root)
{
    map<int, vector<int>> m;
    getVerticesOrder(root, 0, m);
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        
    }
}

int main()
{
    BinarytreeNode<int> *root = takeInput_levelWise();
    printTree_levelwise(root);

    verticalTraversal(root);
}