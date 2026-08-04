/*Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int leftSum=0,rightSum=0,totalSum=0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        totalSum+=nums[i];
      }
      for (int i = 0; i < nums.size(); i++)
      {
        rightSum=totalSum-nums[i]-leftSum;
         if (rightSum==leftSum)
       {
        return i;
       }
       leftSum+=nums[i];
      }
      return -1;
    }
};

class test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {1,7,3,6,5,6};

        if(s1.pivotIndex(nums)==3)
            cout << "test case 1 passed\n";
        else
            cout << "test case 1 failed\n";
    }

    void test2() {
        Solution s1;
        vector<int> nums = {2,1,-1};

        if(s1.pivotIndex(nums)==0)
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