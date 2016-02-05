#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
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