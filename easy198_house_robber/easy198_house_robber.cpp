#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size());
        int max_cash = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                dp[0] = nums[0];
            else if (i == 1)
                dp[1] = dp[0] < nums[1] ? nums[1] : dp[0];
            else
                dp[i] = max<int>(dp[i - 1], dp[i - 2] + nums[i]);

            max_cash = max_cash < dp[i] ? dp[i] : max_cash;
        }

        return max_cash;
    }


};


int main()
{

    int a[] = {2,1,1,2}; 
    vector<int> b(a, a + sizeof(a) / sizeof(int));
    Solution sol;
    cout << sol.rob(b);
    return 0;
}