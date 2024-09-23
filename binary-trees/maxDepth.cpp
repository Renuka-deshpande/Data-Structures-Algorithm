#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data1)
    {
        data = data1;
        left = nullptr;
        right = nullptr;
    }
};
class solution
{
public:
    int Max_depth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_height = Max_depth(root->left);
        int right_height = Max_depth(root->right);
        return 1 + max(left_height, right_height);
    }
};
int main(){
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(5);
    root->right->left->left=new TreeNode(6);

    solution obj;
    cout<<"Maximum depth of tree is: "<<obj.Max_depth(root);

}