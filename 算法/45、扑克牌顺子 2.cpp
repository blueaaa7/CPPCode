#include <vector>
using namespace std;
#include <set>
#include <algorithm>

class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        set<int> _set;
        int _max = 0, _min = 14;
        for (auto itr : numbers)
        {
            if (itr == 0)
                continue;
            if (_set.count(itr))
                return false;
            _set.insert(itr);
            _max = max(_max, itr);
            _min = min(_min, itr);
        }
            return _max - _min < 5;
    }
};