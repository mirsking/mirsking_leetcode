#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if (s.size() != t.size())
			return false;

		unordered_map<char, char> st_map, ts_map;

		for (int i = 0; i < s.size(); i++)
		{
			if (st_map.find(s[i]) == st_map.end())
			{
				st_map[s[i]] = t[i];
			}
			else
			{
				if (st_map[s[i]] != t[i])
					return false;
			}

			if (ts_map.find(t[i]) == ts_map.end())
			{
				ts_map[t[i]] = s[i];
			}
			else
			{
				if (ts_map[t[i]] != s[i])
					return false;
			}
		}

		return true;

    }
};


int main(int argc, char** argv)
{
	Solution sol;
	string s = "paper";
	string t = "title";
	bool res = sol.isIsomorphic(s, t);
	return 0;
}