#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return;

		k = k%nums.size();
		while (k > 0)
		{
			int tmp = *(nums.end()-1);
			nums.pop_back();
			nums.insert(nums.begin(), tmp);
			k--;
		}
    }
};

int main(int argc, char** argv)
{
	int num[] = {1,2,3,4,5,6,7};
	vector<int> nums(num, num+sizeof(num)/sizeof(int));
	Solution sol;
	sol.rotate(nums, 3);
	return 0;
}