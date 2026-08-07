#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};
class Test {
public:
    void test1() {
        Solution s1;
        vector<int> nums = {2,0,2,1,1,0};

        s1.sortColors(nums);

        if (nums == vector<int>{0,0,1,1,2,2})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }


    void test2() {
        Solution s1;
        vector<int> nums = {2,0,1};

        s1.sortColors(nums);

        if (nums == vector<int>{0,1,2})
            cout << "Test case 2 passed\n";
        else
            cout << "Test case 2 failed\n";
    }

};

int main() {
    Test t;
    t.test1();
    t.test2();
    
    return 0;
}