#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		return findPeakElement(nums.begin(), nums.end());
    }
private:
	template<typename BidiIt>
	int findPeakElement(BidiIt begin, BidiIt end)
	{
		BidiIt mid = (begin + end) / 2;
		int lres = findPeakElement(begin, mid);
		int rres = findPeakElement(mid, end);
		if (lres >= 0)
			return lres;
		else if (rres > 0)
			return rres;
	}
};