#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string return_val;
		if (strs.size() == 0)
			return "";

		int str_size = strs[0].size();
		for (int i = 1; i < strs.size(); i++)
			str_size = strs[i].size() < str_size ? strs[i].size() : str_size;

		int k = -1;
		bool same = true;
		for (int i = 0; i < str_size; i++)
		{
			char tmp = strs[0][i];
			for (int j = 1; j < strs.size(); j++)
			{
				same &= (strs[j][i] == tmp);
				if (same == false)
					break;
			}
			if (same == false)
				break;
			else
				k = i;
		}
		
		return strs[0].substr(0, k+1);
    }
};


int main(int argc, char** argv)
{
	Solution sol;
	vector<string> strs;
	//strs.push_back("");
	//strs.push_back("ta");
	//strs.push_back("tab");

	string a;
	a = sol.longestCommonPrefix(strs);
	cout << a;
	return 0;
}