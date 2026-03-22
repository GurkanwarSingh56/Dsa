/*Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
Example 2:

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
Example 3:

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Can you find an O(n) solution?*/
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	
	int thirdMax(vector<int>& nums) {
		long long first = LLONG_MIN;
		long long second = LLONG_MIN;
		long long third = LLONG_MIN;

		for (int num : nums) {
			long long x = num;

			if (x == first || x == second || x == third) {
				continue;
			}

			if (x > first) {
				third = second;
				second = first;
				first = x;
			} else if (x > second) {
				third = second;
				second = x;
			} else if (x > third) {
				third = x;
			}
		}

		return (third == LLONG_MIN) ? static_cast<int>(first) : static_cast<int>(third);
	}
};

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	Solution s;
	cout << s.thirdMax(nums) << "\n";
	return 0;
}
