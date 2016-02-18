#include <iostream>
#include <vector>
#include <algorithm>
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
	//For BST: a and b's ancestor has: a<= c <= b or a>= c >= b
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *cur = root;
		while (cur)
		{
			if (cur->val > p->val && cur->val > q->val)
				cur = cur->left;
			else if (cur->val < p->val && cur->val < q->val)
				cur = cur->right;
			else
				return cur;
		}
	}

	/*
	// the way for Binary Tree, there are better way for BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q)
			return NULL;

		vector<TreeNode*> path1, path2;
		searchNode(root, p, path1);
		searchNode(root, q, path2);
		int n = min(path1.size(), path2.size());

		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (path1[i] != path2[i])
				break;
			index = i;
		}
		return path1[index];
    }
private:
	bool searchNode(TreeNode* root, TreeNode* p, vector<TreeNode*>& path)
	{
		path.push_back(root);
		if (root == p)
			return true;

		if (root->left)
		{
			if (searchNode(root->left, p, path))
				return true;
			path.pop_back();
		}
		if (root->right)
		{
			if (searchNode(root->right, p, path))
				return true;
			path.pop_back();
		}
		return false;
	}
	*/
};

int main()
{
	TreeNode a(6), b(2), c(8), d(0), e(4), f(7), g(9), h(3), i(5), j(100);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; c.right = &g;
	e.left = &h; e.right = &i;
	Solution sol;
	TreeNode* res = sol.lowestCommonAncestor(&a, &b, &e);
	cout << res->val << endl;
	return 0;
}