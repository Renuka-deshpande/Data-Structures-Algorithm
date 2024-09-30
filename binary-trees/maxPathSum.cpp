#include<iostream>
#include <climits> // Include to use INT_MIN
using namespace std;
struct treenode{
    public:
    int data;
    treenode*right;
    treenode*left;
    treenode(int data1){
        data=data1;
        right=nullptr;
        left=nullptr;
    }
};
class solution{
    public:
    int maxpathsum(treenode*root){
        int maxi=INT_MIN;
        maxpathdown(root,maxi);
        return maxi;
    }
    int maxpathdown(treenode*node,int& maxi){
        if(node==nullptr){
            return 0;
        }
        int leftsum=max(0,maxpathdown(node->left,maxi));
        int rightsum=max(0,maxpathdown(node->right,maxi));
        maxi=max(maxi,leftsum+rightsum+node->data);
        return (node->data)+max(leftsum,rightsum);
    }

};
int main(){
     treenode* root = new treenode(3);
    root->left = new treenode(9);
    root->right = new treenode(1);
    root->right->left = new treenode(10);
    root->right->right = new treenode(7);

    solution obj;
    int res=obj.maxpathsum(root);
    cout<<res;
}