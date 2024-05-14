#include <vector>
#include <algorithm>
// #include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        vector<int> res;
        while(true)
        {
            if(n==1)return true;
            if(find(res.begin(),res.end(),n) != res.end())
                return false;
            res.push_back(n);
            int next_n=0;
            while(n>0)
            {
                int d=n%10;
                next_n += d*d;
                n/=10;
            }
            n=next_n;
        }
    }
};
