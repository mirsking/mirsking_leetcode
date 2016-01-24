#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        bool start_found = false;
        for(size_t i = 0; i<nums.size(); i++)
        {
            if(nums[i] == target)
            {
                if(!start_found)
                {
                    start = i; end = i;
                    start_found = true;
                }
                else
                {
                    end = i;
                }
            }
            else if(start_found)
            {// found start and end
                break;
            }
        }
        return vector<int>({start, end});
    }
};

int main()
{

    int tmp[] = {5, 7, 7, 8, 8, 10};
    vector<int> input(tmp, tmp+sizeof(tmp)/sizeof(int));
    Solution sol;
    vector<int> res = sol.searchRange(input, 8);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
