#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0) return 0;
		int n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));
		if (obstacleGrid[0][0] == 0)
			dp[0][0] = 1;
		else
			return 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (obstacleGrid[i][j])
					dp[i][j] = 0;
				else
				{
					if (i > 0 && j > 0)
						dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
					else if (i > 0)
						dp[i][j] = dp[i - 1][j];
					else if (j > 0)
						dp[i][j] = dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main()
{
	//vector<vector<int>> input(3, vector<int>(3, 0));
	//input[1][1] = 1;
	vector<vector<int>> input(2, vector<int>(2, 0));
	input[0][1] = 1;
	Solution sol;
	cout << sol.uniquePathsWithObstacles(input) << endl;
	return 0;
}