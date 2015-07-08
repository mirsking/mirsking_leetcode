#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int res = m;
		for (int i = m + 1; i <= n; i++ )
		{
			res &= i;
		}
		return res;
    }
};

int main()
{
	Solution sol;
	cout << sol.rangeBitwiseAnd(5, 7);
	return 0;
}