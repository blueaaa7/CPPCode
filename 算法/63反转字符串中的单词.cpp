#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string str;
        int len = s.size();
        string tmp;
        for(int i=0;i<len;i++)
        {
            if(s[i] != ' ')
            {
                tmp = tmp+s[i];
            }
            else
            {
                if(!tmp.empty())
                {
                    if (!str.empty()) {
                    tmp += ' ';
                }
                }
                
                str = tmp + str;
                tmp = "";
            }
        }
        if (!tmp.empty()) {
            if (!str.empty()) {
                tmp += ' ';
            }
            str = tmp + str;
        }
        return str;
    }
};

