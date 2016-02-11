#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 广搜
// 从四边的'O'向中间广搜，搜到的'O'都是没被包围的，标记后最终将其保留，其它的'O'置'X'
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.empty())
			return;

		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++)
		{
			bfs(board, i, 0);
			bfs(board, i, n - 1);
		}
		for (int i = 1; i < n - 1; i++)
		{
			bfs(board, 0, i);
			bfs(board, m - 1, i);
		}
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == '+')
					board[i][j] = 'O';
			}
		}
    }
private:
	void bfs(vector<vector<char>>& board, int start_x, int start_y)
	{
		typedef pair<int, int> state_t;
		const int m = board.size();
		const int n = board[0].size();

		/**
		* if state is valid and value is 'O' return true
		*/
		auto state_is_valid = [&](const state_t& s) //valid 'O' state
		{
			const int x = s.first;
			const int y = s.second;
			if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O')
				return false;
			else
				return true;
		};

		/**
		* if state is 'O;, mark it as '+'
		* return the marked states, i.e. 'O' state
		*/
		auto state_extend = [&](const state_t &s)
		{
			vector<state_t> res;
			const int x = s.first;
			const int y = s.second;
			//up down left right
			const state_t new_states[4] = { { x - 1, y }, { x + 1, y }, { x, y - 1 }, { x, y + 1 } };
			for (auto& ss : new_states)
			{
				if (state_is_valid(ss))
				{
					board[ss.first][ss.second] = '+';
					res.push_back(ss);
				}
			}
			return res;
		};

		queue<state_t> que;
		state_t start = {start_x, start_y};
		if (state_is_valid(start))
		{
			board[start.first][start.second] = '+';
			que.push(start);
		}
		while (!que.empty())
		{
			auto& cur = que.front();
			que.pop();
			auto new_states = state_extend(cur);
			for (auto& ss : new_states)
				que.push(ss);
		}
	}
};

void showMatrix(vector<vector<char>>& mat)
{
	for (auto& row : mat)
	{
		for (auto& ch : row)
			cout << ch;
		cout << endl;
	}
}

int main()
{
	vector<vector<char>> input(4, vector<char>(4, 'X'));
	input[1][1] = 'O';
	input[1][2] = 'O';
	input[2][2] = 'O';
	input[3][2] = 'O';
	input[3][1] = 'O';
	showMatrix(input);
	cout << endl;
	Solution sol;
	sol.solve(input);
	showMatrix(input);
	return 0;
}