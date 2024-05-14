#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sta;
        int len = tokens.size();
        for(int i=0 ;i<len;i++)
        {
            string token = tokens[i];
            if(isNumber(token))
            {
                sta.push(atoi(token.c_str()));
            }
            else
            {
                int tmp1 = sta.top();
                sta.pop();
                int tmp2 = sta.top();
                sta.pop();
                switch(token[0])
                {
                    case '+':
                        sta.push(tmp1 + tmp2);
                        break;
                    case '-':
                        sta.push(tmp2 - tmp1);
                        break;
                    case '*':
                        sta.push(tmp1 * tmp2);
                        break;
                    case '/':
                        sta.push(tmp2 / tmp1);
                        break;
                }
            }
        }
            return sta.top();

    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

