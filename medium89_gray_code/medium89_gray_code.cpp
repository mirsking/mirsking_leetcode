#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
		int N = 1 << n;
		vector<int> res;
		res.resize(N);
		for (int i = 0; i < N; i++)
		{
			int code = i^i >> 1;
			res[i] = code;
		}

		return res;
    }
};


int main()
{
	Solution sol;
	vector<int> res = sol.grayCode(2);
	return 0;
}