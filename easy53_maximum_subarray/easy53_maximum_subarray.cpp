#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size());
        int max = -INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                dp[i] = nums[0];
            else
            {
                if (dp[i - 1]>0)
                    dp[i] = dp[i - 1] + nums[i];
                else
                    dp[i] = nums[i];
            }

            max = max < dp[i] ? dp[i] : max;
        }

        return max;
    }

};

int main()
{
	int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.maxSubArray(b);
	return 0;
}