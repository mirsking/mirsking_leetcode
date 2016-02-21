#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
		return  n > 0 && static_cast<int>(pow(3, static_cast<int>(log(INT_MAX) / log(3)))) % n == 0;
    }
};

int main()
{
	Solution sol;
	cout << (sol.isPowerOfThree(27) ? "True" : "False") << endl;
	cout << (sol.isPowerOfThree(28) ? "True" : "False") << endl;
	cout << (sol.isPowerOfThree(25) ? "True" : "False") << endl;
	return 0;
}