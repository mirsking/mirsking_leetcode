#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
		vector<int> res(num+1);
		res[0] = 0; res[1] = 1;
		int pivot = 2;
		for (int i = 2; i <= num; i++)
		{
			if (i / pivot == 2)
			{
				res[i] = 1;
				pivot *= 2;
			}
			else
			{
				res[i] = 1 + res[i%pivot];
			}
		}
		return res;
    }
};


int main()
{
	Solution sol;
	auto val = sol.countBits(5);
	for (auto v : val)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}