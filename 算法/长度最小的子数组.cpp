#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int left = 0, right = 0;
        int len = nums.size();
        int res = 0;
        int minLen = len ;
        while (right < len)
        {
            /* code */
            res += nums[right++];
            while (res >= target)
            {
                /* code */
                minLen = min(minLen, right - left);
                res -= nums[left++];
            }
        }
        return minLen == len ? 0 : minLen;
    }
};

int main()
{
    vector<int> vec={1,2,3,4,5};
    Solution so;
    int tmp = so.minSubArrayLen(15,vec);

    return 0;
}