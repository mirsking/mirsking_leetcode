#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> res;
		string s;
		generate(n, n, s, res);
		return res;
    }
private:
	void generate(int left_num, int right_num, string s, vector<string>& res)
	{
		if (left_num == 0 && right_num == 0)
		{
			res.push_back(s);
			return;
		}
		if (left_num > 0)
			generate(left_num - 1, right_num, s + "(", res);
		
		if (right_num > 0 && left_num<right_num)
			generate(left_num, right_num - 1, s + ")", res);
	}
};


int main()
{
	Solution sol;
	auto res = sol.generateParenthesis(3);
	return 0;
}