#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		nums.insert(nums.begin(), INT_MIN);
		nums.insert(nums.end(), INT_MIN);
		return findPeakElement(nums.begin() + 1, nums.end() - 1, nums.end()) - nums.begin();
    }
private:
	template<typename BidiIt>
	BidiIt findPeakElement(BidiIt begin, BidiIt end, const BidiIt flag)
	{
		BidiIt mid = (end - begin) / 2 + begin;
		if (isPeak(mid))
			return mid;

		BidiIt lres = findPeakElement(begin, mid, flag);
		if (lres != flag)
			return lres;

		BidiIt rres = findPeakElement(mid, end, flag);
		if (rres != flag)
			return rres;

		return flag;
	}
	template<typename BidiIt>
	bool isPeak(BidiIt mid)
	{
		if (*mid > *next(mid) && *mid > *prev(mid))
			return true;
		else
			return false;
	}
};

int main()
{
	int a[] = {1,2,3,1};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.findPeakElement(b);
	return 0;
}