#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int> > res;
		if (numRows < 1)
			return res;

		vector<int> tmp;
		tmp.push_back(1);
		res.push_back(tmp);

		for (int i = 1; i < numRows; i++)
		{
			tmp.clear();
			tmp.push_back(1);
			for (int j = 1; j < i; j++)
			{
				auto& v = res[i - 1];
				tmp.push_back(v[j-1]+v[j]);
			}
			tmp.push_back(1);
			res.push_back(tmp);

		}

		return res;
    }
};


int main(int argc, char** argv)
{

	Solution sol;
	vector<vector<int> > res = sol.generate(5);
	return 0;
}