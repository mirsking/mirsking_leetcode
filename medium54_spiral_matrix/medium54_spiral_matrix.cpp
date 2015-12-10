#include <vector>
#include <iostream>
using namespace std;

#define floatDiv(a,b) (float(a)/float(b))

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;

		int m = matrix.size();
		if (m == 0)
			return res;
		int n = matrix[0].size();

		int x1 = 0, y1 = 0;
		int x2 = m - 1, y2 = n - 1;

		while (x1 <= x2 && y1 <= y2)
		{
			// up row
			for (int i = y1; i <= y2; i++)
				res.push_back(matrix[x1][i]);
			// right column
			for (int j = x1 + 1; j <= x2; j++)
				res.push_back(matrix[j][y2]);

			// down row
			if (x1 != x2) // == means up row already got the res
			{
				for (int k = y2 - 1; k >= y1; k--)
					res.push_back(matrix[x2][k]);
			}
			// left column
			if (y1 != y2) // == means right column already got the res
			{
				for (int h = x2 - 1; h >= x1 + 1; h--)
					res.push_back(matrix[h][y1]);
			}

			x1++; y1++; x2--; y2--;

		}
		return res;
    }
};

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int m = 1, n = 3;
	vector<vector<int>> matrix;
	for (int i = 0; i < m; i++)
	{
		vector<int> v;
		for (int j = 0; j < n; j++)
		{
			v.push_back(a[i*n + j]);
		}
		matrix.push_back(v);
	}

	Solution sol;
	vector<int> res = sol.spiralOrder(matrix);
	for (auto& v : res)
		cout << v << " ";
	return 0;
}