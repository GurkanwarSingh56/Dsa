//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

class Test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {1,2,3,4,5,6,7};

        s1.rotate(nums, 3);

        if (nums == vector<int>{5,6,7,1,2,3,4})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {-1,-100,3,99};

        s1.rotate(nums, 2);

        if (nums == vector<int>{3,99,-1,-100})
            cout << "Test case 2 passed\n";
        else
            cout << "Test case 2 failed\n";
    }
};

int main() {
    Test t;
    t.test1();
    t.test2();
}