#include <iostream>
using namespace std;
#include <queue>
#include <vector>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    //vector to stroe ans
    vector<vector<int>> ans;
    while (!pendingNodes.empty())
    {
        vector<int>smallAns;
        TreeNode *front = pendingNodes.front();
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
                pendingNodes.push(NULL);
            }
        }
        else{
            smallAns.push_back(front->val);
            if(front->left!=NULL){
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                pendingNodes.push(front->right);
            }
        }

    }
}
vector<vector<int>>levelOrder
int main()
{
}
