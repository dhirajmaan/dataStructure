#include <iostream>
#include <queue>
#include <climits>
using namespace std;
#include "BinarytreeNode.h"

#include "D:\dataStructure\linklist1\node.h"
void postOrderTraversal(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        postOrderTraversal(root->left);
    }
    if (root->right != NULL)
    {
        postOrderTraversal(root->right);
    }
    cout << root->data << " ";
}
void preOrderTraversal(BinarytreeNode<int> *root)
{
    cout << root->data << " ";

    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        preOrderTraversal(root->left);
    }
    if (root->right != NULL)
    {
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        inOrderTraversal(root->left);
    }
    cout << root->data << " ";
    if (root->right != NULL)
    {
        inOrderTraversal(root->right);
    }
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
void printBinaryTree(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";
    if (root->left != NULL)
    {
        cout << " L " << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << " R " << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
BinarytreeNode<int> *takeInputLeveWise()
{
    int rootData;
    cout << "Enter root Data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return nullptr;
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
int countNodes(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int findHeight(BinarytreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}
//this is not working
int findHeightOfElement(BinarytreeNode<int> *root, int k)
{
    int ans = -1;
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == k)
    {
        ans = 1;
        return ans;
    }
    else
    {
        ans = -1;
        return ans;
    }
    int leftAns = findHeightOfElement(root->left, k);
    int rightAns = findHeightOfElement(root->right, k);
    if (leftAns != -1)
    {
        ans + leftAns;
    }

    return ans;
}
void mirror(BinarytreeNode<int> *root)
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

        BinarytreeNode<int> *temp = front->left;
        front->left = front->right;
        front->right = temp;
        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
    }
}

void mirrorRecursively(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirrorRecursively(root->left);
    mirrorRecursively(root->right);
    BinarytreeNode<int> *temp = root->right;
    root->right = root->left;
    root->left = temp;
}
//this function is not working
BinarytreeNode<int> *buildTreeHelper(int *inorder, int *preorder, int inorderStart, int inorderEnd, int preorderStart, int preorderEnd)
{
    //base care
    if (inorderStart > inorderEnd)
    {
        return NULL;
    }
    int rootData = preorder[preorderStart];
    //find root data in inorder for root index in inorder
    int rootIndex = -1;
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInorderStart = inorderStart;
    int leftPreorderStart = preorderStart + 1;
    int leftInorderEnd = rootIndex - 1;
    int LeftPreorderEnd = leftInorderEnd - leftInorderStart + leftPreorderStart;
    int rightPreorderEnd = preorderEnd;
    int rightPreorderStart = leftInorderEnd + 1;
    int rightInorderStart = rootIndex + 1;
    int rightInorderEnd = inorderEnd;
    BinarytreeNode<int> *root = new BinarytreeNode<int>(rootData);
    root->left = buildTreeHelper(inorder, preorder, leftInorderStart, leftInorderEnd, leftPreorderStart, LeftPreorderEnd);
    root->right = buildTreeHelper(inorder, preorder, rightInorderStart, rightInorderEnd, rightPreorderStart, rightPreorderEnd);
    return root;
}
//this function is not working
BinarytreeNode<int> *buildTree(int *inorder, int *preorder, int size)
{
    return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
}

pair<int, int> findDiameter_optimized(BinarytreeNode<int> *root)
{
    //base case
    if (root == NULL)
    {
        pair<int, int> p;
        //height
        p.first = 0;
        //diameter
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = findDiameter_optimized(root->left);
    pair<int, int> rightAns = findDiameter_optimized(root->right);

    int leftHeigt = leftAns.first;
    int leftDiameter = leftAns.second;
    int rightHeight = rightAns.first;
    int rightDiameter = rightAns.second;

    int height = 1 + max(leftHeigt, rightHeight);
    //
    int diameter = max(leftHeigt + rightHeight, max(leftDiameter, rightDiameter));

    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}
int diameter(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int option1 = findHeight(root->left) + findHeight(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
pair<int, int> findMinMax(BinarytreeNode<int> *root)
{ //when the root is null we have to assing our min to MAXIMUM value
    //ans our max to MINIMUM value
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int, int> left = findMinMax(root->left);
    pair<int, int> right = findMinMax(root->right);

    int leftMin = left.first;
    int leftMax = left.second;
    int rightMin = right.first;
    int rightMax = right.second;

    int minValue = min(root->data, min(leftMin, rightMin));
    int maxValue = max(root->data, max(leftMax, rightMax));
    pair<int, int> ans;
    ans.first = minValue;
    ans.second = maxValue;
    return ans;
}

bool nodeExist(BinarytreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return 0;
    }
    bool leftAns = nodeExist(root->left, k);
    bool rightAns = nodeExist(root->right, k);
    bool rootAns = k == root->data;
    return (leftAns or rightAns or rootAns);
}
int sumOfBinaryTree(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = sumOfBinaryTree(root->left);
    int rightSum = sumOfBinaryTree(root->right);
    return leftSum + rightSum + root->data;
}
bool isBalanced(BinarytreeNode<int> *root)
{

    if (root == NULL)
    {
        return 1;
    }
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if (abs(leftHeight - rightHeight) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

BinarytreeNode<int> *removeLeafNodes(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL and root->right == NULL)
    {
        delete root;
        return NULL;
    }
    BinarytreeNode<int> *leftChild = removeLeafNodes(root->left);
    BinarytreeNode<int> *rightChild = removeLeafNodes(root->right);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
void levelWisePrintNewLine(BinarytreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinarytreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        BinarytreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front == NULL)
        {

            cout << endl;
            pendingNodes.push(NULL);
        }
        else
        {

            if (front->left != NULL)
            {
                pendingNodes.push(front->left);
            }
            // cout << front->data << " ";
            if (front->right != NULL)
            {
                pendingNodes.push(front->right);
            }

            cout << front->data << " ";
        }
    }
}
void printLevelK(BinarytreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
    }
    printLevelK(root->left, k - 1);
    printLevelK(root->right, k - 1);
}

void printZigZac(BinarytreeNode<int> *root)
{
    queue<BinarytreeNode<int> *> q;
    q.push(root);
    q.push(nullptr);
    int level = 1;
    vector<int> ans;
    while (!q.empty())
    {
        BinarytreeNode<int> *current = q.front();
        q.pop();
        if (current)
        {
            ans.push_back(current->data);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        else
        {
            if (!q.empty())
            {
                if (level % 2 == 0)
                {
                    int n = ans.size();
                    for (int i = n - 1; i >= 0; i--)
                    {
                        cout << ans.at(i) << " ";
                    }
                    ans.clear();
                }
                else
                {
                    for (auto i : ans)
                    {
                        cout << i << " ";
                    }
                    ans.clear();
                }
                q.push(nullptr);
                level++;
                cout << endl;
            }
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
bool isMirror(BinarytreeNode<int> *a, BinarytreeNode<int> *b)
{

    /*
                    
                    2               2
                   / \             / \
                  3  4             4  3
    
    */

    if (a == nullptr and b == nullptr)
    {
        return true;
    }
    //if either one of the root is missing
    if (a == nullptr or b == nullptr)
        return false;

    return (a->data == b->data and isMirror(a->left, b->right) and isMirror(a->right, b->left));
}
bool checkIfTheTreeIsMirrorIsSymmetric(BinarytreeNode<int> *root)
{
    /*
                      1
                     / \
                    2   2
                   / \ / \
                  3  4 4  3
    
    */
    return isMirror(root->left, root->right);
}

pair<Node *, Node *> bst_to_sortedLinkList(BinarytreeNode<int> *root)
{
    if (root == nullptr)
    {
        return make_pair(nullptr, nullptr);
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        Node *head = new Node(root->data);
        return make_pair(head, head);
    }
    Node *middle = new Node(root->data);
    //head   tail
    pair<Node *, Node *> left = bst_to_sortedLinkList(root->left);
    pair<Node *, Node *> right = bst_to_sortedLinkList(root->right);
    Node *tail = nullptr;
    Node *head = nullptr;
    if (left.second != nullptr)
    {
        left.second->next = middle;
        middle->next = right.first;
        head = left.first;
        tail = right.second;
    }
    else
    {
        middle->next = right.first;
        head = middle;
        tail = right.second;
    }
    return (make_pair(head, tail));
}
/*
 Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right 
  child pointer points to the next node in the list and the left child 
  pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 
*/
pair<BinarytreeNode<int> *, BinarytreeNode<int> *> fun(BinarytreeNode<int> *root)
{

    if (root == nullptr)
    {
        return make_pair(nullptr, nullptr);
    }
    if (root->left == nullptr and root->right == nullptr)
    {
        return make_pair(root, root);
    }

    pair<BinarytreeNode<int> *, BinarytreeNode<int> *> left = fun(root->left);
    pair<BinarytreeNode<int> *, BinarytreeNode<int> *> right = fun(root->right);

    BinarytreeNode<int> *head = nullptr;
    BinarytreeNode<int> *tail = nullptr;

    if (left.second != nullptr)
    {
        left.second->right = right.first;
        root->right = left.first;
        root->left = nullptr;
        head = root;
        //this step is important if we dont check for right.second
        //we may assign null to tail but that may not be the case
        //[1,2,null,3] dry run for this case
        if (right.second != nullptr)
        {
            tail = right.second;
        }
        else
        {
            tail = left.second;
        }
    }
    else
    {

        root->right = right.first;
        head = root;
        tail = right.second;
    }

    return make_pair(head, tail);
}

vector<int> *rootToNodePath(BinarytreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == k)
    {
        vector<int> *ans = new vector<int>;
        ans->push_back(root->data);
        return ans;
    }
    vector<int> *left = rootToNodePath(root->left, k);
    vector<int> *right = rootToNodePath(root->right, k);
    if (left != nullptr)
    {
        left->push_back(root->data);
        return left;
    }
    if (right != nullptr)
    {
        right->push_back(root->data);
        return right;
    }
    return nullptr;
}
//1 2 3 4 5 -1 -1 -1 -1 6 7 8 -1 -1 -1 -1 -1
//pre-order  1 2 4 5 6 8 7 3
//inOrder    4 2 8 6 5 7 1 3
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// left centric binary tree 1 2 3 4 5 -1 -1 6 -1 -1 7 -1 -1 -1 -1
//5 6 10 2 3 -1 -1 -1 -1 -1  9 -1 -1
//8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
//10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
//bst 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
int main()
{
    // BinarytreeNode<int> *root = new BinarytreeNode<int>(1);
    // BinarytreeNode<int> *left = new BinarytreeNode<int>(2);
    // BinarytreeNode<int> *right = new BinarytreeNode<int>(3);
    // root->left = left;
    // root->right = right;
    // printBinaryTreeLevelWise(root);
    // preOrderTraversal(root);
    // cout << endl;
    // inOrderTraversal(root);

    // cout << countNodes(root);
    // cout << findHeight(root);
    // cout << exist(root, 11) << endl;
    // cout << findHeightOfElement(root, 7) << endl;
    // mirrorRecursively(root);
    // printBinaryTreeLevelWise(root);
    // int pre[] ={1,2,4,5,3,6,8,9,7};
    // int in[] = {4,2,5,1,8,6,9,3,7};
    // BinarytreeNode<int> *root = buildTree(in, pre, 9);
    BinarytreeNode<int> *root = takeInputLeveWise();
    // printBinaryTreeLevelWise(root);
    printBinaryTreeLevelWise(root);
    cout << endl;
    // pair<int, int> hd;
    // hd = findMinMax(root);
    // cout << "Min " << hd.first << endl;
    // cout << "Max " << hd.second << endl;
    // cout << "print at level" << endl;
    // printLevelK(root, 2);
    printZigZac(root);

   /* pair<Node *, Node *> ht = bst_to_sortedLinkList(root);
    Node *temp = ht.first;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
  */
 
    return 0;
}