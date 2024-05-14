#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        sort(nums.begin(), nums.end());
        if(nums.empty() || nums[0] > val || nums.back() < val) return nums.size();
        auto itr = remove(nums.begin(), nums.end(), val);
        nums.erase(itr,nums.end());
        return nums.size();
    }
};