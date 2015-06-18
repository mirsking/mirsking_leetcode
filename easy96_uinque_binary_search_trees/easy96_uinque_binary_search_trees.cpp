#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numTrees(int n) {
		if (n < 0)
			return 0;
		if (n == 0)
			return 1;

		vector<int> res;
		res.resize(n+1);
		res[0] = res[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				res[i] += res[j] * res[i - j - 1];
			}
		}

		return res[n];
    }

};

int main(int argc, char** argv)
{
	Solution sol;
	cout << sol.numTrees(1) << endl;
	cout << sol.numTrees(2) << endl;
	cout << sol.numTrees(3) << endl;
	cout << sol.numTrees(4) << endl;
	return 0;
}