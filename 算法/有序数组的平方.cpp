#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.empty()) return nums;
        int len = nums.size();
        for(int i=0 ;i < len; i++)
        {
            nums[i] = pow(nums[i],2);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};