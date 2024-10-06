#include<bits/stdc++.h>
using namespace std;

struct treenode
{
public:
    int data;
    treenode *right;
    treenode *left;
    treenode(int data1)
    {
        data = data1;
        right = nullptr;
        left = nullptr;
    }
};

class solution
{
    public:
    bool isleaf(treenode*root){
        if((root->left==nullptr)&&(root->right==nullptr)){
        return true;}
        return false;
    }
    void leftboundary(treenode*root,vector<int>&res){
        treenode*cur=root->left;
        while(cur){
            if(!isleaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left){cur=cur->left;}
            else{cur=cur->right;}
        }
    }
    void rightboundary(treenode*root,vector<int>&res){
        treenode*cur=root->right;
        vector<int>temp;
        while(cur){
            if(!isleaf(cur)){temp.push_back(cur->data);}
            if(cur->right){cur=cur->right;}
            else{cur=cur->left;}
        }
        for(int i=temp.size()-1;i>=0;--i){
            res.push_back(temp[i]);
        }
    }
    void addleaf(treenode*root,vector<int>&res){
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)addleaf(root->left,res);
        if(root->right)addleaf(root->right,res);
    }
    public:
    vector<int>printboundary(treenode*root){
    vector<int>res;
    if(!root)return res;
    if(!isleaf(root)){res.push_back(root->data);}
    leftboundary(root,res);
    addleaf(root,res);
    rightboundary(root,res);
    return res;}
    public:
    void print(const vector<int>&result){
    for(int val:result){
        cout<<val<<" ";
    }
}
};
int main(){
     treenode* root = new treenode(1);
    root->left = new treenode(2);
    root->right = new treenode(3);
    root->left->left = new treenode(4);
    root->left->right = new treenode(5);
    root->right->left = new treenode(6);
    root->right->right = new treenode(7);

    solution obj;
    vector<int>result=obj.printboundary(root);
    obj.print(result);

    return 0;
}