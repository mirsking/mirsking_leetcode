#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		vector< vector<int> > dp(nums.size());
		int max = -INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			dp[i].resize(nums.size() - i);
			for (int j = 0; j < nums.size()-i; j++)
			{
				if (i == 0 && j == 0)
					dp[i][j] = nums[i];

				if (i!=0)
					dp[i][j] = dp[i - 1][j+1] - nums[i - 1];
				else if (j != 0)
					dp[i][j] = dp[i][i+j-1] + nums[i + j];
				if (max < dp[i][j])
					max = dp[i][j];
			}
		}
		return max;
    }

};

int main()
{
	int a[] = {-2, 1, -3, 4, -1, 2, 2, -5, 4 };
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.maxSubArray(b);
	return 0;
}