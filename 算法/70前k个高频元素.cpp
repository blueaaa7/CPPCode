#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int,less<int>> unmap;
        for(auto itr:nums)
        {
           unmap[itr]++;
        }
        vector<pair<int,int>> res;
        for(auto itr:unmap)
        {
            res.push_back(itr);
        }
        sort(res.begin(),res.end(),[=](const pair<int,int> a, const pair<int,int> b){
            return a.second > b.second;
        });
        vector<int> ress;
        for(auto itr:res)
        {
            ress.push_back(itr.first);
        }
        ress.resize(k);
        return ress;
    }
};