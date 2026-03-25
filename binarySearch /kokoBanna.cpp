/*
Koko loves to eat bananas. There are n piles of bananas, the i-th pile has piles[i] bananas.
The guards are gone for h hours.

Koko can decide her bananas-per-hour eating speed k.
Each hour, she chooses one pile and eats up to k bananas from that pile.
If the pile has less than k bananas, she eats all of them and does not eat from another pile that hour.

Return the minimum integer k such that she can eat all bananas within h hours.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int timeFunc(int mid, vector<int>& piles){
        long long sum = 0;  // safer
        for(int i = 0; i < piles.size(); i++){
            sum += (piles[i] + mid - 1) / mid;
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int high = *max_element(piles.begin(), piles.end());
        int low = 1;
        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2; 

            int time = timeFunc(mid, piles);

            if(time <= h){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cin >> h;

    Solution solution;
    int ans = solution.minEatingSpeed(piles, h);

    cout << ans << "\n";
    return 0;
}