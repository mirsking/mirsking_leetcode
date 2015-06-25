#pragma warning(disable:4146)
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
		//if (x == INT_MIN)
		//	return 0;
		long long xx = abs(x);
		long long res_mid = 0;
		int res = 0;
		while (xx != 0)
		{
			res_mid = res_mid * 10 + xx % 10;
			xx = xx / 10;
		}
		if (x < 0)
			res_mid = -res_mid;

		if (res_mid <= INT_MAX && res_mid >= INT_MIN)
			res = res_mid;

		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.reverse(1534236469) << endl;
	//cout << sol.reverse(-2147483648) << endl;
	return 0;
}