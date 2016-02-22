#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<int> res(n);
		int even = (n + 1) / 2;
		int odd = n;
		for (int i = 0; i < n; i++)
		{
			res[i] = (i & 1) ? nums[--odd] : nums[--even];
		}
		for (int i = 0; i < n; i++)
			nums[i] = res[i];
    }
};

int main()
{
	vector<int> input = {1, 5, 1, 1, 6};
	Solution sol;
	sol.wiggleSort(input);
	for (auto& i : input)
		cout << i << endl;
	return 0;
}