#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
		initNexts(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return current_index_ < nexts_.size();
    }

    /** @return the next smallest number */
    int next() {
		return nexts_[current_index_++];
    }
private:
	void initNexts(TreeNode* root)
	{
		MidTravesal(root, nexts_);
		current_index_ = 0;
	}

	void MidTravesal(TreeNode* root, vector<int>& res)
	{
		if (!root)
			return;
		MidTravesal(root->left, res);
		res.push_back(root->val);
		MidTravesal(root->right, res);
	}
private:
	vector<int> nexts_;
	int current_index_;

};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
	TreeNode a(5), b(3), c(7), d(1), e(4), f(6), g(8);
	a.left = &b; a.right = &c;
	b.left = &d; b.right = &e;
	c.left = &f; c.right = &g;
	BSTIterator i = BSTIterator(&a);
	while (i.hasNext())
		cout << i.next() << endl;
	return 0;
}