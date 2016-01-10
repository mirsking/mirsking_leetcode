#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i=1; i<=9; i++)
            nums.push_back(i);

        vector<vector<int> > res;
        vector<int> cur;
        combination(nums, n, 0, k, cur, res);

        vector<vector<int> > final_res;
        for(auto it = res.begin(); it!=res.end(); it++)
        {
            if(it->size() == k)
                final_res.push_back(*it);
        }
        return final_res;
    }
private:
    void combination(vector<int>& nums, int gap, int start, int max_height, vector<int> &cur, vector<vector<int> > &res)
    {
        if(gap == 0)
        {
            res.push_back(cur);
            return;
        }

        int previous = -1;
        for(int i=start; i<nums.size(); i++)
        {
            if(previous == nums[i])
                return;
            if(gap < nums[i])
                return;

            if(cur.size()>=max_height)
                return;

            cur.push_back(nums[i]);
            combination(nums, gap-nums[i], i+1, max_height, cur, res);
            cur.pop_back();
        }
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
    Solution sol;
    vector<vector<int> > res = sol.combinationSum3(3,9);
    print2DVecotr(res);
    return 0;
}
