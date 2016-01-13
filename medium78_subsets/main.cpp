#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        int n = nums.size();
        vector<int> cur;
        subsets(nums, cur, 0, res);
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

void print2DVecotr(vector<vector<int> >& input)
{
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input[i].size(); j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> input = {1,2,3};
    Solution sol;
    auto res = sol.subsets(input);
    print2DVecotr(res);
    return 0;
}
