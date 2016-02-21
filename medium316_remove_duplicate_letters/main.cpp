#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
		unordered_map<char, int> count;
		stack<char> sta;
		unordered_set<char> sta_sets;
		for (int i = 0; i < s.size(); i++)
			count[s[i]]++;

		for (auto& ch : s)
		{
			if (sta_sets.find(ch) != sta_sets.end())
				count[ch]--;
			else
			{
				while (!sta.empty() && sta.top() > ch && count[sta.top()] > 1)
				{
					count[sta.top()]--;
					sta_sets.erase(sta.top());
					sta.pop();
				}
				sta.push(ch);
				sta_sets.insert(ch);
			}
		}
		string res;
		while (!sta.empty())
		{
			res.insert(res.begin(), sta.top());
			sta.pop();
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.removeDuplicateLetters("bcabc") << endl;
	cout << sol.removeDuplicateLetters("cbacdcbc") << endl;
	return 0;
}