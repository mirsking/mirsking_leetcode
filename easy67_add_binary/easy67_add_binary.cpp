#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		string aa, bb, cc;
		if (a.size() < b.size())
		{
			aa = b; bb = a;
		}
		else
		{
			aa = a; bb = b;
		}
		cc.resize(aa.size());
		int max_size = aa.size(), min_size = bb.size();
		int offset = max_size - min_size;
		int carry = 0;
		for (int i = max_size - 1; i >= 0; i--)
		{
			char tmp;
			if (i - offset>=0)
				tmp = aa[i] + bb[i - offset] + carry - '0';
			else
				tmp = aa[i] + carry;
			if (tmp == '2')
			{
				cc[i] = '0';
				carry = 1;
			}
			else if (tmp == '3')
			{
				cc[i] = '1';
				carry = 1;
			}
			else
			{
				cc[i] = tmp;
				carry = 0;
			}
		}
		if (carry == 1)
			cc = "1" + cc;

		return cc;
    }
};

int main()
{

	Solution sol;
	cout << sol.addBinary("1111", "1111");
	return 0;
}