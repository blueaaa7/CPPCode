#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.empty())return nums;
        int size = nums.size();
        vector<int> res;
        for(int i=0;i<size;i++)
        {
            int tmp = nums[i];
            for(int j=i+1;j<size;j++)
            {
                int tmp2 = nums[j];
                if(tmp+tmp2 == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};