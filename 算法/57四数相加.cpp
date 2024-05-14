#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> unmap1;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                unmap1[nums1[i]+nums2[j]]++;
            }
        }
        int count =0;
        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
            {
                if(unmap1.count(-nums3[i]-nums4[j]))
                {
                    count +=unmap1[-nums3[i]-nums4[j]];
                }
            }
        }
        return count;
    }
};
