#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	//如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x=a+bｘb，
	//那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。
    int numSquares(int n) {
		vector<long long> dp(n + 1, INT_MAX);
		for (int i = 0; i*i <= n; i++)
			dp[i*i] = 1;

		for (long long a = 0; a <= n; a++)
		{
			for (long long b = 0; a + b*b <= n; b++)
			{
				dp[a + b*b] = min(dp[a] + 1, dp[a + b*b]);
			}
		}
		return dp[n];
    }
};

int main()
{
	Solution sol;
	cout << sol.numSquares(10) << endl;
	return 0;
}