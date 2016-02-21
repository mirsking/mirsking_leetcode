#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//��Ϊȫ������Сд����ĸ����int �Ϳ��Դ洢ÿһλ����Ϣ�������λ����
//elements[i] |= 1 << (words[i][j] �C ��a��);   //��words[i][j] ��26��ĸ�еĳ��ֵĴ����Ϊ1
//elements[i] & elements[j]    // �ж��Ƿ��н���ֻ��Ҫ������ ��λ �� ��AND�����㼴��

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