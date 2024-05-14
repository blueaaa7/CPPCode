#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i+1;
            int right = len -1;
            while (left <  right)
            {
                int tmp = nums[i]+nums[left]+nums[right];
                if(tmp > 0)
                {
                    right--;
                }
                else if(tmp < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left < right && nums[left] == nums[left+1]) 
                        left++;
                    while(left < right && nums[right] == nums[right-1]) 
                        right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};