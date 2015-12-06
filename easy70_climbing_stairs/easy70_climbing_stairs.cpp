#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		if (n < 1)
			return 0;
		else if (n == 1)
			return 1;

		vector<int> dp(n+1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
    }
};

int main()
{
	Solution sol;
	cout << sol.climbStairs(2) << endl;
	cout << sol.climbStairs(3) << endl;
	cout << sol.climbStairs(4) << endl;
	cout << sol.climbStairs(5) << endl;
	cout << sol.climbStairs(6) << endl;
	return 0;
}