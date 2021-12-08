#include <iostream>
using namespace std;
#include "D:\dataStructure\binaryTree\BinarytreeNode.h"
#include "D:\dataStructure\linklist1\node.h"
#include <queue>
#include <climits>
#include <vector>

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
bool searchNode(BinarytreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == k)
    {
        return true;
    }
    if (k < root->data)
    {
        return searchNode(root->left, k);
    }
    else
    {
        return searchNode(root->right, k);
    }
}
void printAllTheElementInTheRange(BinarytreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > min)
    {
        printAllTheElementInTheRange(root->left, min, max);
    }
    if (root->data <= max)
    {
        printAllTheElementInTheRange(root->right, min, max);
    }
    if (root->data <= max and root->data >= min)
    {
        cout << root->data << " ";
    }
}
int maxmimum(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->data, max(maxmimum(root->left), maxmimum(root->right)));
}
int minimum(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBst(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftMax = maxmimum(root->left);
    int rightMin = minimum(root->right);
    return (root->data > leftMax and root->data <= rightMin and isBst(root->left) and isBst(root->right));
}
//to return a triplet in recursion
class IsBst
{
public:
    int minimum;
    int maxmimum;
    bool isBst;
};
IsBst isBst_optimized(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        IsBst output;
        output.isBst = true;
        output.maxmimum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }
    IsBst leftOutput = isBst_optimized(root->left);
    IsBst rightoutput = isBst_optimized(root->right);
    int minimum = min(root->data, min(leftOutput.minimum, rightoutput.minimum));
    int maximum = max(root->data, max(leftOutput.maxmimum, rightoutput.maxmimum));
    bool isBstOutput = ((root->data > leftOutput.maxmimum) and (root->data <= rightoutput.minimum) and (leftOutput.isBst) and (rightoutput.isBst));
    IsBst output;
    output.minimum = minimum;
    output.maxmimum = maximum;
    output.isBst = isBstOutput;
    return output;
}
bool isBst_optimized2(BinarytreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < min or root->data > max)
    {
        return false;
    }
    bool isLeftOk = isBst_optimized2(root->left, min, root->data - 1);
    bool isRightOk = isBst_optimized2(root->right, root->data, max);
    return (isLeftOk and isRightOk);
}

BinarytreeNode<int> *bstFromArray(int *arr, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (ei + si) / 2;

    BinarytreeNode<int> *root = new BinarytreeNode<int>(arr[mid]);
    BinarytreeNode<int> *leftTree = bstFromArray(arr, si, mid - 1);
    BinarytreeNode<int> *rightTree = bstFromArray(arr, mid + 1, ei);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}
Node *bstToLinklist(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    Node *left = bstToLinklist(root->left);
    Node *right = bstToLinklist(root->right);
    Node *mid = new Node(root->data);
    if (left == NULL)
    {
        mid->next = right;
        return mid;
    }
    else
    {
        Node *temp = left;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = mid;
        mid->next = right;
        return left;
    }
}

pair<Node *, Node *> bstToLinklist_optimised(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node *, Node *> ans1;
        ans1.first = NULL;
        ans1.second = NULL;
        return ans1;
    }
    pair<Node *, Node *> left = bstToLinklist_optimised(root->left);
    pair<Node *, Node *> right = bstToLinklist_optimised(root->right);
    Node *mid = new Node(root->data);
    pair<Node *, Node *> ans;
    if (left.second != NULL)
    {
        left.second->next = mid;
    }
    mid->next = right.first;
    if (left.first != NULL)
    {
        ans.first = left.first;
    }
    else
    {
        ans.first = mid;
    }
    if (right.second != NULL)
    {
        ans.second = right.second;
    }
    else
    {
        ans.second = mid;
    }
    return ans;
}
vector<int> *pathToNode(BinarytreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == k)
    {
        vector<int> *ans = new vector<int>;
        ans->push_back(root->data);
        return ans;
    }
    vector<int> *left = pathToNode(root->left, k);
    vector<int> *right = pathToNode(root->right, k);
    if (left != NULL)
    {
        left->push_back(root->data);
        return left;
    }
    else if (right != NULL)
    {
        right->push_back(root->data);
        return right;
    }
    else
    {
        return NULL;
    }
}

//bst 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//

int main()
{
    BinarytreeNode<int> *root = takeInputLeveWise();
    // cout << searchNode(root, 12) << endl;
    // printAllTheElementInTheRange(root, 6, 10);
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // BinarytreeNode<int> *root = bstFromArray(arr, 0, 5);
    // IsBst ans = isBst_optimized(root);
    // cout << ans.isBst << endl;
    // cout << isBst_optimized2(root) << endl;
    // Node *head = bstToLinklist(root);
    // pair<Node *, Node *> head = bstToLinklist_optimised(root);
    // Node *head = head0.first;
    // while (head.first != head.second)
    // {
    //     cout << head.first->data << " ";
    //     head.first = head.first->next;
    // }
    vector<int> *apple = pathToNode(root, 2);
    for (int i = 0; i < apple->size(); i++)
    {
        cout << apple->at(i) << " ";
    }

    return 0;
}