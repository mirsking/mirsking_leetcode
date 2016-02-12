#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<long long, int> map;
		vector<string> res;
		if (s.size() < 10)
			return res;

		for (int i = 0; i <= s.size() - 10; i++)
		{
			long long mark = encode(s, i);
			if (map.find(mark) != map.end())
				map[mark]++;
			else
				map[mark] = 1;
		}
		for (auto&s : map)
		{
			if (s.second > 1)
				res.push_back(decode(s.first));
		}
		return res;
    }
private:
	static inline int getVal(char& ch)
	{
		switch (ch)
		{
		case 'A':return 1;
		case 'C':return 2;
		case 'G':return 3;
		case 'T':return 4;
		}
	}
	static inline char getChar(int val)
	{
		switch (val)
		{
		case 1:return 'A';
		case 2:return 'C';
		case 3:return 'G';
		case 4:return 'T';
		}
	}
	static inline long long encode(string& s, int left)
	{
		long long res = 0;
		for (int i = 0; i < 10; i++)
		{
			int val = getVal(s[left + i]);
			res = res * 10 + val;
		}
		return res;
	}
	static inline string decode(long long val)
	{
		string res;
		int d = 0;
		do{
			d = val % 10;
			res.push_back( getChar(d));
			val = val / 10;
		} while (val);

		return string(res.rbegin(), res.rend());
	}
};

int main()
{
	Solution sol;
	//vector<string> res = sol.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	vector<string> res = sol.findRepeatedDnaSequences("AAGATCCGTCCCCCCAAGATCCGTC");
	for (auto& s : res)
	{
		cout << s << endl;
	}
	return 0;
}