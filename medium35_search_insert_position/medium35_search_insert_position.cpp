#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		return binarySearch(nums.begin(), nums.end(), target) - nums.begin();
    }
private:
	template <typename BidiIt, typename Type>
	BidiIt binarySearch(BidiIt begin, BidiIt end, Type target)
	{
		if (end - begin == 1)
		{
			if (*begin >= target)
				return begin;
			else
				return end;
		}

		BidiIt mid = (end - begin) / 2 + begin;
		if (*mid > target)
			end = mid;
		else if (*mid < target)
			begin = mid;
		else if (*mid == target)
			return mid;

		return binarySearch(begin, end, target);
	}

};

int main()
{
	int a[] = { 1, 2, 3, 6 };
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.searchInsert(b, 5);
	return 0;
}