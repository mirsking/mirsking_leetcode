#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @brief singleNumber
     * 我们知道，两个相等的数异或结果为0。因此，首次扫描数组，得到两个单独的数A、B的异或结果AxorB。
     * 因为A和B不相等，因此AxorB一定不为0，且二进制位为1的位A和B一定不同。
     * 任取AxorB中的一个二进制位，可以将原数组元素分成两组异或即得结果。
     *
     * 注意n&(~(n-1))表示取的n中的最后一位二进制位。
     * 另外，&的优先级小于==的优先级。
     * @param nums
     * @return
     */
    vector<int> singleNumber(vector<int>& nums)
    {
        int AxorB = 0;
        for(int i=0;i<nums.size(); i++)
            AxorB ^= nums[i];

        int mask = AxorB & (~(AxorB-1));
        int A = 0, B = 0;
        for(int i=0; i< nums.size(); i++)
        {
            if((mask & nums[i])==0)
                A ^= nums[i];
            else
                B ^= nums[i];
        }
        return vector<int>({A, B});
    }


    /**
     * @brief singleNumber : not const space version
     * @param nums
     * @return
     */
    /*
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(res.find(nums[i])!=res.end())
                res.erase(nums[i]);
            else
                res.insert(nums[i]);
        }
        vector<int> final_res(res.begin(), res.end());
        return final_res;
    }
    */
};

int main()
{
    Solution sol;
    vector<int> input = {1,2,1,3,2,5};
    auto res = sol.singleNumber(input);
    for(auto& r:res)
        cout << r << endl;
    return 0;
}
