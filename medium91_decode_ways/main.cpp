#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if (s.size() < 2)
		{
			if (s.size()==1 && isValid(s[0]))
				return 1;
			else 
				return 0;
		}
		const int m = s.size();
		int *dp = new int[m+1];

		dp[0] = 1;
		if (isValid(s[0]))
			dp[1] = 1;
		else
			dp[1] = 0;

		for (int i = 1; i < m; i++)
		{
			//s[i-1] and s[i]
			int val1 = dp[i - 1] * (isValid(s[i - 1], s[i]) ? 1 : 0);

			// s[i]
			int val2 = dp[i] * (isValid(s[i]) ? 1 : 0);
			dp[i + 1] = val1 + val2;
		}

		int res = dp[m];
		delete[] dp;
		return res;
    }
private:
	static inline bool isValid(const char& a, const char& b)
	{
		switch (a)
		{
		case '1': return '0' <= b && b <= '9'; break;
		case '2': return '0' <= b && b <= '6'; break;
		}
		return false;
	}
	static inline bool isValid(const char& a)
	{
		return '1' <= a && a <= '9';
	}
};
int main()
{
	Solution sol;
	cout << sol.numDecodings("0") << endl;
	cout << sol.numDecodings("01") << endl;
	cout << sol.numDecodings("10") << endl;
	cout << sol.numDecodings("12") << endl;
	cout << sol.numDecodings("1222") << endl;
	return 0;
}