#include <iostream>
#include <algorithm>
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
    int minDepth(TreeNode* root) {
		return minDepth(root, false);
    }

private:
	int minDepth(const TreeNode* root, bool has_brother)
	{
		if (!root)
			return has_brother ? INT_MAX : 0;

		return min(minDepth(root->left, root->right != NULL),
			minDepth(root->right, root->left != NULL)) + 1;
	}
};



int main(int argc, char** argv)
{

	TreeNode a(1), b(2), c(2), d(3), e(3), f(4), g(4);

	a.left = &b;
	//a.right = &c;
	//b.left = &d;
	//b.right = &e;
	//d.left = &f;
	//d.right = &g;

	Solution sol;

	cout << sol.minDepth(&a);
	return 0;
}