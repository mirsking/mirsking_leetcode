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
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorderTraversal(root, res);
		return res;
    }
private:
	void inorderTraversal(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
			return;
		inorderTraversal(root->left, res);
		res.push_back(root->val);
		inorderTraversal(root->right, res);
	}
};



int main()
{
	TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(7);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f;
	Solution sol;
	vector<int> res = sol.inorderTraversal(&a);
	return 0;
}