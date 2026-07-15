#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> result;

        for (int x : nums)
            mp[x]++;

        for (auto &it : mp)
        {
            if (it.second > nums.size()/3)
                result.push_back(it.first);
        }

        return result;
    }
};

class Test {
public:
    void test1() {
        Solution s;
        vector<int> nums = {3,2,3};

        if (s.majorityElement(nums) == vector<int>{3})
            cout << "Test 1 Passed\n";
        else
            cout << "Test 1 Failed\n";
    }

    void test2() {
        Solution s;
        vector<int> nums = {1,2};

        vector<int> ans = s.majorityElement(nums);

        if (ans == vector<int>{1,2} || ans == vector<int>{2,1})
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