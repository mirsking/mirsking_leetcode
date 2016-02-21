#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	//https://www.hrwhisper.me/leetcode-verify-preorder-serialization-of-a-binary-tree/
    bool isValidSerialization(string preorder) {
		if (preorder.empty() || preorder == "#")
			return true;
		stack<string> sta;
		int index = 0;
		string node = getNext(preorder, index, index);
		while (node != "")
		{
			if (node == "#")
			{
				if (!sta.empty())
				{
					while (!sta.empty() && sta.top() == "#")
					{
						sta.pop();
						if (sta.empty())
							return false;
						sta.pop();
					}
					sta.push("#");
				}
			}
			else
			{
				sta.push(node);
			}
			node = getNext(preorder, index, index);
		}

		return sta.size() == 1 && sta.top() == "#";

    }
private:
	string getNext(string& str, int start, int& next)
	{
		string res;
		if (start >= str.size())
			return "";
		else
		{
			while (start < str.size() && str[start] != ',')
			{
				res.push_back(str[start]);
				start++;
			}
			next = start + 1;
			return res;
		}
	}
};

int main()
{
	Solution sol;
	//cout << (sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") ? "True" : "False") << endl;
	//cout << (sol.isValidSerialization("1,#,#,#,#") ? "True" : "False") << endl;
	cout << (sol.isValidSerialization("#") ? "True" : "False") << endl;
	return 0;
}