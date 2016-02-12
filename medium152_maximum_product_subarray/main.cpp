#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	//http://blog.csdn.net/linhuanmars/article/details/39537283
    int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return 0;

		int max_local = nums[0];
		int min_local = nums[0]; // for negative
		int global = nums[0];

		for (int i = 1; i < n; i++)
		{
			int max_copy = max_local;
			max_local = max(max(max_local*nums[i], nums[i]), min_local*nums[i]);
			min_local = min(min(max_copy*nums[i], nums[i]), min_local*nums[i]);
			global = max(global, max_local);
		}
		return global;
    }
};

int main()
{
	vector<int> input = {-2, -3, 0, -2, -40};
	Solution sol;
	cout << sol.maxProduct(input);
	return 0;
}