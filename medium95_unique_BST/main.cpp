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
    vector<TreeNode*> generateTrees(int n) {
		if (n == 0)
			return vector<TreeNode*>();
		return generate(1, n);
    }
private:
	vector<TreeNode*> generate(int start, int end)
	{
		vector<TreeNode*> sub_trees;
		if (start > end)
		{
			sub_trees.push_back(nullptr);
			return sub_trees;
		}

		for (int k = start; k <= end; k++)
		{
			vector<TreeNode*> left_sub_trees = generate(start, k-1);
			vector<TreeNode*> right_sub_trees = generate(k + 1, end);
			for (auto i : left_sub_trees)
			{
				for (auto j : right_sub_trees)
				{
					TreeNode *node = new TreeNode(k);
					node->left = i;
					node->right = j;
					sub_trees.push_back(node);
				}
			}
		}
		return sub_trees;
	}
};

	
int main()
{
	Solution sol;
	vector<TreeNode*> res = sol.generateTrees(3);
	return 0;
}