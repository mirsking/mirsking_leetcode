#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> tmp(nums1);
		int left_min = 0, left_max = m;
		int right_min = 0, right_max = n;

		int next = 0;
		while (left_min < left_max && right_min < right_max)
		{
			nums1[next++] = tmp[left_min] < nums2[right_min] ? tmp[left_min++] : nums2[right_min++];
		}
		while (left_min < left_max)
			nums1[next++] = tmp[left_min++];
		while (right_min < right_max)
			nums1[next++] = nums2[right_min++];
    }
};

int main()
{
	int a[] = {1,3,4,8,10};
	int b[] = {2,3,5,7,9,11};
	vector<int> nums1(a, a + sizeof(a) / sizeof(int));
	vector<int> nums2(b, b + sizeof(b) / sizeof(int));
	int m = nums1.size(), n = nums2.size();
	nums1.resize(nums1.size() + nums2.size());
	Solution sol;
	sol.merge(nums1, m, nums2, n);

	return 0;
}