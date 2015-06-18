#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		unordered_map<int, bool> num_map;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			if (num_map.find(nums[i]) == num_map.end())
			{
				num_map[nums[i]] = true;
				res.push_back(nums[i]);
			}
		}
		nums.resize(res.size());
		for (int i = 0; i < res.size(); i++)
		{
			nums[i] = res[i];
		}
		return res.size();
    }
};


int main(int argc, char** argv)
{
	int a[] = { 1, 1, 2};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.removeDuplicates(b);
	return 0;
}