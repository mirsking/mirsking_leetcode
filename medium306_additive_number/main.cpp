#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
		int n = num.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				string s1 = num.substr(0, i+1);
				string s2 = num.substr(i+1, j-i);
				if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
					continue;
				//long long d1 = stoll(s1);
				//long long d2 = stoll(s2);
				//long long next = d1 + d2;
				//string snext = to_string(next);
				string snext = strAdd(s1, s2);

				string now = s1 + s2 + snext;
				while (now.size() < num.size())
				{
					//d1 = d2;
					//d2 = next;
					//next = d1 + d2;
					//snext = to_string(next);
					s1 = s2;
					s2 = snext;
					snext = strAdd(s1, s2);
					now += snext;
				}
				if (now == num) return true;
			}
		}
		return false;
    }
private:
	string strAdd(string lhs, string rhs)
	{
		string res;
		int m = lhs.size(); 
		int n = rhs.size();
		int max_size = max(m, n);
		int carry = 0;
		for (int i = 0; i < max_size; i++)
		{
			int l, r;
			if (i < m)
				l = lhs[m - i - 1] - '0';
			else
				l = 0;
			if (i < n)
				r = rhs[n - i - 1] - '0';
			else
				r = 0;
			int val = l + r + carry;
			res.insert(res.begin(), val % 10 + '0');
			carry = val / 10;
		}
		if (carry != 0)
			res.insert(res.begin(), carry + '0');
		
		return res;
	}
};

int main()
{
	Solution sol;
	//cout << (sol.isAdditiveNumber("112358") ? "True" : "False") << endl;
	//cout << (sol.isAdditiveNumber("199100199") ? "True" : "False") << endl;
	cout << (sol.isAdditiveNumber("211738")? "True" : "False") << endl;
	cout << (sol.isAdditiveNumber("101123581321345589144") ? "True" : "False") << endl;
	//cout << sol.strAdd("101123581321345589144", "7") << endl;
	//cout << sol.strAdd("1", "99") << endl;
	
	return 0;
}