#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
		return findPeakElement(nums.begin(), nums.end(),nums.begin(), nums.end()) - nums.begin();
    }
private:
	template<typename BidiIt>
	BidiIt findPeakElement(BidiIt begin, BidiIt end, const BidiIt begin_flag, const BidiIt end_flag)
	{
		if (end - begin == 1)
		{
			if (isPeak(begin_flag, end_flag, begin))
				return begin;
			else
				return end_flag;
		}

		BidiIt mid = (end - begin) / 2 + begin;
		cout << *begin << " " << *mid << " " << *prev(end) << endl;
		if (isPeak(begin_flag, end_flag, mid))
			return mid;

		BidiIt lres = findPeakElement(begin, mid, begin_flag, end_flag);
		BidiIt rres = findPeakElement(mid, end, begin_flag, end_flag);
		if (lres != end_flag)
			return lres;
		if (rres != end_flag)
			return rres;

		return end_flag;
	}
	template<typename BidiIt>
	bool isPeak(const BidiIt begin, const BidiIt end, BidiIt mid)
	{
		if (mid != begin && mid != prev(end))
		{
			if (*mid > *next(mid) && *mid > *prev(mid))
				return true;
			else
				return false;
		}
		else if (mid == begin && mid == prev(end))
			return true;
		else if (mid == begin)
			return *mid > *next(mid);
		else if (mid == prev(end))
			return *mid > *prev(mid);
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