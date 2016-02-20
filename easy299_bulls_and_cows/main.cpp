#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//http://www.cnblogs.com/easonliu/p/4926337.html
class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA = 0, cntB = 0;
        unordered_map<char, int> hash;
        vector<bool> tag(secret.size(), false);
        for (auto a : secret) {
            ++hash[a];
        };
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++cntA;
                --hash[secret[i]];
                tag[i] = true;
            }
        }
        for (int i = 0; i < guess.size(); ++i) {
            if (!tag[i] && hash[guess[i]] > 0) {
                ++cntB;
                --hash[guess[i]];
            }
        }
        return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};

int main()
{
	Solution sol;

	cout << sol.getHint("1123", "0111") << endl; //1A1B
	cout << sol.getHint("1", "0") << endl; //0A0B
	cout << sol.getHint("11", "11") << endl; //2A0B
	cout << sol.getHint("011", "110") << endl; //1A2B
	return 0;
}