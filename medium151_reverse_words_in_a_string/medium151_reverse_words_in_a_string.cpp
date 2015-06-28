#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
		istringstream ss(s);
		vector<string> vs;

		while (ss)
		{
			string tmp;
			ss >> tmp;
			cout << tmp << ";";
			vs.push_back(tmp);
		}

		s.resize(0);
		for (int i = vs.size() - 1; i >= 0; i--)
		{
			if (vs[i] != "")
			{
				s += vs[i];
				if (i != 0)
					s += " ";
			}
		}
    }
};

int main()
{
	string s = "the sky is blue";
	Solution sol;
	sol.reverseWords(s);
	cout << s;
	return 0;
}