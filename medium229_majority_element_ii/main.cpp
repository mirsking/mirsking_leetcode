#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int a = INT_MIN, b = INT_MIN;
		int c1 = 0, c2 = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == a)
				c1++;
			else if (nums[i] == b)
				c2++;
			else if (c1 == 0)
			{
				a = nums[i];
				c1 = 1;
			}
			else if (c2 == 0)
			{
				b = nums[i];
				c2 = 1;
			}
			else
			{
				c1--;
				c2--;
			}
		}

		vector<int> res;
		c1 = 0;
		c2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == a)
				c1++;
			else if (nums[i] == b)
				c2++;
		}
		if (c1>n / 3)
			res.push_back(a);
		if (c2 > n / 3 && b != a)
			res.push_back(b);

		return res;
    }
};

int main()
{
	Solution sol;
	vector<int> input = {1,2,3,4,5};
	auto res = sol.majorityElement(input);
	for (auto& i : res)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}