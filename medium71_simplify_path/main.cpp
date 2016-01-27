#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> sta;
        string::iterator begin = path.begin();
        string::iterator end = path.end();
        while(begin<end)
        {
            string str = getNextStr(begin, end);
            if(str == "..")
            {
                if(!sta.empty())
                    sta.pop();
            }
            else if(str == "." || str=="")
                ;
            else
                sta.push(str);
        }
        vector<string> strs;
        if(sta.empty())
            return "/";

        while(!sta.empty())
        {
            strs.push_back(sta.top());
            sta.pop();
        }
        string res;
        for(auto it = strs.rbegin(); it!=strs.rend(); it++)
        {
            res += ("/" + *it);
        }
        return res;

    }
private:
    string getNextStr(string::iterator& begin, string::iterator& end)
    {
        string res;
        bool begin_flag = false;
        while(begin!=end)
        {
            if(*begin=='/')
            {
                if(!begin_flag)
                    begin_flag = true;
                else
                    break;
            }
            else
            {
                res.push_back(*begin);
            }
            begin++;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") << endl;
    cout << sol.simplifyPath("/a/b/../../../c/d/../e") << endl;
    cout << sol.simplifyPath("/home/mirsking/") << endl;
    cout << sol.simplifyPath("/a/.//b/../../c/") << endl;
    cout << sol.simplifyPath("/home//mirsking") << endl;
    return 0;
}
