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
    void flatten(TreeNode* root) {
		if (root == NULL)
			return;

		preOrderTraversal(root);
		TreeNode* tmp = root;
		for (auto iter = vec.begin()+1; iter != vec.end();iter++)
		{
			root->left = NULL;
			root->right = *iter;
			root = root->right;
		}
		root = tmp;
    }

private:
	void preOrderTraversal(TreeNode* root)
	{
		if (root == NULL)
			return;

		vec.push_back(root);
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
	vector<TreeNode*> vec;

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
	sol.flatten(NULL);

	return 0;
	
}