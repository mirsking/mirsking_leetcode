#include <iostream>
#include <vector>
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
    bool hasPathSum(TreeNode* root, int sum) {
		rootLeafSum(root);
		for (auto& num : sums)
		{
			if (sum == num)
				return true;
		}

		return false;
    }
private:
	void rootLeafSum(TreeNode* root)
	{
		if (root == NULL)
			return;

		if (root->left == NULL && root->right == NULL)
			sums.push_back(root->val);

		if (root->left != NULL)
			root->left->val += root->val;
		if (root->right != NULL)
			root->right->val += root->val;

		rootLeafSum(root->left);
		rootLeafSum(root->right);
	}

	vector<int> sums;

};


int main(int argc, char** argv)
{

	TreeNode a(5), b(4), c(8), d(11), e(13), f(4), g(7), h(2), i(1);
	a.left = &b; a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.right = &i;

	Solution sol;
	cout << sol.hasPathSum(&a,1);
	return 0;
}