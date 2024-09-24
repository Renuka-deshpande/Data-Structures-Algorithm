#include <iostream>
using namespace std;
struct TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data1)
    {
        data = data1;
        right = nullptr;
        left = nullptr;
    }
};
class solution{
    public:
    int check(TreeNode* node){
        if(node==nullptr){return 0;}
        int left_height=check(node->left);
        int right_height=check(node->right);

        if(left_height==-1 && right_height==-1){return -1;}
        if(abs(left_height-right_height)>1){return -1;}

        return max(left_height,right_height)+1;
    }
};
int main(){
    //TREE-1
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(1);
    root->right->left= new TreeNode(10);
    root->right->right=  new TreeNode(7);

    //TREE2
    TreeNode* root2=new TreeNode(1);
    root2->left=new TreeNode(3);
    root2->right=new TreeNode(2);
    root2->left->left= new TreeNode(5);
    root2->left->right=  new TreeNode(4);
    root2->left->left->left= new TreeNode(7);
    root2->left->left->right= new TreeNode(6);
    

    solution obj;
    int result=obj.check(root);
    if(result!=-1){
        cout<<"The Binary Tree is Balanced and it's height is: "<<result;
    }
    else{
        cout<<"The Binary Tree is not balanced ";
    }
}