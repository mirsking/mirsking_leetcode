#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
		int last_flag = -1;
		stack<int> flags;
		for (auto& ch : s)
		{
			switch (ch)
			{
			case '(':
				if (last_flag != -1)
					flags.push(last_flag);
				last_flag = s_left;
				break;
			case ')':
				if (last_flag == s_left)
				{
					if (flags.empty())
						last_flag = -1;
					else
					{
						last_flag = flags.top();
						flags.pop();
					}
				}
				else
					return false;
				break;

			case '[':
				if (last_flag != -1)
					flags.push(last_flag);
				last_flag = m_left;
				break;
			case ']':
				if (last_flag == m_left)
				{
					if (flags.empty())
						last_flag = -1;
					else
					{
						last_flag = flags.top();
						flags.pop();
					}
				}
				else
					return false;
				break;

			case '{':
				if (last_flag != -1)
					flags.push(last_flag);
				last_flag = l_left;
				break;
			case '}':
				if (last_flag == l_left)
				{
					if (flags.empty())
						last_flag = -1;
					else
					{
						last_flag = flags.top();
						flags.pop();
					}
				}
				else
					return false;
				break;
	

			}
		}
		if (last_flag == -1)
			return true;
		else
			return false;
    }

private:
	enum
	{
		s_left,
		s_right,
		m_left,
		m_right,
		l_left,
		l_right
	};
};


int main()
{
	Solution sol;
	cout << sol.isValid("([]){}");
	cout << sol.isValid(")[]{}");
	cout << sol.isValid("([)]{}");
	cout << sol.isValid("()[{]}");
	return 0;
}