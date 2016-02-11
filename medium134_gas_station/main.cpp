#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int N = gas.size();
		for (int i = 0; i < N; i++)
		{
			int gas_sum = 0;
			for (int j = i; j < i + N; j++)
			{
				int cur = j%N;
				gas_sum = gas_sum + gas[cur] - cost[cur];
				if (gas_sum < 0)
					break;
			}
			if (gas_sum >= 0)
				return i;
		}
		return -1;
	}
};

int main()
{
	vector<int> gas = {2,3};
	vector<int> cost = { 3, 2 };
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	return 0;
}