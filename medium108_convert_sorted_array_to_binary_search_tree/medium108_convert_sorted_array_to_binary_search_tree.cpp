#include <iostream>
#include <vector>
#include <memory>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		else
		{
			TreeNode *node = sortedArrayToBST(nums, 0, nums.size()-1);
			return node;
		}
    }

private:
	TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end)
	{
		if (end < begin)
			return NULL;

		int media = (begin + end) / 2;
		TreeNode* node = new TreeNode(nums[media]);

		node->left = sortedArrayToBST(nums, begin, media-1);
		node->right = sortedArrayToBST(nums, media + 1, end);

		return node;
	}
};

int main(int argc, char** argv)
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	TreeNode* node =  sol.sortedArrayToBST(b);
	return 0;
}