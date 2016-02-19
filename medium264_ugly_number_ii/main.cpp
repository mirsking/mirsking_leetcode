#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
		int i = 0;
		int num = 0;
		while (i < n)
		{
			num++;
			if (isUglyNumber(num))
				i++;
		}
		return num;
    }
private:
	bool isUglyNumber(int m)
	{
		if (m <= 0)
			return false;
		divide2End(m, 2);
		divide2End(m, 3);
		divide2End(m, 5);
		return m == 1;
	}
	inline void divide2End(int& a, int b)
	{
		while (a%b == 0)
			a /= b;
	}
};

int main()
{
	Solution sol;
	cout << sol.nthUglyNumber(10) << endl;
	return 0 ;
}