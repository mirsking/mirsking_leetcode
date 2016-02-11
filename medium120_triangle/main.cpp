#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty())
			return 0;
		int n = triangle.size();
		vector<vector<int>> dp(n);
		for (int i = 0; i < n; i++)
			dp[i].resize(triangle[i].size());
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; i++)
		{
			const int m = triangle[i].size();
			for (int j = 0; j < m; j++)
			{
				if (j == 0) //up right
				{
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				}
				else if (j == m - 1)//up left
				{
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				}
				else // up left right
				{
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
				}
			}
		}

		int min_path = INT_MAX;
		for (int i = 0; i < dp[n - 1].size(); i++)
		{
			if (dp[n - 1][i] < min_path)
				min_path = dp[n - 1][i];
		}
		return min_path;
    }
};

int main()
{
	vector<vector<int>> input(4);
	input[0] = {2};
	input[1] = {3,4};
	input[2] = {6,5,7};
	input[3] = {4,1,8,3};
	Solution sol;
	cout << sol.minimumTotal(input) << endl;
	return 0;
}