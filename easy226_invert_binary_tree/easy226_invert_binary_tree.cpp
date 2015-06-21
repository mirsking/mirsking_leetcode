#include <iostream>
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
    TreeNode* invertTree(TreeNode* root) {
		if (root == NULL)
			return NULL;

		TreeNode* left = root->left;
		root->left = root->right;
		root->right = left;

		invertTree(root->left);
		invertTree(root->right);

		return root;
    }
};

int main()
{
	TreeNode a(4), b(2), c(7), d(1), e(3), f(6), g(9);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; //c.right = &g;
	Solution sol;
	TreeNode* tr = sol.invertTree(&a);
	return 0;
}