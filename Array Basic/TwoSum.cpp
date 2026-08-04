#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(m.find(complement) != m.end()) {
                return {m[complement], i};
            }

            m[nums[i]] = i;
        }

        return {};
    }
};
class test{
    public:
    void test1() {
    Solution s1;
    vector<int> nums = {2,7,11,15};

    vector<int> ans = s1.twoSum(nums, 9);

    if(nums[ans[0]] + nums[ans[1]] == 9)
    {
        cout << "test case 1 passed";
    }
    else
    {
        cout << "test case failed";
    }
}
};


int main() {
    test ti;
    ti.test1();
   
    return 0;
}