#include "D:\dataStructure\binaryTree\BinarytreeNode.h"
class Bst
{
private:
    BinarytreeNode<int> *root;

    bool hasData(BinarytreeNode<int> *root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data < root->data)
        {
            return hasData(root->left, data);
        }
        else
        {
            return hasData(root->right, data);
        }
    }
    BinarytreeNode<int> *insertData(BinarytreeNode<int> *root, int data)
    {
        if (root == nullptr)
        {
            BinarytreeNode<int> *newNode = new BinarytreeNode<int>(data);
            return newNode;
        }
        if (data < root->data)
        {
            root->left = insertData(root->left, data);
        }
        else
        {
            root->right = insertData(root->right, data);
        }
        return root;
    }
    BinarytreeNode<int> *deleteData(BinarytreeNode<int> *root, int data)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (data < root->data)
        {
            root->left = deleteData(root->left, data);
            return root;
        }
        else if (data > root->data)
        {
            root->right = deleteData(root->right, data);
            return root;
        }
        else
        {
            if (root->left == nullptr and root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            if (root->right == nullptr)
            {
                BinarytreeNode<int> *temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }
            if (root->left == nullptr)
            {
                BinarytreeNode<int> *temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            }
            else
            {
                //find the smallest element from the right tree
                //for the replacement of root or gretest from left tree
                BinarytreeNode<int> *temp = root->right;
                while (temp->left != nullptr)
                {
                    temp = temp->left;
                }
                //effectively temp is pointing towards the leftmost leaft of right tree
                root->data = temp->data;
                root->right = deleteData(root->right, temp->data);
                return root;
            }
        }
    }

    void printBinaryTreeLevelWise(BinarytreeNode<int> *root)
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
            cout << front->data << " : ";
            if (front->left != nullptr)
            {
                cout << " L " << front->left->data;
                pendingNodes.push(front->left);
            }
            if (front->right != nullptr)
            {
                cout << " R " << front->right->data;
                pendingNodes.push(front->right);
            }
            cout << endl;
        }
    }

public:
    Bst()
    {
        root = nullptr;
    }

    ~Bst()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(root, data);
    }

    void insertData(int data)
    {
        root = insertData(root, data);
    }

    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void printTree()
    {
        return printBinaryTreeLevelWise(root);
    }
};
