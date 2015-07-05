#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
		string res = "";
		if (n <= 0)
			return res;
		
		n = n - 1;
		while (n >= 0)
		{
			char tmp = n % 26 + 'A';
			res.insert(res.begin(), tmp);
			n = n / 26 - 1;
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.convertToTitle(1) << endl;
	cout << sol.convertToTitle(2) << endl;
	cout << sol.convertToTitle(26) << endl;
	cout << sol.convertToTitle(28) << endl;
	return 0;
}