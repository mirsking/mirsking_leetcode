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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> que;
		if (root)
			que.push(root);
		LevelOrder(que, false, res);
		return res;
    }

private:
	void LevelOrder(queue<TreeNode*>& que, bool reverse, vector<vector<int>>& res)
	{
		if (que.empty())
			return;
		queue<TreeNode*> que2;
		vector<int> cur;
		while (!que.empty())
		{
				TreeNode* node = que.front();
				cur.push_back(node->val);
				if (node->left)
					que2.push(node->left);
				if (node->right)
					que2.push(node->right);
				que.pop();
		}
		if (!reverse)
			res.push_back(cur);
		else
			res.push_back(vector<int>(cur.rbegin(), cur.rend()));
		LevelOrder(que2, !reverse, res);
	}
};

int main()
{
	TreeNode a(3), b(9), c(20), d(15), e(7);
	a.left = &b; a.right = &c;
	c.left = &d; c.right = &e;
	Solution sol;
	vector<vector<int>> res = sol.zigzagLevelOrder(NULL);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}