#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>>ans;  
        sort(arr.begin(),arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
           if(ans.empty()||ans.back()[1]<arr[i][0]){
           ans.push_back(arr[i]);
           }
           else {
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
           }
        }
        
        return ans; 
    }

    
};

class Test {
public:
    void test1() {
        Solution s1;
        vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

        arr = s1.merge(arr); 

        
        if (arr == vector<vector<int>>{{1,6},{8,10},{15,18}})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }


    void test2() {
         Solution s1;
        vector<vector<int>> arr = {{1,4},{4,5}};

        arr = s1.merge(arr); 

        
        if (arr == vector<vector<int>>{{1,5}})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
    }

void test3() {
         Solution s1;
        vector<vector<int>> arr = {{4,7},{1,4}};

        arr = s1.merge(arr); 

        
        if (arr == vector<vector<int>>{{1,7}})
            cout << "Test case 1 passed\n";
        else
            cout << "Test case 1 failed\n";
}
};

int main() {
    Test t;
    t.test1();
    t.test2();
    
    return 0;
}