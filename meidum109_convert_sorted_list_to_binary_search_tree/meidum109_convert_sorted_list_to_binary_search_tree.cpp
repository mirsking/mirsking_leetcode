#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
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
    TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (head != NULL)
		{
			nums.push_back(head->val);
			head = head->next;
		}
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
	ListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution sol;
	TreeNode* node = sol.sortedListToBST(&a);
	return 0;
}