#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/* runtime error at 
* int a[] = {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
bool isGreater(int lhs, int rhs)
{
	string tmp1 = to_string(lhs), tmp2 = to_string(rhs);
	string lstr = tmp1 , rstr = tmp2;
	bool exchangeFlag = false;
	if (tmp1.size() > tmp2.size())
	{
		lstr = tmp2; rstr = tmp1;
		exchangeFlag = true;
	}
	int minN = lstr.size(), maxN = rstr.size();
	for (int i = 0; i < minN; i++)
	{
		if (lstr[i] > rstr[i])
			return exchangeFlag? false: true;
	}
	for (int i = minN; i < maxN; i++)
	{
		if (lstr[minN - 1] > rstr[i])
			return exchangeFlag? false: true;
	}

	return exchangeFlag? true: false;
}
*/

/*
* error at int a[] = { 824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
bool isGreater(int lhs, int rhs)
{
	string lstr = to_string(lhs), rstr = to_string(rhs);
	int i = 0;
	while (lstr.size() < rstr.size())
	{
		lstr.push_back(lstr[i]);
		i++;
	}
	while (rstr.size() < lstr.size())
		rstr.push_back(rstr[rstr.size() - 1]);
	cout << lhs << " < " << rhs << " " << (lstr < rstr) << endl;
	return lstr>rstr;
}
*/


bool isStrGreater(string lhs, string rhs)
{
	string lstr = lhs , rstr = rhs;
	bool exchangeFlag = false;
	if (lhs.size() > rhs.size())
	{
		lstr = rhs; rstr = lhs;
		exchangeFlag = true;
	}
	int minN = lstr.size(), maxN = rstr.size();

	if (lstr > rstr.substr(0, minN))
		return exchangeFlag ? false : true;
	else if (lstr < rstr.substr(0, minN))
		return exchangeFlag ? true : false;
	else
	{
		if (minN == maxN)
			return exchangeFlag? true:false;
		else
		{
			bool tmp = isStrGreater(lstr, rstr.substr(minN, maxN - minN));
			return exchangeFlag ? !tmp : tmp;
		}
	}	
}


bool isGreater(int lhs, int rhs)
{
	string tmp1 = to_string(lhs), tmp2 = to_string(rhs);
	return isStrGreater(tmp1, tmp2);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
		string res="";
		sort(nums.begin(), nums.end(), isGreater);

		for (int i = 0; i < nums.size(); i++)
		{
			if (res == "0" && nums[i] == 0)
				;
			else
				res += to_string(nums[i]);
		}
		return res;
    }
};

int main()
{
	//int a[] = {9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
	//int a[] = { 824, 938, 1399, 5607, 6973, 5703, 9609, 4398, 8247};
	//int a[] = {12,121};
	int a[] = {2, 216, 213, 2000, 2060};
	vector<int> b(a, a + sizeof(a) / sizeof(int));
	Solution sol;
	cout << sol.largestNumber(b);
	return 0;
}