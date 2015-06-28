#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
		if (nums.size() == 0)
			return INT_MIN;
		int res = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			if (res > nums[i])
			{
				res = nums[i];
				break;
			}
		}
		return res;
    }
};

int main()
{
	int a[] = {1,2,1};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.findMin(b);
	return 0;
}