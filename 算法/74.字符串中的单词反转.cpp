#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseMessage(string message) {
        int n = message.size();
        string res = "";
        for(int i = n-1;i >= 0 ;i--)
        {
            if(message[i] != ' ')
            {
               int right = i;
               while (i >= 0 && message[i] != ' ')
               {
                   i--;
               }
                res += message.substr(i+1,right-i)+" ";
            }
        }
        return res.substr(0,res.size()-1);
    }
};