#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return bool布尔型
     */
    bool IsContinuous(vector<int> &numbers)
    {
        // write code here
        sort(numbers.begin(), numbers.end());
        int zero_count = 0;
        int i = 0;
        int distance = 0;
        for (auto itr : numbers)
        {
            if (itr == 0)
            {
                zero_count++;
                i++;
            }
        }
        for (; i < numbers.size()-1; i++)
        {
            if (numbers[i] == numbers[i + 1])
                return false;
            distance += numbers[i + 1] - numbers[i] - 1;
        }
        if (distance <= zero_count)
            return true;
        return false;
    }
};