// bfs level wise traversal
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *right, *left;
    Node(int data1)
    {
        data = data1;
        right = left = nullptr;
    }
};

class solution
{
public:
    vector<vector<int>> levelorder(Node *root) 
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->right->left = new Node(1);
    
    solution sol; // Create an object of the solution class
    vector<vector<int>> result = sol.levelorder(root); // Call the levelorder function
    
    cout << "Level-order Traversal: " << endl;
    for (const auto& level : result) // Iterate through the result to print
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
