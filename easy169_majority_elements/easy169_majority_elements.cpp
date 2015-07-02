#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		unordered_map<int, int> dict;
		int K = floor(nums.size() / 2);
		for (int i = 0; i < nums.size(); i++)
		{
			auto it = dict.find(nums[i]);
			if (it == dict.end())
			{
				dict[nums[i]] = 1;
				if (1>K)
					return nums[i];
			}
			else
			{
				it->second++;
				if (it->second>K)
					return nums[i];
			}
		}
    }
};

int main()
{
	int a[] = { 1};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.majorityElement(b);
	return 0;
}