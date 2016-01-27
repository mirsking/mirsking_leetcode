#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> set_indexs;
        vector<multiset<string> > sets;
        for(int i=0; i<strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            auto it = set_indexs.find(tmp);
            if(it == set_indexs.end())
            {
                sets.resize(sets.size()+1);
                int idx = sets.size() - 1;
                set_indexs[tmp] = idx;
                sets[idx].insert(strs[i]);
            }
            else
            {
                int idx = it->second;
                sets[idx].insert(strs[i]);
            }
        }

        vector<vector<string> > res;
        res.resize(sets.size());
        for(int i=0; i<sets.size(); i++)
        {
            res[i] = vector<string>(sets[i].begin(), sets[i].end());
        }
        return res;
    }
};

int main()
{

    vector<string> input = {"eat", "eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string> > res = sol.groupAnagrams(input);

    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
