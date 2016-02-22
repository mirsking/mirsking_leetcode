#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n, 0);
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			res = max(res, dfs(nums, i, dp));
		}
		return res;
    }
private:
	int dfs(vector<int>& nums, int cur, vector<int>& dp)
	{
		if (dp[cur])
			return dp[cur];

		for (int i = cur + 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[cur])
				dp[cur] = max(dp[cur], dfs(nums, i, dp));
		}
		return ++dp[cur];
		
	}
};

int main()
{
	vector<int> input = { 10, 9, 2, 5, 3, 7, 101, 18 };
	Solution sol;
	cout << sol.lengthOfLIS(input);
	return 0;
}