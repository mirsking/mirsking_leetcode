#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	//dp[x][y] = min(dp[x - 1][y - 1], dp[x][y - 1], dp[x - 1][y]) + 1
	//dp[x][y]表示以坐标(x, y)为右下角元素的全1正方形矩阵的最大长度（宽度）
    int maximalSquare(vector<vector<char>>& matrix) {
		int n = matrix.size(); 
		if (n == 0) return 0;
		int m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m,0));

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			dp[i][0] = matrix[i][0] - '0';
			if (dp[i][0] == 1)
				res = 1;
		}
		for (int j = 0; j < m; j++)
		{
			dp[0][j] = matrix[0][j] - '0';
			if (dp[0][j] == 1)
				res = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
    }
};

int main()
{
	vector<vector<char>> input(4, vector<char>(5, '1'));
	input[0][1] = '0';
	input[1][1] = '0';
	input[3][1] = '0';
	input[3][2] = '0';
	input[0][3] = '0';
	input[0][4] = '0';
	input[3][4] = '0';
	Solution sol;
	cout << sol.maximalSquare(input) << endl;
	return 0;
}