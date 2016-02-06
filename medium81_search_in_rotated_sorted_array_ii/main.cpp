#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
		int lhs = 0, rhs = nums.size();
		while (lhs != rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (target == nums[mid])
				return true;
			if (nums[lhs] < nums[mid])
			{
				if (nums[lhs] <= target && target <= nums[mid])
					rhs = mid;
				else
					lhs = mid + 1;
			}
			else if (nums[lhs] > nums[mid])
			{
				if (nums[mid] <= target && target <= nums[rhs - 1])
					lhs = mid + 1;
				else
					rhs = mid;
			}
			else//nums[lhs]==nums[rhs], this means like 1 3 1 1
				lhs++;
		}
		return false;
	}
};

int main()
{
	vector<int> input = {4,5,6,0,1,2,3};
	Solution sol;
	cout << (sol.search(input, 0) ? "True" : "False") << endl;
	cout << (sol.search(input, 1) ? "True" : "False") << endl;
	cout << (sol.search(input, 2) ? "True" : "False") << endl;
	cout << (sol.search(input, 3) ? "True" : "False") << endl;
	cout << (sol.search(input, 4) ? "True" : "False") << endl;
	cout << (sol.search(input, 5) ? "True" : "False") << endl;
	cout << (sol.search(input, 6) ? "True" : "False") << endl;
	cout << (sol.search(input, -1) ? "True" : "False") << endl;

	return 0;
}