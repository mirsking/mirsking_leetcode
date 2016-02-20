#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
		sort(citations.rbegin(), citations.rend());
		int res = 0;
		for (int i = 0; i < citations.size(); i++)
		{
			if (citations[i] >= i + 1)
				res = i + 1;
			else
				break;
		}
		return res;
    }
};

int main()
{
	vector<int> input = { 2,0,6,1,5 };
	Solution sol;
	cout << sol.hIndex(input) << endl;
	return 0;
}