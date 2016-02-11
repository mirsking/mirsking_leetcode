#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
		int n = s.size();
		int i = 0, j = n-1;
		while (i < j)
		{
			while (i<n && !isAlphanumberic(s[i]))
				i++;
			while (j>=0 && !isAlphanumberic(s[j]))
				j--;
			if (i >= j)
				return true;
			//cout << s[i] << " v.s. " << s[j] << endl;
			if (s[i] != s[j])
				return false;
			else
			{
				i++; j--;
			}
		}
		return true;
    }
private:
	static inline bool isAlphanumberic(char& ch)
	{
		if ('0' <= ch && ch <= '9')
			return true;
		else if ('a' <= ch && ch <= 'z')
			return true;
		else if ('A' <= ch && ch <= 'Z')
		{
			ch = ch - 'A' + 'a'; //convert to lowercase
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Solution sol;
	cout << (sol.isPalindrome("A man, a plan, a canal: Panama")?"True":"False") << endl;
	cout << (sol.isPalindrome("ab")?"True":"False") << endl;
	cout << (sol.isPalindrome("A man,         a plan, a canal: Panama")?"True":"False") << endl;
	return 0;
}