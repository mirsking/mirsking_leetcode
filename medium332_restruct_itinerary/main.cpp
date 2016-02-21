#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

//https://www.hrwhisper.me/leetcode-reconstruct-itinerary/
class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, map<string,int>> m;
		for (const auto &p : tickets) {
			m[p.first][p.second]++;
		}
		string start = "JFK";
		vector<string> ans;
		ans.push_back(start);
		dfs(start, ans, tickets.size()+ 1, m);
		return ans;
	}
	
	bool dfs(const string & cur,vector<string> &ans,const int &n,unordered_map<string, map<string, int>> &m) {
		if (ans.size() == n) return true;
		for (auto ticket = m[cur].begin(); ticket != m[cur].end(); ticket++) { //map<string, int>::iterator
			if (ticket->second != 0) {
				ticket->second--;
				ans.push_back(ticket->first);
				if (dfs(ticket->first, ans, n, m)) return true;
				ans.pop_back();
				ticket->second++;
			}
		}
		return false;
	}
};

int main()
{
	return 0;
}