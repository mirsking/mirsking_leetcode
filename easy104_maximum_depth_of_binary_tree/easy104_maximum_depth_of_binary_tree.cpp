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
    int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;

		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);

		return (left_depth > right_depth) ? left_depth + 1 : right_depth + 1;
    }
};


int main(int argc, char** argv)
{

	TreeNode a(1), b(2),c(2),d(3),e(3),f(4),g(4);

	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	d.left = &f;
	d.right = &g;

	Solution sol;

	cout << sol.maxDepth(&a);
	return 0;
}