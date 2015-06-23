#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;

		vector< vector<char> > ch_v;
		ch_v.resize(numRows);
		int div = 2 * (numRows - 1);
		for (int i = 0; i < s.size(); i++)
		{
			int index = i%div;
			index = index >= numRows ? div - index : index;
			ch_v[index].push_back(s[i]);
		}

		string res;
		for (int i = 0; i < numRows; i++)
		{
			auto& str = ch_v[i];
			for (int j = 0; j < str.size(); j++)
				res.push_back(str[j]);
		}

		return res;
    }
};

int main()
{
	string a = "PAYPALISHIRING";
	Solution sol;
	cout <<	sol.convert("PAYPALISHIRING", 4);
	return 0;
}