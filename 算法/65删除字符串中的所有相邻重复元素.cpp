#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.size();
        stack<char> sta;
        for(int i=0;i<len;i++)
        {
            if(sta.empty())
            {
                sta.push(s[i]);
            }
           else if(sta.top() == s[i])
           {
                sta.pop();
                continue;
           }
           else
           {
            sta.push(s[i]);
           }
        }
        string res;
        len = sta.size();
        for(int i=0;i<len;i++)
        {
            res = sta.top() + res;
            sta.pop();
        }
        return res;
    }
};