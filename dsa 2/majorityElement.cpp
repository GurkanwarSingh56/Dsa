#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++)
    {
       map[nums[i]]++;
            if (map[nums[i]]>nums.size()/2)
            {
                return nums[i];
            }    
    }
    return -1;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {3,2,3};

        if(s1.majorityElement(nums)==3)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {2,2,1,1,1,2,2};

        if(s1.majorityElement(nums)==2)
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