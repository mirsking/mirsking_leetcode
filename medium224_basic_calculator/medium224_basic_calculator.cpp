#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculate(string s) {
		int index = 0;
		stack<string> sta;
		return calculate(s, 0, sta);
    }

private:
	int calculate(string s, int index, stack<string>& sta) {
		string tmp = "";
		for (int i = index; i < s.size(); i++)
		{
			auto& ch = s[i];
			if (ch == ' ')
				continue;

			if (ch != '+' && ch != '-' && ch != '(' && ch != ')')
			{
				tmp.push_back(ch);
			}
			else if (ch == '+' || ch == '-' || ch=='(')
			{
				sta.push(tmp);
				tmp = "";
				string tmp1;
				tmp1.push_back(ch);
				sta.push(tmp1);
			}
			else if (ch == ')')
			{
				if (tmp != "")
				{
					sta.push(tmp);
					tmp = "";
				}
				auto& ch1 = sta.top();
				stack<string> sta_tmp;
				while (ch1 != "(")
				{
					sta_tmp.push(sta.top());
					sta.pop();
					ch1 = sta.top();
				}
				sta.pop();
				int tmp=0;
				while (!sta_tmp.empty())
				{
					auto& str = sta_tmp.top();
					if (str != "+" && str!="-")
					{
						tmp += stoi(str);
						sta_tmp.pop();
					}
					else if (str == "+")
					{
						sta_tmp.pop();
						tmp += stoi(sta_tmp.top());
						sta_tmp.pop();
					}
					else if (str == "-")
					{
						sta_tmp.pop();
						tmp -= stoi(sta_tmp.top());
						sta_tmp.pop();
					}
				}
				sta.push(to_string(tmp));
			}
		}

		stack<string> sta_tmp;
		while (!sta.empty())
		{
			sta_tmp.push(sta.top());
			sta.pop();
		}
		int res = 0;
		while (!sta_tmp.empty())
		{
			if (sta_tmp.top() == "+")
			{
				sta_tmp.pop();
				res += stoi(sta_tmp.top());
				sta_tmp.pop();
			}
			else if (sta_tmp.top() == "-")
			{
				sta_tmp.pop();
				res -= stoi(sta_tmp.top());
				sta_tmp.pop();
			}
			else
			{
				res += stoi(sta_tmp.top());
				sta_tmp.pop();
			}
		}
		return res;
	}
};

int main()
{
	Solution  sol;
	string a = to_string('+');
	string b = "+";
	cout << sol.calculate("(100+(4+5+2)-3)+(6+8)") << endl;
	return 0;
}