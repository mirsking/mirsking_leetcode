#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int min_len = n;
		int left = 0, right = 1;
		//left ~ right-1
		int sum = 0;
		while (left < n)
		{
			while (right <=n && sum <s)
			{
				sum += nums[right-1];
				right = right + 1;
			}
			if (sum >= s)
			{
				int tmp = right - left - 1;
				min_len = min_len > tmp ? tmp : min_len;

				sum -= nums[left];
				left++;
			}
			else
			{
				break;
			}
		}
		if (min_len == n && getSum(nums, 0, n) < s)
			return 0;

		return min_len;
    }
private:
	inline int getSum(vector<int>& nums, int begin, int end)
	{
		int res = 0;
		for (int i = begin; i < end; i++)
			res += nums[i];
		return res;
	}
};

int main()
{
	vector<int> input = {2,3,1,2,4,3};
	Solution sol;
	cout << sol.minSubArrayLen(16, input) << endl;
	return 0;
}