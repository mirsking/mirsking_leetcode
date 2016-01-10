#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if(m==0)
            return 0;

        int n = grid[0].size();
        if(n==0)
            return 0;

        vector< vector<int> > dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++)
        {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i=1; i<m; i++)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                int tmp1 = dp[i-1][j];
                int tmp2 = dp[i][j-1];
                dp[i][j] = min(tmp1, tmp2) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    #define N 3
    int tmp[N][N] = {{1,2,3}, {1,3,4}, {2,1,2}};
    vector< vector<int> > input(N);
    for(int i=0; i<N; i++)
        input[i] = vector<int>(tmp[i], tmp[i]+N);
    Solution sol;
    cout << sol.minPathSum(input) << endl;
    return 0;
}

