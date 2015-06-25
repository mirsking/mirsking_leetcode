#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		if (wordDict.find(s) != wordDict.end())
			return true;

		for (int i = 1; i < s.size(); i++)
		{
			string tmp1(s, 0, i), tmp2(s,i,s.size()-i);
			if (wordDict.find(tmp1) != wordDict.end()
				&& wordBreak(tmp2, wordDict))
				return true;
		}
		return false;
    }

private:
	/* ÎÞÏÞ·Ö¸î*/
	bool wordBreak(string s, int begin, int end, unordered_set<string>& wordDict)
	{
		if (end <= begin)
			return false;
		string tmp(s, begin, end-begin);
		if (wordDict.find(tmp) != wordDict.end())
			return true;
		
		for (int i = begin + 1; i < end; i++)
		{
			if (wordBreak(s, begin, i, wordDict) && wordBreak(s, i + 1, end, wordDict))
				return true;
		}
		return false;
	}
};

int main()
{
	string s = "abcd";
	unordered_set<string> wordDict;
	wordDict.insert("a");
	wordDict.insert("b");
	wordDict.insert("cd");
	Solution sol;
	cout << sol.wordBreak(s, wordDict);
	return 0;
}