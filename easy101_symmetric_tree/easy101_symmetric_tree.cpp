#include <iostream>
using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root == NULL)
			return true;

		return isSymmetric(root->left, root->right);
    }

private:
	bool isSymmetric(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL || right==NULL)
			return false;

		if (left->val == right->val)
			return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
		else
			return false;

	}

};


int main(int argc, char** argv)
{
	TreeNode a(1), b(2), c(2), d(3), e(4), f(4), g(3);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; c.right = &g;

	Solution sol;
	cout << sol.isSymmetric(&b);
	return 0;
}