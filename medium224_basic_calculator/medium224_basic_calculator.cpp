#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		int res = 0;
		vector<int> sign;
		sign.push_back(1);

		char last_op = '+';
		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			switch (ch)
			{
			case ' ':
				break;
			case '+':
			case '-':
				last_op = ch;
				break;
			case '(':
				//enter a new sign contex
				sign.push_back(sign.back()*(last_op == '-' ? -1 : 1));
				last_op = '+';
				break;
			case ')':
				//exit a sign contex
				sign.pop_back();
				break;
			default:
				int num = 0;
				while (i < s.size() && isdigit(s[i])){
					num = num * 10 + s[i] - '0';
					i++;
				}
				i--;
				res += (last_op == '-' ? -1 : 1)*sign.back()*num;
				break;
			}
		}
		return res;
	}
};

int main()
{
	Solution sol;
	cout << sol.calculate("(45+(4+5+2)-3)+(6+8)") << endl;
	return 0;
}