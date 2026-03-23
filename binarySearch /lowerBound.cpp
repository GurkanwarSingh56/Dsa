// Lower Bound implementation with runnable main function.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        int ans = arr.size(); 

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(arr[mid] >= target) {
                ans = mid;        
                right = mid - 1;  
            } else {
                left = mid + 1;   
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    Solution solution;
    int index = solution.lowerBound(arr, target);

    cout << index << "\n";
    return 0;
}