#include <iostream>
using namespace std;

class Solution {
public:
	/*
    int trailingZeroes(int n) {
		if (n == 0)
			return 0;
		long long tmp = 1;
		int res = 0;
		while (n != 1)
			tmp *= (n--);
		cout << tmp << endl;
		while (tmp % 10 == 0)
		{
			res += 1;
			tmp = tmp / 10;
		}
		return res;
    }
	*/
	int trailingZeroes(int n) {
		//factorial(n);

		int res = 0;
		while (n)
		{
			res += n / 5;
			n /= 5;
		}
		return res;
	}

private:
	long long factorial(int n)
	{
		if (n == 0)
			return 0;
		long long tmp = 1;
		int res = 0;
		while (n != 1)
			tmp *= (n--);
		cout << tmp << endl;
		return tmp;
	}
};

int main()
{
	Solution sol;
	cout << sol.trailingZeroes(2147483647);
	return 0;
}