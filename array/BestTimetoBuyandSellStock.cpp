#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {

           
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            }

           
            int profit = prices[i] - minPrice;

            
            if(profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    int result = s.maxProfit(prices);
    int expected = 5;
    if(result == expected){
        cout << "Test case passed!" << endl;
    } else {
        cout << "Test case failed!" << endl;
    }
    cout << endl;
}