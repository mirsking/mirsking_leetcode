#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
		if (x<0)
			return false;
		int base = 1;
		while (x / base > 9)
			base*=10;

		while (x)
		{
			int leftDigit, rightDigit;
			leftDigit = x / base;
			rightDigit = x % 10;
			if (leftDigit != rightDigit)
				return false;

			x -= base*leftDigit;
			base /= 100;
			x /= 10;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	cout << sol.isPalindrome(0);
	return 0;
}