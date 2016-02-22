#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//http://blog.csdn.net/booirror/article/details/47626999
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for (int i = 0; i < input.size(); i++) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> lv = diffWaysToCompute(input.substr(0, i));
                vector<int> rv = diffWaysToCompute(input.substr(i+1));
                for (auto x : lv) {
                    for (auto y : rv) {
                        if (ch == '+') {
                            result.push_back(x+y);
                        } else if (ch == '*') {
                            result.push_back(x*y);
                        } else if (ch == '-') {
                            result.push_back(x-y);
                        }
                    }
                }
            }
        }
        if (result.empty()) {
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};

int main()
{

	return 0;
}