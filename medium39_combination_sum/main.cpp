#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> >res;
        vector<int> cur;

        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
        return res;
    }

private:
    void dfs(vector<int>& candidates, int gap, int start, vector<int>& cur, vector<vector<int> >& res)
    {
        if(gap==0) // find legal solution
        {
            res.push_back(cur);
            return;
        }

        for(int i=start; i<candidates.size(); i++)
        {
            if(gap < candidates[i])
                return; //prune

            cur.push_back(candidates[i]);
            dfs(candidates, gap-candidates[i], i, cur, res);
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
    #define N 4
    int tmp[] = {2,3,6,7};
    vector<int> input(tmp, tmp+N);
    Solution sol;
    vector<vector<int> > res = sol.combinationSum(input, 7);
    print2DVecotr(res);
    return 0;

}
