#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
		int lhs = 0, rhs = nums.size();
		while (lhs < rhs)
		{
			int mid = (lhs + rhs) / 2;
			if (target == nums[mid])
				return mid;
			if (nums[lhs] < nums[mid])
			{
				if (nums[lhs] <= target && target <= nums[mid])
					rhs = mid;
				else
					lhs = mid + 1;
			}
			else
			{
				if (nums[mid] <= target && target <= nums[rhs - 1])
					lhs = mid + 1;
				else
					rhs = mid;
			}
		}
		return -1;
    }
};

int main()
{
	vector<int> input = {4,5,6,0,1,2,3};
	Solution sol;
	cout << sol.search(input, 0)<< endl;
	cout << sol.search(input, 1)<< endl;
	cout << sol.search(input, 2)<< endl;
	cout << sol.search(input, 3)<< endl;
	cout << sol.search(input, 4)<< endl;
	cout << sol.search(input, 5)<< endl;
	cout << sol.search(input, 6)<< endl;
	cout << sol.search(input, -1)<< endl;

	return 0;
}