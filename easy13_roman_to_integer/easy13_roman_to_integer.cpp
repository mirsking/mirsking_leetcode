#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		roman_int_v.resize(26);
		roman_int_v['I' - 'A'] = 1;
		roman_int_v['V' - 'A'] = 5;
		roman_int_v['X' - 'A'] = 10;
		roman_int_v['L' - 'A'] = 50;
		roman_int_v['C' - 'A'] = 100;
		roman_int_v['D' - 'A'] = 500;
		roman_int_v['M' - 'A'] = 1000;

		if (s.size() == 0)
			return 0;
		else if (s.size() == 1)
			return roman_int_v[s[0] - 'A'];

		int return_val = 0;
		for (int i = 0; i < s.size()-1; i++)
		{
			int& a = roman_int_v[s[i] - 'A'];
			int& b = roman_int_v[s[i+1] - 'A'];
			if (a < b)
				return_val -= a;
			else
				return_val += a;
		}
		return_val += roman_int_v[s[s.size()-1] - 'A'];
		return return_val;
    }

private:
	vector<int> roman_int_v;

};


int main(int argc, char** argv)
{
	string s = "MCMLIV";
	
	Solution sol;
	cout << sol.romanToInt(s);
	return 0;
}