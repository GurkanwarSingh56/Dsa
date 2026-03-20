/*Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
// order 2n
    int getSecondLargest(vector<int> &arr) {
        // Initialize largest and second largest
        int largest = arr[0];
        int secondLargest = -1;

        // First pass: find the largest element
        for (int i = 0; i < arr.size(); i++) {
            if (largest < arr[i]) {
                largest = arr[i];
            }
        }

        // Second pass: find the second largest element
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
     // (O(n)) ✅ Optimal
    int getSecondLargest_OnePass(vector<int> &arr) {
        int largest = arr[0];
        int secondLargest = -1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            }
            else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return secondLargest;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution s;
    cout << "TwoPass: " << s.getSecondLargest(arr) << "\n";
    cout << "OnePass: " << s.getSecondLargest_OnePass(arr) << "\n";
    return 0;
}