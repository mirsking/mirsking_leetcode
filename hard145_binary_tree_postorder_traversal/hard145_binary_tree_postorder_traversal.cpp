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
    vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		postorderTraversal(root, res);
		return res;
    }
private:
	void postorderTraversal(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
			return;

		postorderTraversal(root->left, res);
		postorderTraversal(root->right, res);
		res.push_back(root->val);
	}
};

int main()
{
	TreeNode a(1), b(2), c(3), d(4), e(5), f(6), g(7);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f;
	Solution sol;
	vector<int> res = sol.postorderTraversal(&a);
	return 0;
}