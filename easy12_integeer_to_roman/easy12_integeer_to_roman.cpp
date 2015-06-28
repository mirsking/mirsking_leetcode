#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
		//unordered_map<int, char> int_roman;
		//int_roman[1000] = 'M';
		//int_roman[500] = 'D';
		//int_roman[100] = 'C';
		//int_roman[50] = 'L';
		//int_roman[10] = 'X';
		//int_roman[5] = 'V';
		//int_roman[1] = 'L';

		int kk = num / 1000;
		num = num % 1000;
		int bb = num / 100;
		num = num % 100;
		int ss = num / 10;
		int gg = num % 10;

		string res = "";
		while (kk > 0)
		{
			res += "M";
			kk--;
		}
		int2Roman(bb, "M", "D", "C", res);
		int2Roman(ss, "C", "L", "X", res);
		int2Roman(gg, "X", "V", "I", res);
	
		return res;
    }

private:
	void int2Roman(int bb, string shi, string five, string one, string& res)
	{
		if (bb > 0 && bb <= 3)
		{
			while (bb > 0)
			{
				res += one;
				bb--;
			}
		}
		else if (bb == 4)
			res = res + one + five;
		else if (bb == 5)
			res += five;
		else if (5<bb && bb<9)
		{
			res += five;
			while (bb > 5)
			{
				res += one;
				bb--;
			}
		}
		else if (bb == 9)
		{
			res = res + one + shi;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.intToRoman(2014) << endl;
	cout << sol.intToRoman(1990) << endl;
	cout << sol.intToRoman(1954) << endl;
	return 0;
}