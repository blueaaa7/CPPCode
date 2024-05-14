#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0)return false;
        unordered_map<char,char> _map={
            {')','('},
            {'}','{'},
            {']','['},
        };
        stack<char> _sta;
        for(auto itr : s)
        {
            if (_map.count(itr))
            {
                if(_sta.empty() || _sta.top() != _map[itr])
                {
                    return false;
                }
                _sta.pop();
            }
            _sta.push(itr);
        }
        return _sta.empty();
    }
};