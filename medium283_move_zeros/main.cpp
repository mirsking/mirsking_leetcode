#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] != 0)
			{
				nums[idx] = nums[i];
				if (idx != i)
					nums[i] = 0;
				idx++;
			}
		}
    }
};

int main()
{
	vector<int> input = {0, 1, 0, 2, 3, 0, 83};
	Solution sol;
	sol.moveZeroes(input);
	for (auto& i : input)
		cout << i << " ";
	return 0;
}