#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		queue<TreeNode*> que;
		que.push(root);
		levelOrderTravesal(que, res);
		return res;
    }
private:
	void levelOrderTravesal(queue<TreeNode*> que, vector<int>& res)
	{
		queue<TreeNode*> que2;
		if (que.empty())
			return;
		else
			res.push_back(que.front()->val);

		while (!que.empty())
		{
			TreeNode* node = que.front();
			que.pop();
			if (node->right)
				que2.push(node->right);
			if (node->left)
				que2.push(node->left);
		}

		levelOrderTravesal(que2, res);
	}
};

int main()
{
	TreeNode a(1), b(2), c(3), d(4), e(5);
	a.left = &b; a.right = &c;
	b.right = &e; c.right = &d;
	Solution sol;
	vector<int> res = sol.rightSideView(&b);
	for (auto& v : res)
		cout << v << endl;
	return 0;
}