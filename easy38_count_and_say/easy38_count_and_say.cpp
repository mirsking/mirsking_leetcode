#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
		string str = "1";

		while (--n)
		{
			string tmp;
			char last_ch = str[0];
			int count = 1;
			for (int i = 1; i < str.size(); i++)
			{
				char c = str[i];
				if (c == last_ch)
					count++;
				else
				{
					tmp += to_string(count);
					count = 1;
					tmp.push_back(last_ch);
					last_ch = c;

				}
			}
			if (count != 0)
			{
				tmp += to_string(count);
				tmp.push_back(last_ch);
			}
			str = tmp;
		}
		return str;
    }
};

int main()
{
	Solution sol;
	//cout << sol.countAndSay(1) << endl;
	//cout << sol.countAndSay(2) << endl;
	//cout << sol.countAndSay(3) << endl;
	cout << sol.countAndSay(4) << endl;
	cout << sol.countAndSay(5) << endl;
	cout << sol.countAndSay(6) << endl;
	return 0;

}