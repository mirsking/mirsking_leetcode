#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
		int res = num;
		while (res / 10 != 0)
		{
			res = 0;
			while (num!=0)
			{
				res += num % 10;
				num = num / 10;
			}
			num = res;
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.addDigits(38) << endl;
	cout << sol.addDigits(99) << endl;
	cout << sol.addDigits(1) << endl;
	cout << sol.addDigits(100) << endl;
	return 0;
}