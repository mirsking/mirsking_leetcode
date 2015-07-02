#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> dict;
		dict.push_back(" "); 
		dict.push_back(""); dict.push_back("abc"); dict.push_back("def");
		dict.push_back("ghi"); dict.push_back("jkl"); dict.push_back("mno");
		dict.push_back("pqrs"); dict.push_back("tuv"); dict.push_back("wxyz");

		vector<string> res;
		for (int i = 0; i < digits.size(); i++)
		{
			int index = digits[i] - '0';
			if (res.empty())
			{
				for (int j = 0; j < dict[index].size(); j++)
				{
					string tmp;
					tmp.push_back(dict[index][j]);
					res.push_back(tmp);
				}
			}
			else
			{
				vector<string> res_tmp;
				for (auto it = res.begin(); it != res.end();it++)
				{
					string tmp = *it;
					for (int j = 0; j < dict[index].size(); j++)
					{
						string tmp1(tmp);
						tmp1.push_back(dict[index][j]);
						res_tmp.push_back(tmp1);
					}
				}
				if (res_tmp.size() != 0)
				{
					res.clear();
					res.resize(res_tmp.size());
					copy(res_tmp.begin(), res_tmp.end(), res.begin());
				}
			}
		}

		return res;
    }
};

int main()
{
	Solution sol;
	vector<string> res = sol.letterCombinations("02");
	return 0;
}