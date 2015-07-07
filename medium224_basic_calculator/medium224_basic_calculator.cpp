#include <stack>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<long> postfix = to_postfix(s);
        int len = postfix.size();
        if (len == 0) {
            return 0;
        }
        vector<long> tmp;
        long a, b;
        for (int i=0; i<len; i++) {
            long ch = postfix[i];
            switch(ch) {
                case '+':
                    a = tmp.back();
                    tmp.pop_back();
                    tmp.back() = tmp.back() + a;
                    break;
                case '-':
                    a = tmp.back();
                    tmp.pop_back();
                    tmp.back() = tmp.back() - a;
                    break;
                default:
                    tmp.push_back(ch);
            }
        }
        return tmp[0];
    }
    
    vector<long> to_postfix(const string& s) {
        int len = s.size();
        // operators
        vector<char> operato;
        // generated postfix experssion of this infix experssion
        vector<long> postfix;
        
        int val = 0;
        bool innum = false;
        
        for (int i=0; i<len; i++) {
            char ch = s[i];
            switch (ch) {
                case ' ':
                    // skip space
                    continue;
                case '-':
                case '+':
                    while (!operato.empty() && operato.back() != '(') {
                        postfix.push_back(operato.back());
                        operato.pop_back();
                    }
                    operato.push_back(ch);
                    break;
                case '(':
                    // just push to operato
                    operato.push_back(ch);
                    break;
                case ')':
                    // move any operato between this ')' and it's paired '('
                    while (!operato.empty() && operato.back() != '(') {
                        postfix.push_back(operato.back());
                        operato.pop_back();
                    }
                    // destroy '(' placeholder
                    operato.pop_back();
                    break;
                default:
                    if (innum) {
                        val = val * 10 + ch - '0';
                    } else {
                        val = ch - '0';
                        innum = true;
                    }
                    // look ahead
                    if (i+1 == len || s[i+1] > '9' || s[i+1] < '0') {
                        postfix.push_back(val);
                        innum = false;
                    }
            }
        }
        
        while (!operato.empty()) {
            postfix.push_back(operato.back());
            operato.pop_back();
        }
        return postfix;
    }
};

int main()
{
	Solution sol;
	cout << sol.calculate("(45+(4+5+2)-3)+(6+8)") << endl;
	return 0;
}