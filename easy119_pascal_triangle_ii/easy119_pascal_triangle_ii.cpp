#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<vector<int> > res;
		res = generate(rowIndex+1);
		return res[res.size() - 1];
    }

private:
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


int main()
{
	Solution sol;
	vector<int> a = sol.getRow(3);
	return 0;
}