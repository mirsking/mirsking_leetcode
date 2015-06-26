#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (k < 1 || t < 0 || nums.empty())
			return false;
		multiset<int> box;
		box.insert(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			auto iter = box.lower_bound(nums[i] - t);
			if (iter != box.end())
			{
				if (abs(*iter - nums[i]) <= t)
					return true;
			}
			if (i>=k)
				box.erase(nums[i - k]);
			box.insert(nums[i]);
			
		}
		return false;
    }
    
};

int main()
{
	int a[] = {1,3,1 };
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.containsNearbyAlmostDuplicate(b, 1, 1);
	return 0;
}