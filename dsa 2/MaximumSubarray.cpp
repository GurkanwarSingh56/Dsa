/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumSubarry(vector<int>& nums) {
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0; i < nums.size(); i++) {
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0) {
               sum=0;
            }
        }

        return maxSum;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

        if(s1.maximumSubarry(nums)==6)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {5,4,-1,7,8};

        if(s1.maximumSubarry(nums)==23)
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