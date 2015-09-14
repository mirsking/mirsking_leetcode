#include <vector>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
		dp = vector<vector<int>>(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			}
		}
		return dp[m - 1][n - 1];
    }
private:
	vector<vector<int>> dp;
};

int main()
{

	Solution sol;
	int res = sol.uniquePaths(3, 7);
	return 0;
}


