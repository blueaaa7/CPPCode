#include <string>
#include <regex>
#include <iostream>

using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        smatch res;
        
        if(regex_search(haystack,res,regex(needle)))
        {
            cout<<res.position();
            // cout<<res[1];
        }
        return 0;
    }
};

int main()
{
    Solution so;
    so.strStr("sadbutsad","sad");
    return 0;
}