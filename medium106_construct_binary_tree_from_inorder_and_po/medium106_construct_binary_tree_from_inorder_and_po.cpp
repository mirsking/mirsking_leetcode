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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(begin(inorder), end(inorder), begin(postorder), end(postorder));
    }
private:
	template<typename BidiIt>
	TreeNode* buildTree(BidiIt in_first, BidiIt in_last, BidiIt post_first, BidiIt post_last)
	{
		if (in_first == in_last)
			return nullptr;
		if (post_first == post_last)
			return nullptr;

		const auto val = *prev(post_last);
		TreeNode* root = new TreeNode(val);

		auto in_root_pos = find(in_first, in_last, val);
		auto left_size = distance(in_first, in_root_pos);
		auto post_left_last = next(post_first, left_size);

		root->left = buildTree(in_first, in_root_pos, post_first, post_left_last);
		root->right = buildTree(next(in_root_pos), in_last, post_left_last, prev(post_last));

		return root;
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
/*postorder traversal */
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
	a.left = &b; //a.right = &c;
	//b.left = &d; b.right = &e;
	//c.left = &f;

	Solution sol;
	vector<int> inorder = sol.inorderTraversal(&a);
	vector<int> postorder = sol.postorderTraversal(&a);
	TreeNode* node = sol.buildTree(inorder, postorder);

	return 0;
}