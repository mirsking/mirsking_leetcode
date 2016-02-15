#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	//����������һ�����д����Ϊ0�Ľڵ㣬���γ��ӣ�
	//������ӽڵ������Ľڵ����ȼ�1�������ȼ�Ϊ0�������������У�ֱ������Ϊ�ա�
	//�����������Ȳ�Ϊ0�Ľڵ�Ļ���˵���л��������޻���
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//���ڽӱ�洢ͼ
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