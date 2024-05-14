#include <algorithm>
#include <string>
#include <ranges>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return equal(s.begin(),s.end(),t.begin());
    }
};
