#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {2,2,7,11,15};

        if(s1.containDuplicate(nums))
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {2,7,11,15};

        if(!s1.containDuplicate(nums))
            cout << "test case 2 passed\n";
        else
            cout << "test case 2 failed\n";
    }
};

int main() {
    test ti;
    ti.test1();
    ti.test2();

    return 0;
}