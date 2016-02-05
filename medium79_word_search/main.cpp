#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(); 
		if (m == 0) return false;
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (dfs(board, word, 0, i, j, visited))
					return true;
			}
		}
		return false;
    }
private:
	static bool dfs(vector<vector<char>>& board, const string& word, int index, int x, int y,
		vector<vector<bool>> visited)
	{
		if (index == word.size())
			return true;
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
			return false;
		if (visited[x][y])
			return false;
		if (board[x][y] != word[index])
			return false;

		visited[x][y] = true;

		bool res = dfs(board, word, index + 1, x - 1, y, visited) || //up
			dfs(board, word, index + 1, x + 1, y, visited) || //down
			dfs(board, word, index + 1, x, y - 1, visited) || //left
			dfs(board, word, index + 1, x, y + 1, visited); //right
		visited[x][y] = false;
		return res;
	}
};

int main()
{
	vector<vector<char>> input(3);
	input[0] = { 'A', 'B', 'C', 'E' };
	input[1] = { 'S', 'F', 'C', 'S' };
	input[2] = { 'A', 'D', 'E', 'E' };
	Solution sol;
	cout << (sol.exist(input, "ABCCED") ? "True" : "False") << endl;
	cout << (sol.exist(input, "SEE") ? "True" : "False") << endl;
	cout << (sol.exist(input, "ABCB") ? "True" : "False") << endl;
	return 0;
}