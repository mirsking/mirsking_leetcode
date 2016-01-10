#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
        {
            res.push_back(nums);
        }
        return res;
    }
private:
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last)
    {
        //Get a reversed range to simplify reversed traversal
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);

        //Begin from the second last element to the first element
        auto pivot=next(rfirst);
        // Find 'pivot' which is the first element that is no less than its successor.
        // 'Prev' is used since 'pivot' is a 'reversed_iterator'
        while(pivot!=rlast && *pivot >= *prev(pivot))
            pivot++;

        //No such element found, current sequence is already the largest permutation,
        //then the rearrage to the first permutation and return false
        if(pivot == rlast)
        {
            reverse(rfirst, rlast);
            return false;
        }

        // Scan from right to left, find the first element that is greator than 'pivot'
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

        swap(*change, *pivot);
        reverse(rfirst, pivot);

        return true;
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
    int tmp[] = {1,1,2};
    vector<int> input(tmp, tmp+3);
    Solution sol;
    vector<vector<int> > res = sol.permuteUnique(input);
    print2DVecotr(res);
    return 0;
}
