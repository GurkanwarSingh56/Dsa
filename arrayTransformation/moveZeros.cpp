#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
        int j=0;
       for (int i = 0; i < nums.size(); i++)
       {
        if (nums[i]!=0)
        {
           swap(nums[i],nums[j]);
           j++;
        }
        
       }
       return nums;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {0,1,0,3,12};

        if(s1.moveZeroes(nums)==vector<int>{1,3,12,0,0})
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {0};

        if(s1.moveZeroes(nums)==vector<int>{0})
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