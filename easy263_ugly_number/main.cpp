#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
		if (num <= 0)
			return false;
		if (num == 1)
			return true;
		divide2End(num, 2);
		divide2End(num, 3);
		divide2End(num, 5);
		return num == 1;
    }
private:
	inline void divide2End(int& a, int b)
	{
		while (a%b==0)
		{
			a = a / b;
		}
	}
};

int main()
{
	Solution sol;
	cout << (sol.isUgly(6) ? "True" : "False") << endl;
	cout << (sol.isUgly(8) ? "True" : "False") << endl;
	cout << (sol.isUgly(14) ? "True" : "False") << endl;

	return 0;
}