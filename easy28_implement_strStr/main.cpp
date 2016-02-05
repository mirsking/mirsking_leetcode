#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		return kmp(haystack.c_str(), needle.c_str());
	}
private:
	
	static void computePrefix(const char *pattern, int next[])
	{
		int i;
		int j = -1;
		const int m = strlen(pattern);

		next[0] = j;
		for (i = 1; i < m; i++)
		{
			while (j > -1 && pattern[j + 1] != pattern[i])
				j = next[j];

			if (pattern[i] == pattern[j + 1])
				j++;
			next[i] = j;
		}
	}

	static int kmp(const char *text, const char *pattern)
	{
		int i;
		int j = -1;
		const int n = strlen(text);
		const int m = strlen(pattern);
		if (m == 0) return 0; //for the case pattern = ""

		int *next = new int[m];
		computePrefix(pattern, next);
		for (i = 0; i < n; i++) {
			while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
			if (text[i] == pattern[j + 1]) j++;
			if (j == m - 1) {
				delete next;
				return i - j;
			}
		}
		delete next;
		return -1;
	}


	/* Brute Force Algorithm
	int strStr(string haystack, string needle) {
		int n = haystack.size();
		int m = needle.size();

		if (m == 0) // for case needle=""
			return 0;

		for (int i = 0; i < n; i++)
		{
			bool found = true;
			int h = i, k = 0;
			while (h < i + n && k < m)
			{
				found &= (haystack[h++] == needle[k++]);
				if (!found)
					break;
			}
			if (found)
				return i;
		}
		return -1;
	}
	*/
};

int main()
{
	Solution sol;
	cout << sol.strStr("abc", "e") << endl;
	cout << sol.strStr("", "") << endl;
	cout << sol.strStr("abc", "ab") << endl;
	cout << sol.strStr("abc", "de") << endl;
	cout << sol.strStr("a", "a") << endl;
	cout << sol.strStr("abcdef", "cde") << endl;
	return 0;
}