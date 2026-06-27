/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for(i=0; i < nums.size(); i++) {
            if(nums[i] != i ) {
                return i;
            }
        }

        return i;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {0,1,3};

        if(s1.missingNumber(nums)==2)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {0,1,2};

        if(s1.missingNumber(nums)==3)
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