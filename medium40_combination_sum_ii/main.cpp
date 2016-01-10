#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> cur;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);

        return res;
    }

private:
    void dfs(vector<int>& candidates, int gap, int start, vector<int> &cur, vector<vector<int> >& res)
    {
        if(gap==0)
        {
            res.push_back(cur);
            return;
        }

        int previous = -1;
        for(int i=start; i<candidates.size(); i++)
        {
            if(previous == candidates[i]) // have already used candidates[i]
                continue;

            if(gap<candidates[i])
                return;

            previous = candidates[i];
            cur.push_back(candidates[i]);
            dfs(candidates, gap-candidates[i], i+1, cur, res);
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
    #define N 7
    int tmp[] = {10,1,2,7,6,1,5};
    vector<int> input(tmp, tmp+N);
    Solution sol;
    vector<vector<int> > res = sol.combinationSum2(input, 8);
    print2DVecotr(res);
    return 0;

}
