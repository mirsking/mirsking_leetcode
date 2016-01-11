#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    vector<vector<int > > threeSum(vector<int>& nums)
    {
        vector<vector<int> > res;

        if(nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        for(auto a = nums.begin(); a!=prev(nums.end(), 2); a++)
        {
            auto b = next(a);
            if(a>nums.begin() && *a == *prev(a)) continue; //repeat a

            auto c = prev(nums.end());
            while(b<c)
            {
                int sum = *a + *b + *c;
                if(sum == 0)
                {
                    vector<int> tmp = {*a, *b, *c};
                    res.push_back(tmp);
                }

                if(sum < 0)
                    b++;
                else
                    c--;
            }
        }
        //sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
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
    vector<int> input = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    auto res = sol.threeSum(input);
    print2DVecotr(res);
    return 0;
}
