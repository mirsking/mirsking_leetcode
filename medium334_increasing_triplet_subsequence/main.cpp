#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	//https://www.hrwhisper.me/leetcode-increasing-triplet-subsequence/
    bool increasingTriplet(vector<int>& nums) {
		int x1 = INT_MAX, x2 = INT_MAX;
		for (int i = 0; i < nums.size(); i++)
		{
			int val = nums[i];
			if (val <= x1)
				x1 = val;
			else if (val <= x2)
				x2 = val;
			else
				return true;
		}
		return false;
    }
};

int main()
{
	return 0;
}