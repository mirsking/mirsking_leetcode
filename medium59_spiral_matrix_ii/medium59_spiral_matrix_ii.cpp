#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res;
		res.resize(n);
		for (int i = 0; i < n; i++)
			res[i].resize(n);
		int x = 0, y = 0;// x is column, y is row
		for (int i = 1; i <= n*n; i++)
		{
			res[y][x] = i;
			if (y <= x && x + y < n-1)
				x++;
			else if (y < x && x + y >= n-1)
				y++;
			else if (y >= x && x + y >n-1)
				x--;
			else if (y>x + 1 && x + y <= n - 1)
				y--;
			else if (y == x + 1 && x + y <= n - 1) /* sucks*/
				x++;
		}
		return res;
    }
};

void printVV(vector<vector<int>>& vec)
{
	for (auto it1 = vec.begin(); it1 != vec.end(); it1++)
	{
		for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	Solution sol;
	printVV(sol.generateMatrix(2));
	printVV(sol.generateMatrix(3));
	printVV(sol.generateMatrix(4));
	printVV(sol.generateMatrix(5));

	return 0;
}