#include <vector>
using namespace std;

class Solution {
public:

    int search(vector<int>& nums, int target) {
        if(nums.empty() || nums[0] > target || nums.back() < target) return -1;
        int left = 0;
        int right = nums.size()-1;
        while(left <= right)
        {
            int mid = left +( (right - left) >> 1);
            if(nums[mid] == target) return mid;
            else
            {
                if(nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};