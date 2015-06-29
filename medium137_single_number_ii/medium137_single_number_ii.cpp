#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> dict;
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			auto& num = *it;
			auto iter = dict.find(num);
			if (iter == dict.end())
				dict[num] = 1;
			else if (iter->second == 1)
				dict[num] = 2;
			else if (iter->second == 2)
				dict[num] = 3;
		}
		for (auto it = dict.begin(); it != dict.end(); it++)
		{
			if (it->second == 1)
				return it->first;
		}
    }
};

int main()
{
	int a[] = { 1, 2,1, 0, 2 ,1,2};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.singleNumber(b);
	return 0;
}