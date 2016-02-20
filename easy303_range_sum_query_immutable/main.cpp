#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
		if (nums.empty())
			return;

		dp.push_back(0);
		for (auto& n : nums)
			dp.push_back(dp.back() + n);
    }

    int sumRange(int i, int j) {
		return dp[j+1] - dp[i];
    }
private:
	vector<int> dp;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

int main()
{
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray numArray(nums);
	cout << numArray.sumRange(0, 2) << endl;
	cout << numArray.sumRange(2, 5) << endl;
	cout << numArray.sumRange(0, 5) << endl;
	return 0;
}