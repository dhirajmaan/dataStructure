#include <iostream>
using namespace std;
#include "BinarytreeNode.h"
#include <queue>
#include <algorithm> //this has the reverse function
#include <stack>

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
//this solution checks the size of queue to find the new level
//and doesnot return anything just prints
void printLevelWise1(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        //this n helps us to find the no element in the particular level
        int n = pendingNodes.size();
        while (n > 0)
        {
            BinarytreeNode<int> *front = pendingNodes.front();
            //we pop out as mush as the size
            pendingNodes.pop();
            cout << front->data << " ";
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            n--;
        }
        cout << endl;
    }
}
//this solution also checks the size of the queue to find out the next level
//but returns a vector<vector<int>> or list of list
vector<vector<int>> printLevelWise2(BinarytreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        int n = pendingNodes.size();

        vector<int> smallAns;
        while (n > 0)
        {
            BinarytreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            smallAns.push_back(front->data);
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            n--;
        }
        ans.push_back(smallAns);
    }
    return ans;
}
//this solution insert null in the queue to differentiate between different level
//and return a 2d vector or 2d list
vector<vector<int>> printLevelWise3(BinarytreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    vector<int> smallAns;
    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        if (front == NULL)
        {
            if (pendingNodes.empty())
            {
                break;
            }
            else
            {
                ans.push_back(smallAns);
                smallAns.clear();
                pendingNodes.push(NULL);
            }
        }
        else
        {
            smallAns.push_back(front->data);
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            if (front->left == NULL and front->right == NULL)
            {
                pendingNodes.push(NULL);
            }
        }
    }
    return ans;
}
vector<vector<int>> zigzagLevelOrder1(BinarytreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    int level = 1;
    while (!pendingNodes.empty())
    {
        int n = pendingNodes.size();
        vector<int> smallAns;
        while (n > 0)
        {
            BinarytreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            smallAns.push_back(front->data);
            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }
            n--;
        }
        if (level % 2 == 0)
        {
            reverse(smallAns.begin(), smallAns.end());
            ans.push_back(smallAns);
            level++;
        }
        else
        {
            ans.push_back(smallAns);
            level++;
        }
    }
    return ans;
}
//time complexcity is O(n) and space is O(n)+(n)=n
void zigzagLevelOrder2(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<BinarytreeNode<int> *> a;
    stack<BinarytreeNode<int> *> b;
    a.push(root);
    while (!a.empty() or !b.empty())
    {
        while (!a.empty())
        {
            BinarytreeNode<int> *aTop = a.top();
            a.pop();
            cout << aTop->data << " ";
            if (aTop->left != NULL)
            {
                b.push(aTop->left);
            }
            if (aTop->right != NULL)
            {
                b.push(aTop->right);
            }
        }
        cout << endl;

        while (!b.empty())
        {
            BinarytreeNode<int> *bTop = b.top();
            b.pop();
            cout << bTop->data << " ";
            if (bTop->right != NULL)
            {
                a.push(bTop->right);
            }
            if (bTop->left != NULL)
            {
                a.push(bTop->left);
            }
        }
        cout << endl;
    }
}
void zigzagLevelOrder3(BinarytreeNode<int> *root)
{
    stack<BinarytreeNode<int> *> currentLevel;
    stack<BinarytreeNode<int> *> NextLevel;
    currentLevel.push(root);
    bool leftToRight = true;
    // vector<int> ans;
    while (!currentLevel.empty())
    {
        BinarytreeNode<int> *front = currentLevel.top();
        currentLevel.pop();
        // ans.push_back(front->data);
        cout << front->data << " ";
        if (leftToRight)
        {
            if (front->left)
            {
                NextLevel.push(front->left);
            }
            if (front->right)
            {
                NextLevel.push(front->right);
            }
        }
        else
        {
            if (front->right)
            {
                NextLevel.push(front->right);
            }
            if (front->left)
            {
                NextLevel.push(front->left);
            }
        }

        if (currentLevel.empty())
        {
            leftToRight != leftToRight;
            swap(currentLevel, NextLevel);
            cout << endl;
        }
    }
}

//1 2 3 4 5 -1 -1 -1 -1 6 7 8 -1 -1 -1 -1 -1

int main()
{
    BinarytreeNode<int> *root = takeInputLeveWise();
    printLevelWise1(root);
    zigzagLevelOrder3(root);
    // cout << "ans with vector" << endl;
    // vector<vector<int>> ans = printLevelWise2(root);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "this ans is of 3" << endl;
    // vector<vector<int>> ans1 = printLevelWise3(root);
    // for (int i = 0; i < ans1.size(); i++)
    // {
    //     for (int j = 0; j < ans1[i].size(); j++)
    //     {
    //         cout << ans1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}