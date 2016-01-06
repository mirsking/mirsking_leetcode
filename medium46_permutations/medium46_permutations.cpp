#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > res;
        permute(nums, nums.size(), res);
        return res;
    }
private:
    void permute(const vector<int> &nums, int size, vector< vector<int> >& res)
    {
        if(size == 0)
            return;
        else if(size == 1 && res.size() == 0)
        {
            int last_num = nums[size-1];
            vector<int> tmp;
            tmp.push_back(last_num);
            res.push_back(tmp);
        }
        else
        {
            if(size!=1)
                permute(nums, size-1, res);

            int last_num = nums[size-1];
            vector< vector<int> > res_tmp;
            for(int i=0; i<res.size(); i++)
            {
                for(int j=0; j<res[i].size(); j++)
                {
                    vector<int> tmp = res[i];
                    vector<int>::iterator it = tmp.begin()+j;
                    tmp.insert(it, last_num);
                    res_tmp.push_back(tmp);
                }
                res[i].push_back(last_num);
            }
            res.insert(res.end(), res_tmp.begin(), res_tmp.end());
        }
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    Solution sol;
    vector< vector<int> > res = sol.permute(input);

    for(int i =0;i<res.size(); i++)
    {
        vector<int>& tmp = res[i];
        for(int j=0; j<tmp.size(); j++)
        {
            std::cout << tmp[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

