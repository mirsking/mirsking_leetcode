#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ugly_numbers(n);
		ugly_numbers[0] = 1;
		vector<int> idxs(primes.size(), 0);
		int count = 1;
		while (count < n)
		{
			int next_ugly = INT_MAX;
			int min_next_idx = -1;
			for (int i = 0; i < primes.size(); i++)
			{
				int maybe_next_ugly = ugly_numbers[idxs[i]] * primes[i];
				if (next_ugly > maybe_next_ugly )
				{
					next_ugly = maybe_next_ugly;
					min_next_idx = i;
				}
			}
			if (min_next_idx != -1)
				idxs[min_next_idx]++;
			if (ugly_numbers[count - 1] != next_ugly)
			{
				ugly_numbers[count] = next_ugly;
				count++;
			}
		}
		return ugly_numbers[n - 1];
    }
};

int main()
{
	//vector<int> primes = {2, 7, 13, 19};
	vector<int> primes = { 3, 5, 7, 11, 19, 23, 29, 41, 43, 47 }; 
	Solution sol;
	for (int i = 0; i < 15; i++)
		cout << sol.nthSuperUglyNumber(i+1, primes) << endl;
	return 0;
}