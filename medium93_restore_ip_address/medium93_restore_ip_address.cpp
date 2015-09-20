#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> rres;
		string res;
		restoreIpAddresses(s, 0, res, rres);
		return rres;
    }
private:
	void restoreIpAddresses(string s, int index, string res, vector<string>& rres)
	{
		if (s.size() > (4 - index) * 3)
		{
			return;
		}

		if (s.size() < 4 - index)
		{
			return;
		}

		if (s.size() == 0)
		{
			res.pop_back();// pop .
			rres.push_back(res);
			return;
		}

		int tmp = 0;
		for (int i = 0; i < 3 && i<s.size(); i++)
		{
			tmp = tmp * 10 + s[i] - '0';
			if (tmp > 255 || (i>0 && tmp == s[i]-'0'))// 010010 avoid 0.1.001.0
			{
				return;
			}
			else
			{
				restoreIpAddresses(s.substr(i + 1, s.size() - i - 1), index + 1, res + to_string(tmp)+ ".", rres);
			}
		}
	}

};


int main()
{
	Solution sol;
	vector<string> res = sol.restoreIpAddresses("010010");
	return 0;
}