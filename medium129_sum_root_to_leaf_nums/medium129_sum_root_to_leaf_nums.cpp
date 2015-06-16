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

    int sumNumbers(TreeNode* root) {
		rootLeafSum(root);

		int sum = 0;
		for (auto& a : sums)
			sum += a;
		return sum;
    }
	
private:
	void rootLeafSum(TreeNode* root)
	{
		if (root == NULL)
			return;

		if (root->left == NULL && root->right == NULL)
			sums.push_back(root->val);

		if (root->left != NULL)
			root->left->val += ((root->val)*10);
		if (root->right != NULL)
			root->right->val += ((root->val)*10);

		rootLeafSum(root->left);
		rootLeafSum(root->right);
	}

	vector<int> sums;

};


int main(int argc, char** argv)
{

	TreeNode a(5), b(4), c(8), d(1), e(13), f(4), g(7), h(2), i(1);
	a.left = &b; a.right = &c;
	b.left = &d;
	//c.left = &e;
	//c.right = &f;
	//d.left = &g;
	//d.right = &h;
	//f.right = &i;

	Solution sol;
	cout << sol.sumNumbers(&a);
	return 0;
}