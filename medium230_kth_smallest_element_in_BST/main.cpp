#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        midTravesal(root, res);
        return res[k-1];
    }
private:
    void midTravesal(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return;
        midTravesal(root->left, res);
        res.push_back(root->val);
        midTravesal(root->right, res);
    }
};


int main()
{
    TreeNode a(2), b(1), c(3), d(4);
    a.left = &b;
    a.right = &c;
    c.right = &d;
    Solution sol;
    cout << sol.kthSmallest(&a, 4) << endl;
    return 0;
}
