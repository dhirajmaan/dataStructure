/*
    tree travresla is quite easy if we use recursion but it may be tuff if we have
    to do it iteratively 

    so let's change the recursive solution into iterative using stack as recursion also 
    uses stack


    let's take example of postorder traversal

                            1
                        /       \
                      3           5
                  /    \         /    \
                7       9       4      2  

      if(root==null)
            return;
      postorder(root->left);
      postorder(root->right);
      coutroot->data<<" ";

      what happens here id DFS of left and then DFS of right and then finally we print 

*/
#include <iostream>
#include "BinarytreeNode.h"
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
BinarytreeNode<int> *takeInputLeveWise()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinarytreeNode<int> *root = new BinarytreeNode<int>(rootData);
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        //for left child
        int leftData;
        cout << "Enter the left Child of " << front->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinarytreeNode<int> *leftChild = new BinarytreeNode<int>(leftData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }
        //for right chld
        int rightData;
        cout << "Enter the right Child of " << front->data << endl;
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
void printBinaryTreeLevelWise(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : ";
        if (front->left != NULL)
        {
            cout << " L " << front->left->data;
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << " R " << front->right->data;
            pendingNodes.push(front->right);
        }
        cout << endl;
    }
}
void postorder(BinarytreeNode<int> *root)
{ /*
    here we are using map which introduces an extra space complexcity in our 
    solution 
     the solution below is only using stack
    */
    unordered_map<BinarytreeNode<int> *, int> count;
    stack<BinarytreeNode<int> *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        BinarytreeNode<int> *current = stack.top();
        if (current == nullptr)
        {
            stack.pop();
            continue;
        }
        if (count[current] == 0)
            stack.push(current->left);
        else if (count[current] == 1)
            stack.push(current->right);

        else if (count[current] == 2)
            cout << current->data << " ";
        else
            stack.pop();
        count[current]++;
    }
}
void postorder_withoutMap(BinarytreeNode<int> *root)
{
    stack<pair<BinarytreeNode<int> *, int>> stack;
    stack.push({root, 0});
    while (!stack.empty())
    {
        pair<BinarytreeNode<int> *, int> top = stack.top();
        BinarytreeNode<int> *current = top.first;
        int count = top.second;

        stack.pop();
        if (current == nullptr or count == 3)
        {
            continue;
        }

        stack.push({current, count + 1});

        if (count == 0)
            stack.push({current->left, 0});
        else if (count == 1)
            stack.push({current->right, 0});
        else if (count == 2)
            cout << current->data << " ";
    }
}
//1 2 3 4 5 -1 -1 -1 -1 6 7 8 -1 -1 -1 -1 -1
//pre-order  1 2 4 5 6 8 7 3
//inOrder    4 2 8 6 5 7 1 3
//3 5 7 9 4 2 8 -1 -1 -1 -1 -1 -1 -1 -1
void function(BinarytreeNode<int> *root)
{
    stack<pair<BinarytreeNode<int> *, int>> s;
    s.push({root, 0});
    while (!s.empty())
    {
        pair<BinarytreeNode<int> *, int> top = s.top();
        BinarytreeNode<int> *current = top.first;
        int count = top.second;

        s.pop();
        if (current == nullptr or count == 3)
        {
            continue;
        }

        s.push({current, count + 1});
        if (count == 0)
            cout << current->data << " ";
        else if (count == 1)
            s.push({current->left, 0});
        else if (count == 2)
            s.push({current->right, 0});
    }
}
int main()
{
    BinarytreeNode<int> *root = takeInputLeveWise();
    printBinaryTreeLevelWise(root);
    postorder(root);
    cout << endl;
    postorder_withoutMap(root);
    return 0;
}