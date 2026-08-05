#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
class Test {
public:
    void test1() {
        Solution s1;
        vector<int>nums = {-4,-1,0,3,10};

        nums = s1.sortedSquares(nums); 

        
        if (nums == vector<int>{0,1,9,16,100})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }


    void test2() {
         Solution s1;
       vector<int>nums = {-7,-3,2,3,11};

        nums = s1.sortedSquares(nums); 

        
        if (nums == vector<int>{4,9,9,49,121})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }

};

int main() {
    Test t;
    t.test1();
    t.test2();
    
    return 0;
}