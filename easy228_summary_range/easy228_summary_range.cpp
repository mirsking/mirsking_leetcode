#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> res;
		int begin, end;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i == 0)
			{
				begin = nums[0]; end = nums[0];
			}
			else
			{
				if (end + 1 == nums[i])
					end = nums[i];
				else
				{
					if (begin == end)
						res.push_back(to_string(begin));
					else
						res.push_back(to_string(begin) + "->" + to_string(end));
					begin = nums[i]; end = nums[i];
				}

			}
		}
		return res;
    }
};


int main()
{
	int a[] = {0,1,2,4,5,7};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	vector<string> c = sol.summaryRanges(b);
	return 0;
}