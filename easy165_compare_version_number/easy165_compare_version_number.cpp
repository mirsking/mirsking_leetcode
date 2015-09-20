#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
		long long v1 = getFirstVersion(version1);
		long long v2 = getFirstVersion(version2);
		if (v1 != v2)
			return v1 > v2 ? 1 : -1;
		else
		{
			if (version1.size() == 0 && version2.size()==0)
				return 0;
			else
				return compareVersion(version1, version2);
		}
        
    }
private:
	long long getFirstVersion(string& str)
	{
		long long res = 0;
		size_t point_i = str.find('.');
		if (point_i >= str.size())
		{
			if (str.empty())
				res = 0;
			else
				res = stol(str);
			str.clear();
		}
		else
		{
			res = stol(str.substr(0, point_i));
			str = str.substr(point_i + 1, str.size() - point_i - 1);
		}
		return res;
	}
};


int main()
{
	string v1 = "1.0";
	string v2 = "1";
	Solution sol;
	cout << sol.compareVersion(v1, v2);
	return 0;
}