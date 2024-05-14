#include <algorithm>
#include <string>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str string字符串 
     * @param n int整型 
     * @return string字符串
     */
    string LeftRotateString(string str, int n) {
        // write code here
        int len = str.size();
        if(n == 0 || n % len ==0)return str;
        reverse(str.begin(),str.begin()+n);
        reverse(str.begin()+n,str.end());
        reverse(str.begin(),str.end());
        return str;
    }
};