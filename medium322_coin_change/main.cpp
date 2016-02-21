#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	//https://www.hrwhisper.me/leetcode-coin-change/
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX-1);
		dp[0] = 0;
		for (int i = 0; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i + coins[j] <= amount)
				{
					dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1);
				}
			}
		}
		return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};

int main()
{
	vector<int> coins = {186,419,83,408};
	Solution sol;
	cout << sol.coinChange(coins, 6249) << endl;
	return 0;
}