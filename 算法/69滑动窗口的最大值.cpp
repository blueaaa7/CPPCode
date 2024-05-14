#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pque;
        for (int i = 0; i < k; i++)
        {
            pque.emplace(nums[i], i);
        }
        vector<int> res;
        res.emplace_back(pque.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            pque.emplace(nums[i],i);
            while (pque.top().second <= i-k)
            {
                pque.pop();
            }
            res.emplace_back(pque.top().first);
        }
        return res;
    }
};