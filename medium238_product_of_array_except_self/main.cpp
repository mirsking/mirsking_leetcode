#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// space O(1), time O(n)
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();

		vector<int> res(n,1);
		for (int i = n - 2; i >= 0; i--)
			res[i] = res[i + 1] * nums[i + 1];

		int left = 1;
		for (int i = 0; i < n; i++)
		{
			res[i] = res[i] * left;
			left *= nums[i];
		}
		return res;
	}

	/*
	// space O(n), time O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> left(n,1), right(n, 1);
		for (int i = 1; i < n; i++)
			left[i] = left[i - 1] * nums[i - 1];

		for (int i = n - 2; i >= 0; i--)
			right[i] = right[i + 1] * nums[i + 1];

		vector<int> res(n, 0);
		for (int i = 0; i < n; i++)
			res[i] = left[i] * right[i];

		return res;
    }
	*/
};

int main()
{
	vector<int> input = { 1, 2, 3, 4 };
	Solution sol;
	vector<int> res = sol.productExceptSelf(input);
	for (auto& i : res)
		cout << i << " ";
	return 0;
}