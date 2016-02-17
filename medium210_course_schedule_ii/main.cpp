#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> grasp(numCourses, vector<int>(0));
		vector<int> in_degrees(numCourses, 0);
		for (auto& p : prerequisites)
		{
			grasp[p.second].push_back(p.first);
			in_degrees[p.first]++;
		}

		queue<int> que;
		vector<int> res;
		for (int i = 0; i < numCourses; i++)
		{
			if (in_degrees[i] == 0)
				que.push(i);
		}

		while (!que.empty())
		{
			int co = que.front();
			que.pop();
			res.push_back(co);
			for (auto& c : grasp[co])
			{
				in_degrees[c]--;
				if (in_degrees[c] == 0)
					que.push(c);
			}
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (in_degrees[i] != 0)
				return vector<int>();
		}

		if (res.size() != numCourses)
			return vector<int>();
		else
			return res;
    }
};

void print(vector<int>& in)
{
	for (int i = 0; i < in.size(); i++)
	{
		cout << in[i] << " ";
	}
	cout << endl;
}

int main()
{
	Solution sol;
	int numCourse = 2;
	vector<pair<int, int>> prerequ;
	prerequ.push_back(make_pair(1, 0));
	auto res = sol.findOrder(numCourse, prerequ);
	print(res);
	prerequ.push_back(make_pair(0, 1));
	res = sol.findOrder(numCourse, prerequ);
	print(res);
	return 0;
}