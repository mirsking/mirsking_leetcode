#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> existNums;

		int start = 0, end = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (existNums.find(nums[i]) == existNums.end())
			{
				existNums.insert(nums[i]);
				end++;
			}
			else
				return true;
			
			if (end - start>k)
			{
				existNums.erase(nums[start]);
				start++;
			}
		}

		return false;

    }
};


int main()
{
	int a[] = {1,1,2};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.containsNearbyDuplicate(b,29999);
	return 0;
}