#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		int res = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (citations[i] >= n - i)
				res = n - i;
		}
		return res;
    }
};


int main()
{
	vector<int> input = { 0, 1, 3, 5, 6 };
	Solution sol;
	cout << sol.hIndex(input) << endl;
	return 0;
}