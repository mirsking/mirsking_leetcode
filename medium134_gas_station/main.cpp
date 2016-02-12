#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0;
		int j = -1;
		int sum = 0;
		for (int i = 0; i < gas.size(); i++)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0)
			{
				j = i;
				sum = 0;
			}
		}
		return total >= 0 ? j + 1 : -1;
	}
	/* TLE
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
	*/
};

int main()
{
	vector<int> gas = {2,3};
	vector<int> cost = { 3, 2 };
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	return 0;
}