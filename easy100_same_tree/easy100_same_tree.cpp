#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)
			return true;
		else if (p == NULL)
			return false;
		else if (q == NULL)
			return false;

		if (p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
    }
};


int main(int argc, char** argv)
{
	TreeNode a(1), b(2), c(3), d(5);
	a.left = &b;
	a.right = &c;
	b.left = &d;


	Solution sol;
	cout << sol.isSameTree(&a, &b);
	return 0;

}