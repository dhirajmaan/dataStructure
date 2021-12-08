#include <iostream>
#include <queue>
using namespace std;
#include "D:\dataStructure\binaryTree\BinarytreeNode.h"
#include "D:\dataStructure\linklist1\node.h"
#include <climits>
#include <algorithm>

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
BinarytreeNode<int> *duplicateAndAttach(BinarytreeNode<int> *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left != NULL)
    {
        BinarytreeNode<int> *copyNode = new BinarytreeNode<int>(root->data);
        BinarytreeNode<int> *temp = root->left;
        root->left = copyNode;
        copyNode->left = temp;
        copyNode->left = duplicateAndAttach(temp);
        root->right = duplicateAndAttach(root->right);
        return root;
    }
    if (root->right == NULL and root->left == NULL)
    {
        BinarytreeNode<int> *copyNode = new BinarytreeNode<int>(root->data);
        root->left = copyNode;
        return root;
    }
}
void duplicateAndAttach2(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    duplicateAndAttach2(root->left);
    duplicateAndAttach2(root->right);

    BinarytreeNode<int> *path = root->left;
    BinarytreeNode<int> *newNode = new BinarytreeNode<int>(root->data);
    root->left = newNode;
    newNode->left = path;
}
/*print all  the pair of nodes which sum is equal to s*/
//the time complexcity of this approach is O(N^2) so we need to think something better
BinarytreeNode<int> *findNode(BinarytreeNode<int> *root, int s)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == s)
    {
        return root;
    }
    BinarytreeNode<int> *left = findNode(root->left, s);
    if (left != NULL)
    {
        return left;
    }
    else
    {
        BinarytreeNode<int> *right = findNode(root->right, s);
        return right;
    }
}
void printSumPair(BinarytreeNode<int> *root, BinarytreeNode<int> *currentNode, int s)
{
    if (currentNode == NULL or root == NULL)
    {
        return;
    }
    printSumPair(root, currentNode->left, s);
    printSumPair(root, currentNode->right, s);
    int rootData = currentNode->data;
    BinarytreeNode<int> *ans = findNode(root, s - rootData);
    if (ans != NULL and ans->data != INT_MIN)
    {
        cout << currentNode->data << " " << ans->data << endl;
        ans->data = INT_MIN;
    }

    return;
}
//this is the second method of print sum pair

//this is the helper function
void TreeIntoArray(BinarytreeNode<int> *root, vector<int> *arr)
{
    if (root == NULL)
    {
        return;
    }
    arr->push_back(root->data);
    TreeIntoArray(root->left, arr);
    TreeIntoArray(root->right, arr);
}
void printSumPairV1(BinarytreeNode<int> *root, int sum)
{
    vector<int> *sortedArray = new vector<int>;
    //changed our tree into an array
    TreeIntoArray(root, sortedArray);
    //sorted the array
    sort(sortedArray->begin(), sortedArray->end());
    int si = 0;
    int ei = sortedArray->size() - 1;
    while (ei > si)
    {
        if (sortedArray->at(si) + sortedArray->at(ei) == sum)
        {
            cout << sortedArray->at(si) << " " << sortedArray->at(ei) << endl;
            si++;
            ei--;
        }
        else if (sortedArray->at(si) + sortedArray->at(ei) < sum)
        {
            si++;
        }
        else
        {
            ei--;
        }
    }
}
BinarytreeNode<int> *lcaOfTwoNode(BinarytreeNode<int> *root, int node1, int node2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == node1 or root->data == node2)
    {
        return root;
    }
    else
    {
        BinarytreeNode<int> *left = lcaOfTwoNode(root->left, node1, node2);
        BinarytreeNode<int> *right = lcaOfTwoNode(root->right, node1, node2);
        if (left != NULL and right != NULL)
        {
            return root;
        }
        else if (left != NULL)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}
int lcaOfTwoNode_bst(BinarytreeNode<int> *root, int node1, int node2)
{
    if (root == NULL)
    {
        return -1;
    }
    if (node1 < root->data and node2 < root->data)
    {
        int left = lcaOfTwoNode_bst(root->left, node1, node2);
        if (left > 0)
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
    if (node1 >= root->data and node2 >= root->data)
    {
        int right = lcaOfTwoNode_bst(root->right, node1, node2);
        if (right > 0)
        {
            return right;
        }
        else
        {
            return -1;
        }
    }
    return root->data;
}
//
class ReturnType
{
public:
    int min;
    int max;
    bool is_bst;
    int h_bst;
};
ReturnType heightOfLargestBstInBinaryTree(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        ReturnType ans;
        ans.max = INT_MIN;
        ans.min = INT_MAX;
        ans.h_bst = 0;
        ans.is_bst = true;
        return ans;
    }
    ReturnType ansLeft = heightOfLargestBstInBinaryTree(root->left);
    ReturnType ansRight = heightOfLargestBstInBinaryTree(root->right);
    int minimum = min(root->data, min(ansLeft.min, ansRight.min));
    int maximum = max(root->data, max(ansLeft.max, ansRight.max));
    bool isBst_final = (root->data > ansLeft.max) and (root->data < ansRight.min) and (ansLeft.is_bst) and (ansRight.is_bst);
    int h_bst_final;
    if (isBst_final)
    {
        h_bst_final = max(ansLeft.h_bst, ansRight.h_bst) + 1;
    }
    else
    {
        h_bst_final = max(ansLeft.h_bst, ansRight.h_bst);
    }
    ReturnType ans;
    ans.max = maximum;
    ans.min = minimum;
    ans.h_bst = h_bst_final;
    ans.is_bst = isBst_final;
    return ans;
}
int sumOfRightTree(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->data + sumOfRightTree(root->right);
}
void replaceWithSumOfgreaterNodes(BinarytreeNode<int> *root, int PrevRootData)
{
    if (root == NULL)
    {
        return;
    }
    //time complexcity O(n)
    int tempRootData = root->data;
    root->data += PrevRootData + sumOfRightTree(root->right);
    replaceWithSumOfgreaterNodes(root->left, root->data);
    replaceWithSumOfgreaterNodes(root->right, PrevRootData);
}
int replaceWithSumOfgreaterNodes_optimized(BinarytreeNode<int> *root, int sum)
{
    if (root == nullptr)
    {
        return sum;
    }
    sum = replaceWithSumOfgreaterNodes_optimized(root->right, sum);
    sum+=root->data;
    root->data=sum;
}
// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
//8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
//binary tree with bst inside
//10 8 20 6 9 18 24 -1 -1 -1 -1 -1 -1 22 -1 -1 -1
//10 6 25 8 9 7 28 4 12 -1 -1 -1 -1 -1 -1 -1 5 -1 -1 -1 6 -1 -1
//
int main()
{
    BinarytreeNode<int> *root = takeInputLeveWise();
    // printBinaryTreeLevelWise(root);
    printLevelWise1(root);
    cout << "ans" << endl;
    // cout << "first" << endl;
    // root = duplicateAndAttach(root);
    // printBinaryTreeLevelWise(root);
    // cout << "second" << endl;

    // printBinaryTreeLevelWise(root);
    // printSumPair(root, root, 15);
    // BinarytreeNode<int> *ans = lcaOfTwoNode(root, 2, 10);
    // cout << ans->data << endl;
    // cout << lcaOfTwoNode_bst(root, 2, 10) << endl;
    // printSumPairV1(root, 15);
    // ReturnType output = heightOfLargestBstInBinaryTree(root);
    // cout << "height " << output.h_bst << endl;
    // cout << "is bst " << output.is_bst << endl;
    // cout << "min " << output.min << endl;
    // cout << "max " << output.max << endl;
    replaceWithSumOfgreaterNodes(root, 0);
    printLevelWise1(root);
}