#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 余数开始循环的时候就是商开始循环的时候
	// http://blog.csdn.net/u012162613/article/details/41998617
    string fractionToDecimal(int numerator, int denominator) {
		if (numerator == 0)
			return "0";
		string res;
		if (numerator > 0 ^ denominator > 0) res.push_back('-');
		long long n = numerator, d = denominator;
		n = abs(n); d = abs(d);
		res += to_string(n / d);
		long long r = n%d;
		if (r == 0)
			return res;
		else
			res.push_back('.');
		unordered_map<int, int> map;
		while (r)
		{
			if (map.find(r) != map.end())
			{
				res.insert(map[r], 1, '(');
				res.push_back(')');
				break;
			}

			map[r] = res.size();
			r *= 10;
			res += to_string(r / d);
			r = r%d;
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.fractionToDecimal(1, 2) << endl;
	cout << sol.fractionToDecimal(1, 3) << endl;
	cout << sol.fractionToDecimal(2, 1) << endl;
	cout << sol.fractionToDecimal(111, 11) << endl;
	cout << sol.fractionToDecimal(1, 11) << endl;
	cout << sol.fractionToDecimal(0, 3) << endl;
	return 0;
}