#include <iostream>
using namespace  std;

class Solution {
public:
    int mySqrt(int x) {
		if (x == 1)
			return 1;
		int L = 0, R = x;
		int M=0;
		int LastM = -1;
		while (1)
		{
			LastM = M;
			M = (L + R) / 2;
			//cout << M << endl;
			if (LastM == M)
				break;
			if ((long long)M*(long long)M > x)
				R = M - 1;
			else if ((long long)M*(long long)M < x)
				L = M + 1;
		}

		return M;
    }
};

int main()
{
	Solution sol;
	cout << sol.mySqrt(1) << endl;
	return 0;
}