#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, bool> dp_map;
	
		for (auto& num : nums)
		{
			auto iter = dp_map.find(num);
			if (iter != dp_map.end())
				return true;
			else
				dp_map[num] = true;
		}

		return false;

    }
};

int main(int argc, char** argv)
{
	int tmp[] = {10};
	int length = sizeof(tmp) / sizeof(int);
	length = 0;

	Solution sol;
	vector<int> nums(tmp, tmp + length);

	bool res = sol.containsDuplicate(nums);

	return 0;
}