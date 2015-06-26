#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
		int max_area = 0;
		int start = 0, end = height.size() - 1;
		while (start < end)
		{
			int tmp = min(height[start], height[end])*(end - start);
			max_area = max(tmp, max_area);
			if (height[start] < height[end])
				start++;
			else
				end--;
		}

		return max_area;
    }


};

int main()
{
	int a[] = { 1, 2, 1 ,2 ,3};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.maxArea(b);
	return 0;
}