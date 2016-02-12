#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		if (tokens.empty())
			return 0;

		stack<int> sta;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i].size()==1)
			{
				switch (tokens[i][0])
				{
				case'+':{
					int v1 = sta.top(); sta.pop();
					int v2 = sta.top(); sta.pop();
					int val = v1 + v2;
					sta.push(val);
					break;
				}
				case '-':{
					int v1 = sta.top(); sta.pop();
					int v2 = sta.top(); sta.pop();
					int val = v2 - v1;
					sta.push(val);
					break;
				}
				case '*':{
					int v1 = sta.top(); sta.pop();
					int v2 = sta.top(); sta.pop();
					int val = v1 * v2;
					sta.push(val);
					break;
				}
				case '/':{
					int v1 = sta.top(); sta.pop();
					int v2 = sta.top(); sta.pop();
					int val = v2 / v1;
					sta.push(val);
					break;
				}
				default:
				{
					int val = stoi(tokens[i]);
					sta.push(val);
					break;
				}
				}
			}
			else
			{
				int val = stoi(tokens[i]);
				sta.push(val);
			}
		}
		if (sta.empty())
			return 0;
		else
			return sta.top();
    }
};

int main()
{
	vector<string> input = {"-1","1","*","-1","+"};
	Solution sol;
	cout << sol.evalRPN(input)<< endl;
	return 0;
}