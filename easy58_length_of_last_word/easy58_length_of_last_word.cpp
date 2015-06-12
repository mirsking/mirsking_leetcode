#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
		if (s.size() == 0)
			return 0;

		auto iter = find(s.rbegin(), s.rend(), ' ');
		if (iter == s.rbegin())
			return lengthOfLastWord(s.substr(0, s.size() - 1));

		return iter - s.rbegin();

    }
};

int main(int argc, char** argv)
{
	Solution sol;
	string s = "Hello World haha";
	cout << sol.lengthOfLastWord(s);
	return 0;
}