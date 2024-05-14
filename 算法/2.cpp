#include <unordered_map>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0)return false;
        unordered_map<int,int> unmap={
            {')','('},
            {']','['},
            {'}','{'}
        };
        stack<int> sta;
        int len = s.size();
        for(int i=0;i<len;i++)
        {
            if(unmap.find(s[i]) != unmap.end())
            {
                if(sta.empty() || sta.top() != unmap[s[i]])
                {
                    return false;
                }
                else
                {
                    sta.pop();
                }
            }
            else
            {
                sta.push(s[i]);
            }
        }
        return sta.size() == 0;
    }
};