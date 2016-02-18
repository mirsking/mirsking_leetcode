#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
	//(a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
    int countDigitOne(int n) {
		int ones = 0;
		for (long m = 1; m <= n; m *= 10)
		{
			long a = n / m, b = n%m;
			ones += (a + 8) / 10 * m;
			if (a % 10 == 1)
				ones += b + 1;
		}
		return ones;

		int res = 0;
		for (long k = 1; k <= n; k *= 10) {
            long r = n / k, m = n % k;
            res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
		return res;
    }
};
*/

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long k = 1; k <= n; k *= 10) {
            long r = n / k, m = n % k;
            res += (r + 8) / 10 * k + (r % 10 == 1 ? m + 1 : 0);
        }
        return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.countDigitOne(1410065408);
	return 0;
}