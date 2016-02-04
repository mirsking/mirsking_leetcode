#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/**
�����Ӵ��ﺬ���ظ��ַ����򸸴�һ�������ظ��ַ��� ����������Ϳ��Ծ��������⣬���Կ�����̰���㷨��
̰�ĺͶ���������ǣ������ﵥ��������ֻ��Ӱ�츸���⣬�����ܾ���������

���ⷽ������������ɨ�裬�������ظ��ַ�ʱ������һ���ظ��ַ���index+1����Ϊ�µ�����λ�ã�ֱ������������һ���ַ���
ʱ�临�Ӷȣ� O(n)
*/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ASCII_MAX = 255;
		vector<int> last(ASCII_MAX, -1); // �洢�ַ����һ�γ��ֵ�λ��

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