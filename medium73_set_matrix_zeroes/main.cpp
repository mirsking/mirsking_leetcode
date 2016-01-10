#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        int m=matrix.size();
        if(m==0)
            return;
        int n=matrix[0].size();
        if(n==0)
            return;

        unordered_set<int> zero_rows, zero_cols;
        for(int i=0;i<m;i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(zero_rows.find(i)==zero_rows.end())
                        zero_rows.insert(i);
                    if(zero_cols.find(j)==zero_rows.end())
                        zero_cols.insert(j);
                }
            }
        }

        for(auto it=zero_rows.begin(); it!=zero_rows.end(); it++)
        {
            matrix[*it] = vector<int>(n, 0);
        }
        for(auto it=zero_cols.begin(); it!=zero_cols.end(); it++)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][*it] = 0;
            }
        }
    }
};

int main()
{
#define N 3
    int tmp[N][N] = {{1,2,0}, {1,2,1}, {1,0,0}};
    vector<vector<int> > input(3);
    for(int i=0; i<N; i++)
    {
        input[i] = vector<int>(tmp[i], tmp[i] + N);
    }
    Solution sol;
    sol.setZeroes(input);
    for(int i=0; i<input.size(); i++)
    {
        for(int j=0; j<input.size(); j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
