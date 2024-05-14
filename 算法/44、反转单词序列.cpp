#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.empty()) return str;
        stack<vector<char>> sta;
        auto itr = str.begin();
        vector<char> vec;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]!=' ')
            {
                vec.push_back(str[i]);
            }
            else
            {
                sta.push(vec);
                vec.erase(vec.begin(),vec.end());
            }
        }
        string str_res;
        int count =0;
        for(int i=0; i<sta.size(); i++)
        {
            vector<char> tmp(sta.top());
            sta.pop();
           for(auto itr : tmp)
           {
            str_res+=itr;
           }
            if(count < sta.size())
            {
                str_res+=' ';
            }
        }
        return str_res;
    }
};

