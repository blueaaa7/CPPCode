#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        sort(ransomNote.begin(),ransomNote.end());
        sort(magazine.begin(),magazine.end());
        return includes(magazine.begin(),magazine.end(),ransomNote.begin(),ransomNote.end());
    }
};

int main(){};  