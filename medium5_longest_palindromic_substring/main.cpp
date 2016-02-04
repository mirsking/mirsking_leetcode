#pragma warning(disable:4996)
//#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//dp
class Solution {
public:
	string longestPalindrome(string s) {
		const int N = s.size();
		//vector<vector<bool> > dp(N, vector<bool>(N, false));
#ifdef WIN32
		bool **dp;
		dp = new bool*[N];
		for(int i=0; i<N; i++)
		{
			dp[i] = new bool[N];
			memset(dp[i], 0, N);
		}
#else
		bool dp[N][N];
		fill_n(&dp[0][0], N*N, false);
#endif

		for (int i = 0; i < N; i++)
			dp[i][i] = true;

		int start = 0; int max_len = 1; // notice: min_len is 1 not 0
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
#ifdef WIN32
		for (int i = 0; i < N; i++)
			delete[] dp[i];
		delete[] dp;
#endif
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
