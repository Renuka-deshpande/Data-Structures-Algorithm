#include <iostream>
using namespace std;

struct TreeNode {
public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data1) {
        data = data1;
        right = nullptr;
        left = nullptr;
    }
};

class solution {
public:
    int FindDiameter(TreeNode* node, int &maxi) {
        if (node == nullptr) {
            return 0;
        }
        int lh = FindDiameter(node->left, maxi);
        int rh = FindDiameter(node->right, maxi);
        
        maxi = max(maxi, lh + rh); // Update maxi to store the maximum diameter found

        return 1 + max(lh, rh);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(7);

    solution obj;
    int maxi = 0;
    obj.FindDiameter(root, maxi);
    cout << "Diameter of the tree: " << maxi << endl;

    return 0;
}
