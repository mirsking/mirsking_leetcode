#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//greedy algorithm
	bool canJump(vector<int>& nums) {
		int reach = 1;
		for (int i = 0; i < reach && reach < nums.size(); i++)
			reach = max(reach, nums[i] + i + 1);
		return reach >= nums.size();
	}
};

int main()
{
	//vector<int> input = { 2, 3, 1, 1, 4 };
	vector<int> input = { 3, 2, 1, 0, 4 };
	Solution sol;
	cout << (sol.canJump(input)? "True":"False") << endl;
	return 0;
}