#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s) {
		stack<char> op_sta;
		stack<int> num_sta;

		int last_num = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char ch = s[i];
			switch (ch)
			{
			case ' ':
				break;
			case '+':
			case '-':
				num_sta.push(last_num);
				last_num = 0;
				while (!op_sta.empty())
					calculateOne(op_sta, num_sta);
				op_sta.push(ch);
				break;
			case '*':
			case '/':
					num_sta.push(last_num);
					last_num = 0;

					while (!op_sta.empty() && (op_sta.top() == '*' || op_sta.top()=='/'))
						calculateOne(op_sta, num_sta);
					op_sta.push(ch);
					break;
			default:
				last_num = last_num * 10 + ch - '0';
				break;
			}
		}
		num_sta.push(last_num);
		last_num = 0;

		while (!op_sta.empty())
		{
			calculateOne(op_sta, num_sta);
		}

		return num_sta.top();
    }

private:
	void calculateOne(stack<char>& op_sta, stack<int>& num_sta)
	{
		if (op_sta.empty() || num_sta.size() < 2)
			return;

		int b = num_sta.top();
		num_sta.pop();
		int a = num_sta.top();
		num_sta.pop();
		int c;

		char ch = op_sta.top();
		op_sta.pop();
		switch (ch)
		{
		case '*':
			c = a * b;
			break;
		case '/':
			c = a / b;
			break;
		case '+':
			c = a + b;
			break;
		case '-':
			c = a - b;
			break;
		}

		num_sta.push(c);
	}
};


int main()
{
	Solution sol;
	cout << sol.calculate("100000000/1/2/3/4/5/6/7/8/9/10");
	return 0;
}