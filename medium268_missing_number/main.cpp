#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
			res ^= (i + 1) ^ nums[i];
		return res;
	}
	/*
	// space O(n) time O(n)
    int missingNumber(vector<int>& nums) {
		int n = nums.size();
		vector<int> tmp(n + 1, -1);
		for (auto& i : nums)
		{
			tmp[i] = i;
		}
		for (int i = 0; i < n + 1; i++)
		{
			if (tmp[i] != i)
				return i;
		}
    }
	*/
};

int main()
{
	vector<int> input = {1,2,4,0};
	Solution sol;
	cout << sol.missingNumber(input) << endl;
	return 0;
}