#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    //康托编码
    string getPermutation(int n, int k)
    {
        int total = factorial(n);
        k = (k-1)%total;
        string candidates = string("123456789").substr(0,n);
        string res(n, ' ');
        for(int i=0; i<n; i++)
        {
            total /= (n-i);
            int index = k/total;
            res[i] = candidates[index];
            candidates.erase(index, 1);
            k = k%total;
        }
        return res;
    }

private:
    int factorial(int n)
    {
        int res = 1;
        while(n)
        {
           res *=n;
           n--;
        }
        return res;
    }

    /*
     * next_permutation : TLE
    string getPermutation(int n, int k) {
        string str;
        for(int i=1; i<=n; i++)
            str.push_back('0'+i);
        vector<string> permutations;
        getPermutaions(str, permutations);
        int num = permutations.size();
        k = (k-1)%num;
        return permutations[k];
    }
private:
    void getPermutaions(string str, vector<string>& res)
    {
        res.push_back(str);
        while(next_permutation(str.begin(), str.end()))
            res.push_back(str);
    }
    */
};

int main()
{
    Solution sol;
    cout << sol.getPermutation(3, 1) << endl;
    cout << sol.getPermutation(3, 2) << endl;
    cout << sol.getPermutation(3, 6) << endl;
    cout << sol.getPermutation(3, 7) << endl;
    cout << sol.getPermutation(3, 8) << endl;
    return 0;
}
