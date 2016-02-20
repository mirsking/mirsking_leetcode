#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
		vector<string> map(26, "");
		unordered_set<string> dict;
		vector<string> words;
		string2Vector(str, words);
		if (pattern.size() != words.size())
			return false;
		for (int i = 0; i < pattern.size(); i++)
		{
			int idx = pattern[i] - 'a';
			if (map[idx] == "" && dict.find(words[i]) == dict.end())
			{
				map[idx] = words[i];
				dict.insert(words[i]);
			}
			else if (map[idx] != words[i])
				return false;
		}
		return true;
    }
private:
	void string2Vector(string& str, vector<string>& res)
	{
		stringstream ss(str);
		while (ss)
		{
			string tmp;
			ss >> tmp;
			if (tmp != "")
				res.push_back(tmp);
		}
	}
};

int main()
{
	Solution sol;
	cout << (sol.wordPattern("abba", "dog cat cat dog") ? "True" : "False") << endl;
	cout << (sol.wordPattern("abba", "dog cat cat fish") ? "True" : "False") << endl;
	cout << (sol.wordPattern("aaaa", "dog cat cat dog") ? "True" : "False") << endl;
	cout << (sol.wordPattern("abba", "dog dog dog dog") ? "True" : "False") << endl;
	return 0;
}