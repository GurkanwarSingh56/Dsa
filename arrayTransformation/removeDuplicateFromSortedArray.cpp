#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   int removeDuplicates(vector<int>& nums) {
    int j=1;
    for (int i = 1; i < nums.size(); i++)
    {
       if (nums[i]!=nums[i-1])
       {
       nums[j]=nums[i];
       j++;
       }  
    }
    return j;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {1,1,2};

        if(s1.removeDuplicates(nums)==2)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

        if(s1.removeDuplicates(nums)==5)
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