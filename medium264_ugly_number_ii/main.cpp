#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> ugly_numbers(n);
		ugly_numbers[0] = 1;
		int idx2 = 0, idx3 = 0, idx5 = 0;
		int count = 1;
		while (count < n)
		{
			int next_ugly = min(
				ugly_numbers[idx2] * 2,
				min(ugly_numbers[idx3] * 3,
				ugly_numbers[idx5] * 5)
				);
			if (next_ugly == ugly_numbers[idx2] * 2)
				idx2++;
			if (next_ugly == ugly_numbers[idx3] * 3)
				idx3++;
			if (next_ugly == ugly_numbers[idx5] * 5)
				idx5++;
			ugly_numbers[count] = next_ugly;
			count++;
		}
		return ugly_numbers[n - 1];
	}
};

int main()
{
	Solution sol;
	cout << sol.nthUglyNumber(10) << endl;
	return 0 ;
}