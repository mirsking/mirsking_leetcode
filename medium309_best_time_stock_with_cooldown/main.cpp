#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//http://www.cnblogs.com/grandyang/p/4997417.html
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
        for (int price : prices) {
            pre_buy = buy;
            buy = max(pre_sell - price, pre_buy);
            pre_sell = sell;
            sell = max(pre_buy + price, pre_sell);
        }
        return sell;
    }
};
int main()
{
	return 0;
}