#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> _unmap;
        int left=0,right=0;
        int res=0;
        while (right < s.size())
        {
            int tmp = s[right];
            _unmap[tmp]++;
            right++;
            while (_unmap[tmp] > 1)
            {
                /* code */
                int tmp = s[left];
                _unmap[tmp]--;
                left++;
            }
            res = max(res,right - left);
        }
        return res;
        
    }
};