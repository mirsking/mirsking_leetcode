#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<string> cur;
		vector<vector<string>> res;
		dfs(s, cur, res, 0, 1);
		return res;
    }
private:
	void dfs(string& s, vector<string>& cur, vector<vector<string>> &res, size_t prev, size_t start)
	{
		if (start == s.size()) // 最后一个隔板
		{
			if (isPalindrome(s, prev, start))
			{
				cur.push_back(s.substr(prev, start - prev));
				res.push_back(cur);
				cur.pop_back();
			}
			return;
		}

		//不断开
		dfs(s, cur, res, prev, start+1);
		if (isPalindrome(s, prev, start))
		{
			//断开
			cur.push_back(s.substr(prev, start - prev));
			dfs(s, cur, res, start, start + 1);
			cur.pop_back();
		}
	}

	static inline bool isPalindrome(string& s, size_t i, size_t j)
	{
		j = j - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				break;
			else
			{
				i++;
				j--;
			}
		}
		return i >= j;
	}
};
void showMatrix(vector<vector<string>>& mat)
{
	for (auto& row : mat)
	{
		for (auto& ch : row)
			cout << ch << " ";
		cout << endl;
	}
}


int main()
{
	Solution sol;
	auto res = sol.partition("aab");
	showMatrix(res);
	return 0;
}