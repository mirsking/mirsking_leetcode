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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(begin(preorder), end(preorder), begin(inorder), end(inorder));
    }
private:
	template<typename BidiIt>
	TreeNode* buildTree(BidiIt pre_first, BidiIt pre_last, BidiIt in_first, BidiIt in_last)
	{
		if (pre_first == pre_last)
			return nullptr;
		if (in_first == in_last)
			return nullptr;

		const auto val = *pre_first;
		TreeNode* root = new TreeNode(val);

		auto in_root_pos = find(in_first, in_last, val);
		// left subtree in_first, in_robot_pos
		// right subtree in_robot_pos, in_end
		auto left_size = distance(in_first, in_root_pos);
		auto pre_left_last = next(pre_first, left_size+1);

		root->left = buildTree(next(pre_first), pre_left_last, in_first, in_root_pos);
		root->right = buildTree(pre_left_last, pre_last, next(in_root_pos), in_last);

		return root;
	}

/* preorder traversal*/
public:
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderTraversal(root, res);
		return res;
    }

private:
	void preorderTraversal(TreeNode* root, vector<int>& res)
	{
		if (root == NULL)
			return;

		res.push_back(root->val);
		preorderTraversal(root->left, res);
		preorderTraversal(root->right, res);
	}

/* inorder traversal*/
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
	vector<int> preorder = sol.preorderTraversal(&a);
	vector<int> inorder = sol.inorderTraversal(&a);
	TreeNode* node = sol.buildTree(preorder, inorder);

	return 0;
}