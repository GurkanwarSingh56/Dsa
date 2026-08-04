/*Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]*/
#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool degreeOfArray(vector<int>& nums) {
       unordered_set<int>s(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i++){
        if (s.find(nums[i]*2)!=s.end()&&nums[i]!=nums[i]*2)
        {
            return true;
        }
        else if(s.find(nums[i]/2)!=s.end()&&nums[i]%2==0&&nums[i]/2!=nums[i]){
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
        vector<int> nums = {10,2,5,3};

        if(s1.degreeOfArray(nums))
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {3,1,7,11};

        if(!s1.degreeOfArray(nums))
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