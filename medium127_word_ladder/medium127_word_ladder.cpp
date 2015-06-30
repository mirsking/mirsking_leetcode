#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		queue<string> ladder;
		ladder.push(beginWord);
		wordDict.erase(beginWord);
		int count = 1;
		int level = 1;
		while (!ladder.empty())
		{
			string curWord = ladder.front();
			ladder.pop();
			count--;
			for (int i = 0; i < curWord.size(); i++)
			{
				string tmp = curWord;
				for (int j = 'a'; j <= 'z'; j++)
				{
					if (tmp[i] == j) continue;
					tmp[i] = j;
					if (tmp == endWord)
						return level+1;
					if (wordDict.find(tmp) != wordDict.end())
						ladder.push(tmp);
					wordDict.erase(tmp);
				}
			}
			if (count == 0)
			{
				count = ladder.size();
				level++;
			}

		}
		return 0;
    }
};

int main()
{
	const int N = 5;
	string a[N] = {"hot","dot","dog","lot","log"};
	//const int N = 2;
	//string a[N] = { "hot", "dog" };
	unordered_set<string> dict;
	for (int i = 0; i < N; i++)
	{
		dict.insert(a[i]);
	}
	Solution sol;
	cout << sol.ladderLength("hit", "cog", dict);
	return 0;
}