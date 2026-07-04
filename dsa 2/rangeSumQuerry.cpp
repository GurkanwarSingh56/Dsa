/* Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
  */
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

class Test {
public:
    void check(int actual, int expected, string testName) {
        cout << testName << " : ";

        if (actual == expected)
            cout << "Passed";
        else
            cout << "Failed";

        cout << " (Expected = " << expected
             << ", Actual = " << actual << ")" << endl;
    }

    void runTests() {
        vector<int> nums = {2, 4, 6, 8, 10};

        NumArray obj(nums);

        cout << "Original Array: ";
        for (int x : nums)
            cout << x << " ";

        cout << "\n\nPrefix Array: ";
        for (int x : obj.prefix)
            cout << x << " ";

        cout << "\n\n----- Test Cases -----\n";

        check(obj.sumRange(0, 2), 12, "Test Case 1");
        check(obj.sumRange(1, 3), 18, "Test Case 2");
        check(obj.sumRange(2, 4), 24, "Test Case 3");
        check(obj.sumRange(0, 4), 30, "Test Case 4");

        // Fixed expected value for Test Case 5
        check(obj.sumRange(1, 2), 10, "Test Case 5");
    }
};

int main() {
    Test t;
    t.runTests();

    return 0;
}