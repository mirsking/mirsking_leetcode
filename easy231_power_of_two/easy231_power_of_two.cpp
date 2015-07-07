#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n == 1)
			return true;
		unordered_set<int> powers;
		powers.insert(1);
		while (n != 0)
		{
			int power = 2;
			if (n%power == 0)
			{
				n = n / power;
				if (powers.find(n) != powers.end())
					return true;
				else
					powers.insert(power);
			}
			else
				return false;

			power *= 2;
		}
		return false;
    }
};

int main()
{
	Solution sol;
	cout << boolalpha << sol.isPowerOfTwo(1) << endl;
	cout << boolalpha << sol.isPowerOfTwo(2) << endl;
	cout << boolalpha << sol.isPowerOfTwo(4) << endl;
	cout << boolalpha << sol.isPowerOfTwo(8) << endl;
	cout << boolalpha << sol.isPowerOfTwo(64) << endl;
	cout << boolalpha << sol.isPowerOfTwo(100) << endl;
	return 0;
}