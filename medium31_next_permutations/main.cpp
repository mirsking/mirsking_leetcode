#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         nextPermutation(nums.begin(), nums.end());
    }
private:
    template <class BidiIt>
    bool nextPermutation(BidiIt first, BidiIt last)
    {
        //get the reverse iterator
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);

        //from the secound last element to find the pivot to break the increase order
        auto pivot = next(rfirst);
        while(pivot!=rlast && *pivot >= *prev(pivot))
            pivot++;

        // if pivot is the first element, means no next_permutation
        if(pivot==rlast)
        {
            reverse(first, last);
            return false;
        }

        //find the change point
        //NOTICE NOTICE NOTICE here rfist to pivot is import
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        //bind1st This function constructs an unary function object from the binary function object op by binding its first parameter to the fixed value x.

        swap(*change, *pivot);

        //NOTICE NOTICE NOTICE here rfist to pivot is import
        reverse(rfirst, pivot);

        return true;
    }
};

void print1DVector(vector<int> &input)
{
    for(auto& i:input)
        cout << i << " ";
    cout << endl;
}

int main()
{
    int tmp[] = {1,2,3};
    vector<int> input(tmp, tmp+sizeof(tmp)/sizeof(int));
    Solution sol;
    print1DVector(input);
    for(int i=0;i<6; i++)
    {
        sol.nextPermutation(input);
        print1DVector(input);
    }

    return 0;
}
