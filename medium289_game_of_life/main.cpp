#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		int m = board.size(); 
		if (m == 0)return;
		int n = board[0].size();
		vector<pair<int, int>> dead;
		vector<pair<int, int>> live;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int num = calcLiveNeighbor(board, i, j);
				if (board[i][j] == 1)
				{
					if (num < 2 || num >3)
						dead.push_back(make_pair(i, j));
				}
				else
				{
					if (num == 3)
						live.push_back(make_pair(i, j));
				}
			}
		}

		for (auto& d : dead)
			board[d.first][d.second] = 0;

		for (auto& l : live)
			board[l.first][l.second] = 1;
		 
    }
private:
	inline int calcLiveNeighbor(vector<vector<int>>& board, int i, int j)
	{
		int m = board.size(); int n = board[0].size();
		int res = 0;
		vector<pair<int, int>> neighbors = { 
			{i-1, j},	//up
			{i-1, j-1}, //up left
			{i-1, j+1}, //up right
			{i+1, j},	//down
			{i+1, j-1}, //down left
			{i+1, j+1}, //down righ
			{i, j-1}, //left
			{i, j+1}, //right
		};
		for (auto& p : neighbors)
		{
			if (0 <= p.first && p.first < m && 0 <= p.second && p.second < n)
				res += board[p.first][p.second];
		}
		return res;
	}
};

void print2D(vector<vector<int>>& input)
{
	for (auto&v : input)
	{
		for (auto& n : v)
			cout << n << " ";
		cout << endl;
	}
	cout << endl << endl;
}

int main()
{
	vector<vector<int>> input(1, vector<int>(2, 1));
	input[0][0] = 0;
	Solution sol;
	print2D(input);
	
	for (int i = 0; i < 5; i++)
	{
		sol.gameOfLife(input);
		print2D(input);
	}
	return 0;
}