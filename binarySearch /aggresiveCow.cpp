/*You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.
Constraints:
2 ≤ stalls.size() ≤ 106
0 ≤ stalls[i] ≤ 108
2 ≤ k ≤ stalls.size()*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool possible(vector<int> &stalls, int k, int dist) {
        int count = 1; 
        int lastposition = stalls[0];
        
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastposition >= dist) {
                lastposition = stalls[i];
                count++;
            }
            if (count >= k) return true; 
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end()); 

        int st = 1; 
        
        int end = stalls[n - 1] - stalls[0]; 
        int ans = 0;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            
            if (possible(stalls, k, mid)) {
                ans = mid;
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> stalls1 = {1, 2, 4, 8, 9};
    int k1 = 3;
    cout << "Test Case 1: " << sol.aggressiveCows(stalls1, k1) << " (Expected: 3)" << endl;
    
    // Test Case 2
    vector<int> stalls2 = {10, 1, 2, 7, 5};
    int k2 = 3;
    cout << "Test Case 2: " << sol.aggressiveCows(stalls2, k2) << " (Expected: 4)" << endl;
    
    // Test Case 3
    vector<int> stalls3 = {2, 12, 11, 3, 26, 7};
    int k3 = 5;
    cout << "Test Case 3: " << sol.aggressiveCows(stalls3, k3) << " (Expected: 1)" << endl;
    
    return 0;
}
