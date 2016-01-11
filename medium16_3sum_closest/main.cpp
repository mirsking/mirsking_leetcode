#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return 0;

        sort(nums.begin(), nums.end());

        int result = 0;
        int min_gap = INT_MAX;

        for(auto a = nums.begin(); a!=prev(nums.end(), 2); a++)
        {
            auto b = next(a);
            auto c = prev(nums.end());

            while(b<c)
            {
                int sum = *a + *b + *c;
                int gap = abs(sum-target);
                if(gap < min_gap)
                {
                    result = sum;
                    min_gap = gap;
                }

                if(sum<target)
                    b++;
                else
                    c--;
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> input = {1,2,4,8,16,32,64,128};
    cout << sol.threeSumClosest(input, 82) << endl;
    return 0;
}

