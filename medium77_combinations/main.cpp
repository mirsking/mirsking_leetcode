#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        cur.resize(k);
        solve(n, k, 0, 1);
        return res;
    }
private:

    void solve(const int n, const int k, int cur_idx, int cur_val)
    {
        if(cur_idx == k)
        {
            res.push_back(cur);
            return;
        }
        else if(cur_idx > k)
            return;

        for(int i=cur_val; i<=n; i++)
        {
            cur[cur_idx] = i;
            solve(n,k, cur_idx+1, i+1);
        }
    }

    vector<vector<int> > res;
    vector<int> cur;
};

int main()
{
    Solution sol;
    vector<vector<int> > res = sol.combine(4,2);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}
