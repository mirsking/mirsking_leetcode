#include<iostream>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL)
			return res;
		queue<TreeNode> que;
		que.push(*root);
		levelOrder(que, res);
		return res;
    }
private:
	void levelOrder(queue<TreeNode> que, vector<vector<int> >& res)
	{
		if (que.empty())
			return;

		vector<int> tmp;
		queue<TreeNode> que2;
		while (!que.empty())
		{
			TreeNode node = que.front();
			tmp.push_back(node.val);
			if (node.left!=NULL)
				que2.push(*(node.left));
			if (node.right!=NULL)
				que2.push(*(node.right));
			que.pop();
		}
		res.push_back(tmp);
		levelOrder(que2, res);
	}
};

int main()
{
	TreeNode a(3), b(9), c(20), d(15), e(7);
	a.left = &b; a.right = &c;
	c.left = &d; c.right = &e;
	Solution sol;
	vector<vector<int>> res = sol.levelOrder(&a);
	return 0;
}