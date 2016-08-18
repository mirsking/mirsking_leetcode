#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num==0)
            return false;
        if(num ==1)
            return true;
        return (num%4==0) && isPowerOfFour(num/4);
    }
};

int main()
{
	Solution sol;
	cout << (sol.isPowerOfFour(16) ? "True" : "False") << endl;
	return 0;
}