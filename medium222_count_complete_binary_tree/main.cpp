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
	//http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
public:
    int countNodes(TreeNode* root) {
		int depth = 0;
		TreeNode *node = root;
		while (node)
		{
			depth++;
			node = node->left;
		}
		if (depth == 0)
			return 0;

		int left = 0; int right = (1 << (depth - 1)) - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (getNode(root, mid, depth - 1))
				left = mid + 1;
			else
				right = mid - 1;
		}

		return (1 << (depth - 1)) + right;
    }
private:
	TreeNode* getNode(TreeNode* root, int path, int depth)
	{
		while (depth-- && root)
		{
			if (path & (1 << depth))
				root = root->right;
			else
				root = root->left;
		}
		return root;
	}

};

int main()
{
	TreeNode a(1), b(2), c(3), d(4);
	a.left = &b; a.right = &c;
	b.left = &d;
	Solution sol;
	cout << sol.countNodes(NULL);
	return 0;
}