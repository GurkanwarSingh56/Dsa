#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        vector<int> ret;
      for (int i = 0; i < nums.size(); i++)
      {
       result[nums[i]-1]=nums[i];
      }
      for (int i = 0; i < nums.size(); i++)
      {
        if (result[i]==0)
        {
            ret.push_back(i+1);
        } 
      }
      return ret;
    }
};

class Test {
public:
    void test1() {
        Solution s;
        vector<int> nums = {4,3,2,7,8,2,3,1};

        if (s.findDisappearedNumbers(nums) == vector<int>{5,6})
            cout << "Test 1 Passed\n";
        else
            cout << "Test 1 Failed\n";
    }

    void test2() {
        Solution s;
        vector<int> nums = {1,1};

        vector<int> ans = s.findDisappearedNumbers(nums);

        if (ans == vector<int>{2})
            cout << "Test 2 Passed\n";
        else
            cout << "Test 2 Failed\n";
    }
};

int main() {
    Test t;
    t.test1();
    t.test2();
}