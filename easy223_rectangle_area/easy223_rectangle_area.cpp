#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area = 0;
		vector<int> points;
		int tmp = isRecInRec(A, B, C, D, E, F, G, H, points);
		switch (tmp)
		{
		case 0:break;
		case 1: {
					vector<int> point2;
					if (isRecInRec(E, F, G, H, A, B, C, D, point2) == 1)
					{
						area = recArea(A, B, C, D) + recArea(E, F, G, H)
							- recArea(points[0], points[1], point2[0], point2[1]);
					}
					else
						cout << "caculate error!";
					break;
		}
		case 2:
		{

				  break;
		}
		}
		return area;
    }

private:
	inline int recArea(int A, int B, int C, int D)
	{
		return abs(A - C)*abs(B - D);
	}

	/* is point AB in EFGH*/
	inline bool isPointInRec(int A, int B, int E, int F, int G, int H)
	{
		if (E <= A && A <= G && F <= B && B <= H)
			return true;
		else 
			return false;
	}
	/* is rec ABCD any point in EFGH, if true ,results in vector<int>*/
	/* how many point in, 0 1 2 4*/
	int isRecInRec(int A, int B, int C, int D, int E, int F, int G, int H, vector<int>& points)
	{
		if (isPointInRec(A, B, E, F, G, H))
		{
			points.push_back(A);
			points.push_back(B);
		}
		if (isPointInRec(A, D, E, F, G, H))
		{
			points.push_back(A);
			points.push_back(D);
		}
		if (isPointInRec(C, D, E, F, G, H))
		{
			points.push_back(C);
			points.push_back(D);
		}
		if (isPointInRec(C, B, E, F, G, H))
		{
			points.push_back(C);
			points.push_back(B);
		}

		return points.size()/2;
	}
};

int main()
{
	Solution sol;
	cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);
	return 0;
}