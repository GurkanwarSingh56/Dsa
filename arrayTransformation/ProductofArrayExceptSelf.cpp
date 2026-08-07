#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int prefix =1;
       int suffix=1;
       vector<int> result(nums.size(),1);
       for(int i=0;i<nums.size()-1;i++){
        prefix *=nums[i];
        result[i+1]=prefix;
       }
       for (int i = nums.size()-1; i >0; i--)
       {
        suffix*=nums[i];
        result[i-1]*=suffix;
       }
       
        return result;
    }
};
class Test {
public:
    void test1() {
        Solution s1;
        vector<int>nums = {1,2,3,4};

        nums = s1.productExceptSelf(nums); 

        
        if (nums == vector<int>{24,12,8,6})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }


    void test2() {
         Solution s1;
       vector<int>nums = {-1,1,0,-3,3};

        nums = s1.productExceptSelf(nums); 

        
        if (nums == vector<int>{0,0,9,0,0})
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