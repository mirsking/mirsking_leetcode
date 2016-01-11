#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > res;
        int n= nums.size();
        if(n<4)
            return res;

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int> > > cache;
        for (size_t a = 0; a < nums.size(); ++a) {
            for (size_t b = a + 1; b < nums.size(); ++b) {
                cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
            }
        }
        for (int c = 0; c < nums.size(); ++c) {
            for (size_t d = c + 1; d < nums.size(); ++d) {
                const int key = target - nums[c] - nums[d];
                if (cache.find(key) == cache.end()) continue;
                const auto& vec = cache[key];
                for (size_t k = 0; k < vec.size(); ++k) {
                    if (c <= vec[k].second)
                        continue; // 有重叠
                    res.push_back( { nums[vec[k].first],
                    nums[vec[k].second], nums[c], nums[d] });
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
/*
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > res;
        int n= nums.size();
        if(n<4)
            return res;

        sort(nums.begin(), nums.end());

        unordered_multimap<int, pair<int, int> > cache; // use hash_map to cache the sum of 2 nums
        for(int i=0; i+1 < nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                cache.insert(make_pair(nums[i]+nums[j], make_pair(i,j)));
            }
        }

        for(auto i=cache.begin(); i!=cache.end(); i++)
        {
            int x = target - i->first;
            auto range = cache.equal_range(x);
            for(auto j=range.first; j!=range.second; j++)
            {
                auto a = i->second.first;
                auto b = i->second.second;
                auto c = j->second.first;
                auto d = j->second.second;
                if(a!=c && a!=d && b!=c && b!=d)
                {
                    vector<int> vec = {nums[a], nums[b], nums[c], nums[d]};
                    sort(vec.begin(), vec.end());
                    res.push_back(vec);
                }
            }
        }

        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    */
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
    Solution sol;
    vector<int> input = {1, 0, -1, 0, -2, 2};
    auto res = sol.fourSum(input, 0);
    print2DVecotr(res);
    return 0;
}
