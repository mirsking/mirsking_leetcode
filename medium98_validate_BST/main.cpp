#include <iostream>
#include <limits>
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
    bool isValidBST(TreeNode* root) {
		return isValidBST(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());
    }
private:
	bool isValidBST(TreeNode* root, long long min, long long max)
	{
		if (!root)
			return true;
		return root->val > min && root->val < max
			&& isValidBST(root->left, min, root->val)
			&& isValidBST(root->right, root->val, max);
	}
};
int main()
{
	TreeNode a(1), b(2), c(3);
	//a.right = &b; b.right = &c;
	a.left = &b; b.right = &c;
	Solution sol;
	cout << (sol.isValidBST(&a) ? "True" : "False") << endl;
	return 0;
}