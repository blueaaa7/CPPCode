#include <vector>
#include <algorithm>
#include <stack>
using namespace std;



class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(),s.end());
        stack<char> sta;
        for(auto itr:s)
        {
            sta.push(itr);
        }
        int size = sta.size();
        s.clear();
        for(int i=0 ;i<size;i++)
        {
            s.push_back(sta.top());
            sta.pop();
        }
    }
};