#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        const int OFFSET = 2;
        if(n<OFFSET) return n;

        int index = OFFSET;
        for(int i=OFFSET; i<n; i++)
        {
            if(nums[i] != nums[index-OFFSET])
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main()
{
    vector<int> input = {1,1,1,2,2,3,3,3,3,4};
    Solution sol;
    cout << sol.removeDuplicates(input) << endl;
    for(int i=0;i<input.size(); i++)
        cout << input[i] << endl;
    return 0;
}
