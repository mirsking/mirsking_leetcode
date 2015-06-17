#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		vector<int> nums_bak;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums_bak.push_back(nums[i]);
		}
		
		nums.resize(nums_bak.size());
		for (int i = 0; i < nums_bak.size(); i++)
			nums[i] = nums_bak[i];

		return nums_bak.size();
    }
};

int main(int argc, char** argv)
{
	
	int num[] = {1,2,1,4,5,6,7};
	//vector<int> nums(num, num+sizeof(num)/sizeof(int));
	vector<int> nums;

	Solution sol;
	cout << sol.removeElement(nums, 1);

	return 0;
}