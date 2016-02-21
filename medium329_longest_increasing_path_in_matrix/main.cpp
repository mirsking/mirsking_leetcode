#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//https://www.hrwhisper.me/leetcode-longest-increasing-path-matrix/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)return 0;
		int n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				res = max(res, dfs(matrix, i, j, dp));
		}
		return res;
    }
private:
	int dfs(const vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp)
	{
		if (dp[x][y])
			return dp[x][y];

		int m = matrix.size();
		int n = matrix[0].size();
		vector<pair<int, int>> dirs = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		for (auto& p : dirs)
		{
			int nx = x + p.first, ny = y + p.second;
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
				matrix[nx][ny] > matrix[x][y])
				dp[x][y] = max(dp[x][y], dfs(matrix, nx, ny, dp));
		}
		return ++dp[x][y];
	}
};

int main()
{
	vector<vector<int>> input = {
		{ 9, 9, 4 },
		{ 6, 6, 8 },
		{ 2, 1, 1 } };
	Solution sol;
	cout << sol.longestIncreasingPath(input);
	return 0;
}