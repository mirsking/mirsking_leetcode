#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

        if(divisor == 0)
            return INT_MAX;

        int s1 = sign(dividend);
        cout << s1 << endl;
        int s2 = sign(divisor);
        cout << s2 << endl;

        long long n1 = abs(static_cast<long long>(dividend));
        long long n2 = abs(static_cast<long long>(divisor));
        long long ans = 0;
        while(n1>=n2)
        {
            long long base = n2;
            for(int i=0; n1>=base; ++i)
            {
                n1 -= base;
                base <<= 1;
                ans += 1LL << i;
            }
        }
        if(s1==s2)
        {
            if(ans > INT_MAX)
                return INT_MAX;
            else
                return ans;
        }
        else
            return -ans;
    }
private:
    int sign(int x){
        return x<0?-1:1;
    }

};


int main()
{
    Solution sol;
    cout << sol.divide(-2147483648, -1) << endl;
    return 0;
}
