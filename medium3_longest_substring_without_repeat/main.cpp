#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
假设子串里含有重复字符，则父串一定含有重复字符： 单个子问题就可以决定父问题，所以可以用贪心算法。
贪心和动规的区别是：动规里单个子问题只能影响父问题，而不能决定父问题

解题方法：从左往右扫描，当遇到重复字符时，以上一个重复字符的index+1，作为新的搜索位置，直到搜索到最优一个字符，
时间复杂度： O(n)
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ASCII_MAX = 255;
		vector<int> last(ASCII_MAX, -1); // 存储字符最初一次出现的位置

		int start = 0;
		int max_len = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (last[s[i]]>=start)// == means "bb"
			{
				max_len = max(max_len, i - start);
				start = last[s[i]] + 1;
			}
			last[s[i]] = i;
		}

		max_len = max(int(s.size() - start), max_len);
		return max_len;
	}
};

int main()
{
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << sol.lengthOfLongestSubstring("bb") << endl;
	cout << sol.lengthOfLongestSubstring("abcde") << endl;
	cout << sol.lengthOfLongestSubstring("abcdea") << endl;
	return 0;
}