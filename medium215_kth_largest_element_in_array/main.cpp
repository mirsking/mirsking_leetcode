#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		sort(nums.rbegin(), nums.rend());
		return nums[k - 1];
    }
};

int main()
{
	return 0;
}