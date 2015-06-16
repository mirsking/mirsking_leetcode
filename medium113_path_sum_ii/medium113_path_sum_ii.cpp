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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int> > return_val;
		vector<int> tmp;
		pathSum(root, sum, tmp, return_val);
		return return_val;
    }
   
private:
	void pathSum(TreeNode* root, int sum, vector<int>& cur, vector<vector<int> >& res)
	{
		if (root == NULL)
			return;

		cur.push_back(root->val);

		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->val)
				res.push_back(cur);
		}

		pathSum(root->left, sum - root->val, cur, res);
		pathSum(root->right, sum - root->val, cur, res);
		
		cur.pop_back();
	}
};


int main(int argc, char** argv)
{
	TreeNode a(5), b(4), c(8), d(11), e(13), f(4), g(7), h(2), i(5);
	a.left = &b; a.right = &c;
	b.left = &d;
	c.left = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	f.right = &i;

	Solution sol;
	vector<vector<int> > v = sol.pathSum(&a, 22);
	return 0;
}