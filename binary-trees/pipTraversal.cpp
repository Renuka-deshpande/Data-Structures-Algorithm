//all 3 dfs traversal in one 
#include <bits/stdc++.h>
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
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    tuple<vector<int>, vector<int>, vector<int>> preinpostTraversal(TreeNode *root)
    {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;
        if (root == nullptr)
            return make_tuple(pre, in, post);
        ;
        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            if (it.second == 1)
            {
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->left != nullptr)
                {
                    st.push({it.first->left, 1});
                }
            }

            else if (it.second == 2)
            {
                in.push_back(it.first->data);
                it.second++;
                st.push(it);

                if (it.first->right != nullptr)
                {
                    st.push({it.first->right, 1});
                }
            }

            else
            {
                post.push_back(it.first->data);
            }
        }
        return make_tuple(pre, in, post);
    }
};
int main()
{

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(1);

    Solution obj;
    vector<int> pre, in, post;
    tie(pre, in, post) = obj.preinpostTraversal(root);

    cout << "pre-order traversal: " << endl;
    for (int val : pre)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "in-order traversal: " << endl;
    for (int val : in)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << "post-order traversal: " << endl;
    for (int val : post)
    {
        cout << val << " ";
    }
}
