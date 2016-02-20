#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	//���һ����x���Ա�ʾΪһ��������a����һ��ƽ����b��b��Ҳ����x=a+b��b��
	//��ô����������x���ٵ�ƽ�������������������a���ٵ�ƽ������������1����Ϊb*b�Ѿ���ƽ�����ˣ���
    int numSquares(int n) {
		vector<long long> dp(n + 1, INT_MAX);
		for (int i = 0; i*i <= n; i++)
			dp[i*i] = 1;

		for (long long a = 0; a <= n; a++)
		{
			for (long long b = 0; a + b*b <= n; b++)
			{
				dp[a + b*b] = min(dp[a] + 1, dp[a + b*b]);
			}
		}
		return dp[n];
    }
};

int main()
{
	Solution sol;
	cout << sol.numSquares(10) << endl;
	return 0;
}