#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	//拓扑排序。用一个队列存入度为0的节点，依次出队，
	//将与出队节点相连的节点的入度减1，如果入度减为0，将其放入队列中，直到队列为空。
	//如里最后还有入度不为0的节点的话，说明有环，否则无环。
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//用邻接表存储图
		vector<vector<int>> grasp(numCourses, vector<int>(0));
		vector<int> in_degrees(numCourses);
		for (auto& p : prerequisites)
		{
			grasp[p.second].push_back(p.first);
			in_degrees[p.first]++;
		}

		queue<int> que;
		for (int i = 0; i < numCourses; i++)
		{
			if (in_degrees[i] == 0)
				que.push(i);
		}

		while (!que.empty())
		{
			int n = que.front();
			que.pop();
			for (auto& e : grasp[n])
			{
				in_degrees[e]--;
				if (in_degrees[e] == 0)
					que.push(e);
			}
		}

		for (int i = 0; i < in_degrees.size(); i++)
		{
			if (in_degrees[i] != 0)
				return false;
		}
		return true;
    }
};

int main()
{
	Solution sol;
	int numCourse = 2;
	vector<pair<int, int>> prerequ;
	prerequ.push_back(make_pair(1, 0));
	cout << (sol.canFinish(numCourse, prerequ) ? "True" : "False") << endl;
	prerequ.push_back(make_pair(0, 1));
	cout << (sol.canFinish(numCourse, prerequ) ? "True" : "False") << endl;
	return 0;
}