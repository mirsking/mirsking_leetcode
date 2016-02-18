#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> ret;
		if (!root)
			return ret;
		vector<int> cur;
		vector<vector<int>> res;
		binaryTreePaths(root, cur, res);

		for (int i = 0; i < res.size(); i++)
		{
			string tmp;
			for (int j = 0; j < res[i].size(); j++)
			{
				tmp += to_string(res[i][j]);
				if (j != res[i].size() - 1)
					tmp += "->";
			}
			ret.push_back(tmp);
		}
		return ret;
    }
private:
	void binaryTreePaths(TreeNode* root, vector<int>& cur, vector<vector<int>>& res)
	{
		cur.push_back(root->val);
		if (!root->left && !root->right)
		{
			res.push_back(cur);
			return;
		}
		
		if (root->left)
		{
			int n = cur.size();
			binaryTreePaths(root->left, cur, res);
			cur.resize(n);
		}
		if (root->right)
		{
			int n = cur.size();
			binaryTreePaths(root->right, cur, res);
			cur.resize(n);
		}
		cur.pop_back();
	}
};

int main()
{
	TreeNode a(1), b(2), c(3), d(5);
	a.left = &b; a.right = &c;
	b.right = &d;
	Solution sol;
	auto res = sol.binaryTreePaths(&a);
	for (auto& s : res)
	{
		cout << s << endl;
	}

	return 0;
}
