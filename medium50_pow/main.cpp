#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        if(n==1)
            return x;
        double tmp = myPow(x, abs(n/2));
        if(n>0)
        {
            if(n&1) // n is odd
                return tmp*tmp*x;
            else
                return tmp*tmp;
        }
        else
        {
            if(n&1)
                return 1.0/(tmp*tmp*x);
            else
                return 1.0/(tmp*tmp);
        }
    }
};


int main()
{

    Solution sol;
    cout << sol.myPow(10.0, 100) << endl;

    return 0;
}
