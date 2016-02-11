#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//贪心算法
//低进高出，把所有正的价格差全部加起来
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int sum = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			int diff = prices[i] - prices[i - 1];
			if (diff > 0)
				sum += diff;
		}
		return sum;
    }
};


int main()
{
	vector<int> input = {1,2,5,1,5,7,1};
	Solution sol;
	cout << sol.maxProfit(input) << endl;
	return 0;
}