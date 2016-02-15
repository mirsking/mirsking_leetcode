#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// '1' is land, and '0' is water
	// 对所有的1进行dfs，dfs的过程中将深搜到的1置为非1，这样碰到的1的个数就是岛屿的个数
    int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m == 0)
			return 0;
		n = grid[0].size();
		if (n == 0)
			return 0;

		int res = 0;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == '1')
				{
					res++;
					dfs(grid, i, j);
				}
			}
		}

		return res;

    }
private:
	void dfs(vector<vector<char>> &grid, int i, int j)
	{
		if (i < 0 || i >= m || j < 0 || j >= n)
			return;

		if (grid[i][j] == '1')
		{
			grid[i][j] = '2';
			dfs(grid, i - 1, j);
			dfs(grid, i + 1, j);
			dfs(grid, i, j - 1);
			dfs(grid, i, j + 1);
		}
	}
private:
	int m, n;
};

int main()
{
	//vector<vector<char>> input(4);
	//input[0] = { '1', '1', '1', '1', '0' };
	//input[1] = { '1', '1', '0', '1', '0' };
	//input[2] = { '1', '1', '0', '0', '0' };
	//input[3] = { '0', '0', '0', '0', '0' };

	//vector<vector<char>> input(4);
	//input[0] = { '1', '1', '0', '0', '0' };
	//input[1] = { '1', '1', '0', '0', '0' };
	//input[2] = { '0', '0', '1', '0', '0' };
	//input[3] = { '0', '0', '0', '1', '1' };

	vector<vector<char>> input(3);
	input[0] = { '1', '1', '1'};
	input[1] = { '0', '1', '0'};
	input[2] = { '1', '1', '1'};
	Solution sol;
	cout << sol.numIslands(input) << endl;
	return 0;
}