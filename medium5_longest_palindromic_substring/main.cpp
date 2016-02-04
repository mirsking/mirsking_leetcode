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

		int start = 0; int max_len = 0;
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < j; i++)
			{
				if (j == i + 1)
					dp[i][j] = (s[j] == s[i]);
				else//j > i+1
					dp[i][j] = dp[i + 1][j - 1] && (s[j] == s[i]);
				if (dp[i][j] && j-i+1 > max_len)
				{
					max_len = j - i + 1;
					start = i;
				}
			}
		}
		return s.substr(start, max_len);
	}
};

int main()
{
	Solution sol;
	cout << sol.longestPalindrome("aa") << endl;
	cout << sol.longestPalindrome("abcdefedcba") << endl;
	return 0;
}
