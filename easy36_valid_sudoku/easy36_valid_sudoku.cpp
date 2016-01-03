#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0)
			return true;

		int m = board[0].size();
		if (m != n)
			return false;
		vector<std::pair<int, int>> indexes;

		for (int i = 0; i < n; i++)
		{
			//row
			indexes.clear();
			for (int j = 0; j < n; j++)
				indexes.push_back(std::make_pair(i, j));

			if (!isValidSubSudoku(board, indexes))
				return false;

			// column
			indexes.clear();
			for (int j = 0; j < n; j++)
				indexes.push_back(std::make_pair(j, i));

			if (!isValidSubSudoku(board, indexes))
				return false;
		}

		//sub-box
		for (int i = 0; i < n; i += 3)
		{
			for (int j = 0; j < n; j += 3)
			{
				indexes.clear();
				for (int k = i; k < i+3;k++)
					for (int h = j; h < j+3;h++)
						indexes.push_back(std::make_pair(k, h));

				if (!isValidSubSudoku(board, indexes))
					return false;
			}

		}

		return true;
		
    }

private:
	bool isValidSubSudoku(vector<vector<char>>& board, vector<std::pair<int, int>>& indexs)
	{
		if (indexs.size() != board.size())
			return false;
		vector<int> count(board.size(), 0);
		for (int i = 0; i < indexs.size(); i++)
		{
			int& row = indexs[i].first;
			int& col = indexs[i].second;
			if (board[row][col] == '.')
				continue;
			int num = board[row][col] - '1';
			if (count[num] != 0)
				return false;
			else
				count[num] = 1;
		}
		return true;
		
	}
	const static int DIM = 9;
};

int main()
{
	Solution sol;
	vector<vector<char>> input(9);
	input[0].push_back('5');
	input[0].push_back('3');
	input[0].push_back('.');
	input[0].push_back('.');
	input[0].push_back('7');
	input[0].push_back('.');
	input[0].push_back('.');
	input[0].push_back('.');
	input[0].push_back('.');
	
	input[1].push_back('6');
	input[1].push_back('.');
	input[1].push_back('.');
	input[1].push_back('1');
	input[1].push_back('9');
	input[1].push_back('5');
	input[1].push_back('.');
	input[1].push_back('.');
	input[1].push_back('.');

	input[2].push_back('.');
	input[2].push_back('9');
	input[2].push_back('8');
	input[2].push_back('.');
	input[2].push_back('.');
	input[2].push_back('.');
	input[2].push_back('.');
	input[2].push_back('6');
	input[2].push_back('.');

	input[3].push_back('8');
	input[3].push_back('.');
	input[3].push_back('.');
	input[3].push_back('.');
	input[3].push_back('6');
	input[3].push_back('.');
	input[3].push_back('.');
	input[3].push_back('.');
	input[3].push_back('3');

	input[4].push_back('4');
	input[4].push_back('.');
	input[4].push_back('.');
	input[4].push_back('8');
	input[4].push_back('.');
	input[4].push_back('3');
	input[4].push_back('.');
	input[4].push_back('.');
	input[4].push_back('1');

	input[5].push_back('7');
	input[5].push_back('.');
	input[5].push_back('.');
	input[5].push_back('.');
	input[5].push_back('2');
	input[5].push_back('.');
	input[5].push_back('.');
	input[5].push_back('.');
	input[5].push_back('6');

	input[6].push_back('.');
	input[6].push_back('6');
	input[6].push_back('.');
	input[6].push_back('.');
	input[6].push_back('.');
	input[6].push_back('.');
	input[6].push_back('2');
	input[6].push_back('8');
	input[6].push_back('.');

	input[7].push_back('.');
	input[7].push_back('.');
	input[7].push_back('.');
	input[7].push_back('4');
	input[7].push_back('1');
	input[7].push_back('9');
	input[7].push_back('.');
	input[7].push_back('.');
	input[7].push_back('5');

	input[8].push_back('.');
	input[8].push_back('.');
	input[8].push_back('.');
	input[8].push_back('.');
	input[8].push_back('8');
	input[8].push_back('.');
	input[8].push_back('.');
	input[8].push_back('7');
	input[8].push_back('9');

	if (sol.isValidSudoku(input))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}