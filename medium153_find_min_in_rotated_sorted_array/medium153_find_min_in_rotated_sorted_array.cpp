#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
		int L = 0;
		int R = nums.size();
		while (L < R)
		{
			int M = (L + R) / 2;
			if (R-L==2 || R-L==1)
				return min(nums[L], nums[M]);

			if (nums[L] > nums[M])
				R = M+1;
			else if (nums[L] < nums[M])
				L = M;
		}
    }
};

int main()
{
	int a[] = {1,2,3};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.findMin(b);
	return 0;
}