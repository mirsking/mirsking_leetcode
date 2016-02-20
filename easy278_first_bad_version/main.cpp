#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define BAD_NUM 2147483647
bool isBadVersion(int version)
{
	if (version >= BAD_NUM)
		return true;
	else
		return false;
}


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
		long long left = 1;
		long long right = n; right += 1;
		while (left < right)
		{
			long long mid = left + (right - left) / 2; //(left + right) / 2;
			if (isBadVersion(mid))
				right = mid;
			else
				left = mid + 1;
		}
		return left;
    }
};

int main()
{
	Solution sol;
	cout << sol.firstBadVersion(2147483647) << endl;
	return 0;
}