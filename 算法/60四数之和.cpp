#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<len;i++)
        {
            if(nums[i] > target && nums[i] >= 0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<len;j++)
            {   
                if(nums[i]+nums[j] > target && nums[i]+nums[j] >= 0)
                    break;
                if(j > i+1 && nums[j] == nums[j-1])
                {
                    continue;
                }
                int left = j+1;
                int right = len-1;
                int tmp = nums[i] + nums[j];

                while(left < right)
                {
                    int tmp2 = nums[i] + nums[j] + nums[left] + nums[right]; 
                    if(tmp2 > target)
                    {
                        right--;
                    }
                    else if(tmp2 < target)
                    {
                        left++;
                    }
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while (left < right && nums[left] == nums[left+1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right-1])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};