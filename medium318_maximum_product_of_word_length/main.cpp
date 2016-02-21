#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//因为全部都是小写的字母，用int 就可以存储每一位的信息。这就是位运算
//elements[i] |= 1 << (words[i][j] – ‘a’);   //把words[i][j] 在26字母中的出现的次序变为1
//elements[i] & elements[j]    // 判断是否有交集只需要两个数 按位 与 （AND）运算即可

class Solution {
public:
    int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<int> elements(n);
		for (int i = 0; i < n; i++)
		{
			for (auto&c : words[i])
				elements[i] |= 1 << (c - 'a');
		}

		size_t max_length = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (!(elements[i] & elements[j]))
					max_length = max(max_length, words[i].length() * words[j].length());
			}
		}
		return max_length;
    }
};

int main()
{
	vector<string> input = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	Solution sol;
	cout << sol.maxProduct(input) << endl;
	return 0;
}