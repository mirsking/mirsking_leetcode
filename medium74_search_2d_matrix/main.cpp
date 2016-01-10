#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        if(matrix.size()==0)
            return false;

        int m = matrix.size();
        if(m==0)
            return false;
        int n = matrix[0].size();

        for(int i=0; i<m; i++)
        {
            int &left = matrix[i][0], &right = matrix[i][n-1];
            if(target == left || target == right)
                return true;
            else if(target > left && target < right)
            {
                for(int j=1; j<n-1; j++)
                {
                    if(target == matrix[i][j])
                        return true;
                }
                return false;
            }
            else if(target > right)
            {
                continue;
            }
            else if(target < left)
                return false;
        }
        return false;
    }
};
int main()
{
    int a[] = {1,3,5,7};
    int b[] = {10,11,12,13};
    Solution sol;
    vector<vector<int> > input;
    vector<int> tmp1(a, a+sizeof(a)/sizeof(int));
    vector<int> tmp2(b, b+sizeof(b)/sizeof(int));
    input.push_back(tmp1);
    input.push_back(tmp2);
    cout << sol.searchMatrix(input, 9) << endl;
    return 0;
}
