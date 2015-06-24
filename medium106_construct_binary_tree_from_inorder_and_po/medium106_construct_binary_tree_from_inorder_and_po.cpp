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
};

int main()
{
	int a[] = { 2, 1, 3};
	int b[] = { 2, 3, 1};
	vector<int> inorder(a, a + sizeof(int));
	vector<int> postorder(b, b + sizeof(int));
	Solution sol;
	TreeNode* node = sol.buildTree(inorder, postorder);

	return 0;
}