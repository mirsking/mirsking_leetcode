#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int offset = 0;
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			offset++;
		}
		return m << offset;
    }
};

int main()
{
	Solution sol;
	cout << sol.rangeBitwiseAnd(5, 7);
	return 0;
}