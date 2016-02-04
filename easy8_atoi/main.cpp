#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int n = str.size();
		
		int sign = 1;
		int res = 0;
		int i = 0;
		while (i < n && str[i] == ' ')
			i++;
		switch (str[i])
		{
		case '+':i++; break;
		case '-':sign = -1; i++; break;
		}
		for (; i < n; i++)
		{
			if (str[i]<'0' || str[i] > '9')
				break;
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0')>INT_MAX % 10))
				return sign == -1 ? INT_MIN : INT_MAX;
			res = res * 10 + str[i] - '0';
		}
		return res*sign;
	}
};

int main()
{
	Solution sol;
	cout << sol.myAtoi("123") << endl;
	cout << sol.myAtoi("+-123") << endl;
	cout << sol.myAtoi("-123") << endl;
	return 0;
}
