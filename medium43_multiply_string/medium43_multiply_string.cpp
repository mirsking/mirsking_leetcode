#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
		string res;
		if (num1.size() == 0 || num2.size() == 0)
			return res;

		if (num1 == "0" || num1 == "-0" || num2 == "0" || num2 == "-0")
			return "0";

		int sign_count = 0;
		if (num1[0] == '-')
		{
			sign_count++;
			num1.erase(num1.begin());
		}
		if (num2[0] == '-')
		{
			sign_count++;
			num2.erase(num2.begin());
		}

		res.assign(num1.size(), '0');

		int carry = 0;
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			for (int j = num1.size() - 1; j >= 0; j--)
			{
				int tmp = (num2[i] - '0')*(num1[j] - '0');
				long long right_dist2 = num2.size() - 1 - i;
				long long right_dist1 = num1.size() - 1 - j;
				long long index = res.size() - 1 - right_dist2 - right_dist1;

				if (index < 0)
				{
					tmp += carry;
					res.insert(res.begin(), tmp%10 + '0');
					carry = tmp / 10;
				}
				else
				{
					int tmp1 = res[index] - '0' + tmp + carry;
					res[index] = tmp1%10 + '0';
					carry = tmp1 / 10;
				}
			}
			if (carry != 0)
			{
				if (carry >= 10)
					cout << "carry error" << endl;
				else
				{
					res.insert(res.begin(), carry + '0');
					carry = 0;
				}
			}
		}


		if (sign_count % 2 != 0)
			res.insert(res.begin(), '-');
		return res;
    }
};


int main()
{
	Solution sol;
	cout << sol.multiply("9", "99");
	return 0;
}