#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp
class Solution {
public:
	string longestPalindrome(string s) {
		int N = s.size();
		vector<vector<bool> > dp(N, vector<bool>(N, false));
		for (int i = 0; i < N; i++)
			dp[i][i] = true;

		string str;
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < j; i++)
			{
				if (j == i + 1)
					dp[i][j] = (s[j] == s[i]);
				else//j > i+1
					dp[i][j] = dp[i + 1][j - 1] && (s[j] == s[i]);
				if (dp[i][j] && j-i+1 > str.size())
				{
					str = s.substr(i, j - i + 1);
				}
			}
		}
		return str;
	}
};

int main()
{
	Solution sol;
	cout << sol.longestPalindrome("aa") << endl;
	cout << sol.longestPalindrome("abcdefedcba") << endl;
	return 0;
}
