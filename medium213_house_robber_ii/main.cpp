#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
		int n = nums.size();
		switch (n)
		{
		case 0: return 0;
		case 1: return nums[0];
		case 2: return max(nums[0], nums[1]);
		}

		return max(robSum(nums, 0, n - 1), robSum(nums, 1, n));
    }
private:
	int robSum(vector<int>& nums, int s, int e)
	{
		int n = e - s;
		vector<int> dp(n, 0);
		dp[0] = nums[s];
		dp[1] = max(nums[s], nums[s + 1]);

		for (int i = 2; i < n; i++)
		{
			dp[i] = max(dp[i - 2] + nums[s+i], dp[i - 1]);
		}
		return dp[n - 1];
	}
	
};

int main()
{
	vector<int> input = {1,4,3,4};
	Solution sol;
	cout << sol.rob(input) << endl;
	return 0;
}