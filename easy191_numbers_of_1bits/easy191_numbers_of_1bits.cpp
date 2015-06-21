#include <iostream>
#include <cstdint>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0)
		{
			if (n % 2 == 1)
				count++;
			n = n / 2;
		}
		return count;
    }
};

int main()
{
	Solution sol;
	cout << sol.hammingWeight(15) << endl;
	cout << sol.hammingWeight(32767) << endl;
	return 0;
}