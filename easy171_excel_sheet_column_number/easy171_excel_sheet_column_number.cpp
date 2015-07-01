#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int res = 0;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			res = res * 26 + (*it - 'A'+1);
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.titleToNumber("A") << endl;
	cout << sol.titleToNumber("Z") << endl;
	cout << sol.titleToNumber("AB") << endl;
	cout << sol.titleToNumber("AAA") << endl;
	return 0;
	
}