#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        vector<int> cur;
        subsets(nums, cur, 0, res);
		//cout << "origin size:" << res.size() << endl;
		sort(res.begin(), res.end());
		auto end = unique(res.begin(), res.end());
		/cout << "unique size:" << end-res.begin() << endl;
		res.resize(end - res.begin());
		return res;
    }
private:
    void subsets(vector<int> &nums, vector<int> &cur, int idx, vector<vector<int> >& res)
    {
        if(idx == nums.size())
        {
            res.push_back(cur);
            return;
        }

        // don't use nums[idx]
        subsets(nums, cur, idx+1, res);

        //use nums[idx]
        cur.push_back(nums[idx]);
        subsets(nums, cur, idx+1, res);
        cur.pop_back();
    }
};

int main()
{
	vector<int> input = { 1, 2, 2 };
	Solution sol;
	vector<vector<int>> res = sol.subsetsWithDup(input);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}