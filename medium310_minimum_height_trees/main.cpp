#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
	//Õÿ∆À≈≈–Ú
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) // for the case "1 []"
			return { 0 };

		vector<int> degrees(n, 0);
		queue<int> que;
		vector<vector<int>> graph(n);
		for (auto& e : edges)
		{
			graph[e.first].push_back(e.second);
			degrees[e.first]++;

			graph[e.second].push_back(e.first);
			degrees[e.second]++;
		}
		for (int i = 0; i < n; i++)
		{
			if (degrees[i] == 1)
				que.push(i);
		}
		while (n>2)
		{
			int sz = que.size();
			if (sz == 0)
				break;
			for (int i = 0; i < sz; i++)
			{
				int node = que.front();
				que.pop();
				n--;
				for (auto t : graph[node])
				{
					degrees[t]--;
					if (degrees[t] == 1)
						que.push(t);
				}
			}
		}

		vector<int> res;
		while (!que.empty())
		{
			res.push_back(que.front());
			que.pop();
		}
		return res;

	}
};
/*
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 0)
			return vector<int>();
		// construct the graph
		vector<vector<int>> graph(n, vector<int>(n, 0));
		for (auto& e : edges)
		{
			graph[e.first][e.second] = 1;
			graph[e.second][e.first] = 1;
		}
		map<int, vector<int> > res;
		for (int i = 0; i < n; i++)
		{
			int h = getHeight(graph, i);
			if (res.find(h) == res.end())
			{
				vector<int> tmp = { i };
				res[h] = tmp;
			}
			else
			{
				res[h].push_back(i);
			}
		}
		return res.begin()->second;
    }

private:
	int getHeight(vector<vector<int>>& graph, int node)
	{
		int n = graph.size();
		vector<bool> visited(n, false);
		vector<int> height(n, 0);
		queue<int> que;
		que.push(node);
		bfs(graph, que, visited, 0, height);
		int res = 0;
		for (auto& h : height)
			res = max(res, h);
		return res;
	}
	void bfs(vector<vector<int>>& graph, queue<int>& que, vector<bool>& visited, int last_height, vector<int>& height)
	{
		if (que.empty())
			return;
		int n = graph.size();
		queue<int> que2;
		while (!que.empty())
		{
			int node = que.front();
			que.pop();

			height[node] = last_height + 1;
			visited[node] = true;
			for (int i = 0; i < n; i++)
			{
				if (i != node && !visited[i] && graph[node][i]==1)
					que2.push(i);
			}
		}
		bfs(graph, que2, visited, last_height + 1, height);
	}
};
*/

int main()
{
	//int n = 4;
	//vector<pair<int, int>> input = { { 1, 0 }, { 1, 2 }, { 1, 3 } };
	//int n = 6;
	//vector<pair<int, int>> input = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
	int n = 11;
	vector<pair<int, int>> input = { { 0, 1 }, { 0, 2 }, { 2, 3 }, { 0, 4 }, { 2, 5 }, { 5, 6 }, { 3, 7 }, { 6, 8 }, { 8, 9 }, { 9, 10 } };
	Solution sol;
	auto res = sol.findMinHeightTrees(n, input);
	for (auto& r : res)
		cout << r << " ";
	return 0;
}