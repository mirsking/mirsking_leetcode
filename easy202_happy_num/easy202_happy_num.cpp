#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n)
    {
        unordered_set<int> mid_nums;
        mid_nums.insert(n);
        return isHappy(n, mid_nums);
    }
private:
    bool isHappy(int n, unordered_set<int>& mid_nums) {

        string str = to_string(n);
        int sum = 0;
        for (int i = 0; i < str.size(); i++)
            sum += pow((str[i] - '0'), 2);

        if (sum == 1)
            return true;
        else
        {
            if (mid_nums.find(sum) != mid_nums.end())
                return false;
            else
            {
                mid_nums.insert(sum);
                return isHappy(sum, mid_nums);
            }
        }

    }



};

int main()
{
    Solution sol;
    cout << sol.isHappy(0);
    return 0;
}