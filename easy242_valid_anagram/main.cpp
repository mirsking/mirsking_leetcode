#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		unordered_map<char, int> map1, map2;
		calcMap(s, map1);
		calcMap(t, map2);
		for (auto& m : map1)
		{
			if (m.second != map2[m.first])
				return false;
		}
		
		return true;
    }
private:
	void calcMap(string& s, unordered_map<char, int>& map)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (map.find(s[i]) == map.end())
				map[s[i]] = 1;
			else
				map[s[i]]++;
		}
	}
};

int main()
{
	Solution sol;
	cout << (sol.isAnagram("abc", "cab") ? "True" : "False") << endl;
	cout << (sol.isAnagram("abc", "cbe") ? "True" : "False") << endl;
	return 0;
}