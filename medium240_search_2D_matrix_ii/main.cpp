#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (n == 0)
			return false;
		int m = matrix[0].size();

		bool res = false;
		for (int i = 0; i < n; i++)
		{
			if (target >= matrix[i][0] && target <= matrix[i][m - 1])
				res |= binarySearch(matrix[i], target);
		}
		return res;
    }
private:
	bool binarySearch(vector<int>& nums, int val)
	{
		return binarySearch(nums, 0, nums.size(), val);
	}
	bool binarySearch(vector<int>& nums, int left, int right, int val)
	{
		if (left >= right)
			return false;
		int mid = (left + right) / 2;
		if (nums[mid] == val)
			return true;
		else if (nums[mid] < val)
			left = mid + 1;
		else if (nums[mid] > val)
			right = mid;
		return binarySearch(nums, left, right, val);
	}
};

int main()
{
	vector<vector<int>> input(5, vector<int>(5));
	input[0] = { 1, 4, 7, 11, 15 };
	input[1] = { 2, 5, 8, 12, 19 };
	input[2] = { 3, 6, 9, 16, 22 };
	input[3] = { 10, 13, 14, 17, 24 };
	input[4] = { 18, 21, 23, 26, 30 };
	Solution sol;
	cout << (sol.searchMatrix(input, 5) ? "True" : "False") << endl;
	cout << (sol.searchMatrix(input, 20) ? "True" : "False") << endl;
	return 0;
}