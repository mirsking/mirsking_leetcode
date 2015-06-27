#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int res = (C - A)*(D - B) + (G - E)*(H - F);
		int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
		if (B1 > D1 || A1 > C1)
			;
		else
			res -= (C1 - A1)*(D1 - B1);
		return res;
    }

};

int main()
{
	Solution sol;
	cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
	return 0;
}