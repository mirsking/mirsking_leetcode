#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return;
		int n = matrix[0].size();

		vector<vector<int>> new_matrix(n, vector<int>(m));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				new_matrix[i][j] = matrix[m-j-1][i];
			}
		}
		matrix = new_matrix;
    }
};

int main()
{

	Solution sol;
	vector<vector<int>> matrix(2,vector<int>(2,0));
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[1][0] = 3;
	matrix[1][1] = 4;
	sol.rotate(matrix);
	return 0;
}